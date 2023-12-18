#include "ThreadPool.hpp"

void ThreadPool::Start() {
    for (int i = 0; i < std::thread::hardware_concurrency(); i++) {
        threads.emplace_back(&ThreadPool::ThreadLoop, this);
    }
}

void ThreadPool::QueueJob(const std::function<void()> &job) {
    std::unique_lock<std::mutex> lock(queue_mutex);
    jobs.push(job);
    lock.unlock();
    mutex_condition.notify_one();
}

void ThreadPool::Stop() {
    should_terminate = true;
    mutex_condition.notify_all();
    for (auto &thread : threads) {
        thread.join();
    }
}

bool ThreadPool::busy() { return !jobs.empty(); }

void ThreadPool::ThreadLoop() {
    while (true) {
        std::unique_lock<std::mutex> lock(queue_mutex);
        mutex_condition.wait(
            lock, [this]() { return should_terminate || !jobs.empty(); });

        if (should_terminate) {
            break;
        }
        auto job = jobs.front();
        jobs.pop();
        lock.unlock();
        job();
    }
}
