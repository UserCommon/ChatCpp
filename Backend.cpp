#include "Backend.hpp"
#include "include/socket/TCPSocket.hpp"
#include "include/user/User.hpp"
#include <algorithm>
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
#define MAX_USERS 256

struct UserHash {
    std::size_t operator()(const User &u) const {
        return std::hash<std::string>()(u.getNickname());
    }
};

struct UserEqual {
    bool operator()(const User &u1, const User &u2) const {
        return u1.getNickname() == u2.getNickname();
    }
};

Backend::Backend(const std::string &addr, int port) {
    this->m_socket = TCPServer();
    this->m_socket.bind(addr, port);
    // this->m_rooms = std::vector<Room>();
    std::unordered_map<std::string, ClientData> m_usermap;
}

void Backend::start(const std::string &addr, int port) {
    std::cout << "Starting backend..." << std::endl;
    Backend instance = Backend(addr, port);

    instance.m_socket.listen(MAX_USERS);
    std::cout << "Started successfully!" << std::endl;
    std::cout << instance.m_socket.socket_fd << std::endl;
    while (true) {
        // Here is threadPool needed!
        std::thread([&]() {
            try {
                ClientData data = instance.m_socket.accept();
                if (!data.isValid()) {
                    // std::cerr << "Can't accept user: " << data.new_socket
                    //           << std::endl;
                } else {
                    std::cout << "Got client!" << std::endl;

                    Message m("server", "Enter your nick name:");
                    m.writeTo(data.new_socket);
                    Message got = Message::readFrom(
                        data.new_socket); // Message should exists but there it
                                          // cant? Client! Use emptyness
                    // TODO: Validate step
                    std::cout << "New user: " << got.getMessage() << std::endl;
                    User user = User(got.getMessage());
                    instance.addUser(user, data);
                    std::cout.flush();

                    while (true) { // make async without loop?
                        // Get user!
                        Message got = Message::readFrom(data.new_socket);
                        std::cout << "Message from " << got.getSender() << " | "
                                  << got.getMessage() << std::endl;
                        std::cout.flush();

                        instance.handleMessage(got, User(got.getSender()),
                                               data); // this what we can throw
                                                      // to our ThreadPool
                    }
                }
            } catch (std::out_of_range) {
            }
        }).detach();
    }
}

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
        // Command
        std::vector<std::string> command_vector = ssplitString(str_msg);
        // if (command_vector[0] == "/createRoom") {
        //     addRoom(Room(command_vector[1]));
        // } else if (command_vector[0] == "/enterRoom") {
        //     enterRoom(command_vector[1], user);
        // }
        const char *s = command_vector[0].c_str();
        for (int i = 0; i < std::strlen(s); i++) {
            std::cout << ((int)s[i]) << " ";
        }
        std::cout << std::endl;
        if (std::strcmp(command_vector[0].c_str(), "/test") == 0) {
            Message("server", "Hello, " + user.getNickname())
                .writeTo(data.new_socket);
        } else {
            Message("server", "Unknown command: " + msg.getMessage())
                .writeTo(data.new_socket);
        }
    } else {
        for (const auto &user_loop : m_usermap)
            Message(user.getNickname() + ": ", msg.getMessage())
                .writeTo(user_loop.second.new_socket);
        std::cout << "Got message: " << user.getNickname() << ": "
                  << msg.getMessage() << std::endl;
    }
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
