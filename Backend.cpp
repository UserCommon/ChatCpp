#include "Backend.hpp"
#include "csignal"
#include "include/socket/TCPSocket.hpp"
#include "include/thread_pool/ThreadPool.hpp"
#include "include/user/User.hpp"
#include <algorithm>
#define threads_c 2

#include <atomic>
#include <cstring>
#include <format>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unordered_map>
#include <variant>
#define MAX_USERS 10

struct UserHash {
    std::size_t operator()(const User &u) const {
        return std::hash<std::string>()(u.getNickname());
    }
};

bool NicknameEquality::operator()(const std::string &u1,
                                  const std::string &u2) const {
    return (std::strcmp(u1.c_str(), u2.c_str()) == 0);
}

Backend::Backend(const std::string &addr, int port) {
    this->m_socket = TCPServer();
    this->m_socket.bind(addr, port);
    // this->m_rooms = std::vector<Room>();
    std::unordered_map<std::string, ClientData> m_usermap;
}

void Backend::start(const std::string &addr, int port) {
    std::atomic<int> a;
    ThreadPool pool;
    pool.Start();

    std::cout << "Starting backend..." << std::endl;
    Backend instance = Backend(addr, port);

    instance.m_socket.listen(MAX_USERS);
    std::cout << "Started successfully!" << std::endl;
    std::cout << instance.m_socket.socket_fd << std::endl;
    while (true) {
        if (a < threads_c) {
            a++;
            // Here is threadPool needed!
            pool.QueueJob([&]() {
                try {
                    ClientData data = instance.m_socket.accept();
                    if (!data.isValid()) {
                        return;
                    } else {
                        std::cout << "Got client!" << std::endl;

                        Message m("server", "Enter your nick name:");
                        m.writeTo(data.new_socket);
                        Message got = Message::readFrom(
                            data.new_socket); // Message should exists but there
                                              // it cant? Client! Use emptyness
                        if (std::strcmp(got.getSender().c_str(), "server") ==
                                0 &&
                            std::strcmp(got.getMessage().c_str(),
                                        "disconnection_error") == 0) {
                            return;
                        }
                        // TODO: Validate step
                        User user = User(got.getMessage());
                        instance.addUser(user, data);
                        instance.printMap();
                        std::cout << instance.getUserSocket(user.getNickname())
                                  << std::endl;
                        bool connected = true;

                        while (connected) { // make async without loop?
                            // Get user!
                            Message got = Message::readFrom(data.new_socket);
                            if (std::strcmp(got.getSender().c_str(),
                                            "server") == 0 &&
                                std::strcmp(got.getMessage().c_str(),
                                            "disconnection_error") == 0) {
                                return;
                            }
                            std::cout << "Message from " << got.getSender()
                                      << " | " << got.getMessage() << std::endl;
                            std::cout.flush();

                            instance.handleMessage(
                                got, User(got.getSender()),
                                data); // this what we can throw
                                       // to our ThreadPool
                        }
                        a--;
                        std::cout << a << std::endl;
                        std::cout.flush();
                    }
                } catch (std::out_of_range) {
                    std::cout << "OUT OF RANGE" << std::endl;
                }
            });
        }
    }
    pool.Stop();
}

// Отправлять всем пользователям кроме себя

std::vector<std::string> ssplitString(const std::string &input) {
    std::vector<std::string> result;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}

void Backend::handleMessage(Message msg, User user, ClientData data) {
    std::string str_msg = msg.getMessage();
    if (str_msg.at(0) == '/') {
        std::vector<std::string> command_vector = ssplitString(str_msg);

        std::cout << std::endl;
        if (std::strcmp(command_vector[0].c_str(), "/test") == 0) {
            Message("server", "Hello, " + user.getNickname())
                .writeTo(data.new_socket);
        } else if (std::strcmp(command_vector[0].c_str(), "/tell") == 0) {
            if (command_vector.size() >= 3) {
                std::stringstream s;
                for (int i = 2; i < command_vector.size(); i++) {
                    s << command_vector[i] << " ";
                }
                Message m(user.getNickname(), s.str());
                m.writeTo(getUserSocket(command_vector[1]));
                std::cout << m.getSender() << " | " << m.getMessage()
                          << std::endl;
                std::cout.flush();
            } else {
                Message("server", "Illegal command argument! /tell has only 2 "
                                  "arguments 1: reciever 2: Message itself")
                    .writeTo(data.new_socket);
            }

        } else {
            Message("server", "Unknown command: " + msg.getMessage())
                .writeTo(data.new_socket);
        }

        std::cout << "debug parser" << std::endl;
        for (int i = 0; i < command_vector.size(); i++) {
            std::cout << i << ": " << command_vector[i] << " | ";
        }
        std::cout << std::endl;
    } else {
        if ((std::strcmp(msg.getSender().c_str(), "server") == 0) &&
            (std::strcmp(msg.getMessage().c_str(), "disconnection_error") ==
             0)) {
            return;
        }

        for (const auto &user_loop : m_usermap) {
            if (user_loop.second.new_socket !=
                data.new_socket) { // Fixed, Probably buggy
                Message(user.getNickname(), msg.getMessage())
                    .writeTo(user_loop.second.new_socket);
            }
        }
        std::cout << "Got message: " << user.getNickname() << ": "
                  << msg.getMessage() << std::endl;
    }
}

int Backend::getUserSocket(const std::string &name) {
    printMap();
    std::lock_guard<std::mutex> guard(m_mutex);

    // for (const auto &user_loop : m_usermap) {
    //     if (std::strcmp(user_loop.first.c_str(), name.c_str()) == 0) {
    //         std::cout << "HEY" << std::endl;
    //         return user_loop.second.new_socket;
    //     }
    // }
    return m_usermap.at(name).new_socket;
}

void Backend::printMap() {
    std::lock_guard<std::mutex> guard(m_mutex);
    for (const auto &user_loop : m_usermap) {
        std::cout << "User: " << user_loop.first
                  << " Socket: " << user_loop.second.new_socket << std::endl;
    }
    std::cout.flush();
}

void Backend::addUser(const User &user, ClientData data) {
    std::lock_guard<std::mutex> guard(m_mutex);

    m_usermap.insert({user.getNickname(), data});
}

void Backend::removeUser(const User &user) {
    std::lock_guard<std::mutex> guard(m_mutex);

    m_usermap.erase(user.getNickname());
}

// Probably buggy!
// void Backend::addRoom(Room room) { m_rooms.push_back(room); }
// void Backend::enterRoom(const std::string &room, User user) {
//     auto it = std::find(m_rooms.begin(), m_rooms.end(), room);
//     if (it != m_rooms.end()) {
//         it->addUser(user);
//     }
// }
//
// void Backend::removeRoom(const std::string &room) {
//     auto itr = std::find(m_rooms.begin(), m_rooms.end(), room);
//     if (itr != m_rooms.end())
//         m_rooms.erase(itr);
// }

void Backend::stop() {
    std::cout << "Backend is stoppin..." << std::endl;

    // m_socket.close();
    // for (auto it = m_rooms.begin(); it != m_rooms.end(); it++) {
    //     it = m_rooms.erase(it);
    // }
    std::cout << "Backend stopped successfully" << std::endl;
}
