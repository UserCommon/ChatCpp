#include "include/socket/Message.hpp"
#include "include/socket/TCPSocket.hpp"
#include "include/user/User.hpp"
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>
#include <string>
#include <thread>
using Client = TCPSocket;

Message inputMessage(const std::string &nickname) {
    std::string msg;
    std::getline(std::cin, msg);
    std::cout.flush();

    // std::cout << msg << std::endl;
    return Message(nickname, msg);
}

void sendMessageAsync(const std::string &userName, Client &client) {
    while (true) {
        auto start = std::chrono::steady_clock::now(); // Record the start time
        Message msg = inputMessage(userName);
        client.sendMessage(msg);
        auto end = std::chrono::steady_clock::now(); // Record the end time
        std::chrono::duration<double> elapsed_seconds =
            end - start; // Calculate the elapsed time
        if (elapsed_seconds <
            std::chrono::milliseconds(
                100)) { // Limit the rate to 10 messages per second
            std::this_thread::sleep_for(
                std::chrono::milliseconds(100) -
                elapsed_seconds); // Wait to maintain the rate
        }
    }
}

void receiveMessageAsync(Client &client) {
    while (true) {
        Message response = client.recvMessage();
        std::cout << response.getSender() << " " << response.getMessage()
                  << std::endl;
        std::cout.flush();
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Need to have hostname and port" << std::endl;
        exit(-100);
    }
    TCPSocket client;
    client.connect(argv[1], std::stoi(argv[2]));
    Message hello = client.recvMessage();
    std::cout << hello.getSender() << ": " << hello.getMessage() << std::endl;

    Message init = inputMessage("Unauthorized");
    User user = User(init.getMessage());
    init.writeTo(client.socket_fd);
    std::cout << "Welcome"
              << " " << user.getNickname() << std::endl;
    auto sendFuture = std::async(std::launch::async, [&]() {
        while (true) {
            Message msg = inputMessage(user.getNickname());
            client.sendMessage(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });

    auto receiveFuture = std::async(std::launch::async, [&]() {
        while (true) {
            Message response = client.recvMessage();
            std::cout << response.getSender() << " " << response.getMessage()
                      << std::endl;
            std::cout.flush();
        }
    });
    // std::chrono::milliseconds timeout(50);
    // Message msg = inputMessage(user.getNickname());
    // client.sendMessage(msg);
    // std::future<Message> future =
    //     std::async([&]() { return inputMessage(user.getNickname());
    //     });
    // if (future.wait_for(timeout) == std::future_status::ready) {
    //     client.sendMessage(future.get());
    // }
    // Message response = client.recvMessage();
    // std::cout << response.getSender() << " " << response.getMessage()
    //           << std::endl;

    sendFuture.get();
    receiveFuture.get();
    std::cout.flush();
    std::cout << "Bye!" << std::endl;
    return 0;
}
