#include "Backend.hpp"
#include "socket/TCPSocket.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <sys/socket.h>
#define MAX_USERS 256

Backend::Backend() {
    this->m_socket = TCPServer();
    this->m_rooms = std::vector<Room>();
    this->m_users = std::set<User>();
}

void Backend::start() {
    std::cout << "Starting backend..." << std::endl;
    Backend instance;

    std::cout << "Started successfully!" << std::endl;
    instance.m_socket.listen(MAX_USERS);
    while (true) {
        // Here is threadPool needede!
        {
            ClientData data = instance.m_socket.accept();
            if (!data.isValid()) {
                std::cerr << "Can't accept user: " << data.new_socket
                          << std::endl;
            } else {
                Message m("server", "Enter your nickname!");
                m.writeTo(data.new_socket);
                Message got = Message::readFrom(
                    data.new_socket); // Message should exists but there it
                                      // cant? Client! Use emptyness
                // TODO: Validate step
                User user(got.getData());

                while (true) { // make async without loop?
                    // Get user!
                    Message got = Message::readFrom(data.new_socket);

                    instance.handleMessage(
                        std::move(got),
                        user); // this what we can throw to our ThreadPool
                }
            }
        }
    }
}

std::vector<std::string> splitString(const std::string &input) {
    std::vector<std::string> result;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}

void Backend::handleMessage(Message &&msg, User &user) {
    std::string str_msg = msg.getData();
    if (str_msg.at(0) == '/') {
        // Command
        std::vector<std::string> command_vector = splitString(str_msg);
        if (command_vector[0] == "/createRoom") {
            addRoom(Room(command_vector[1]));
        } else if (command_vector[0] == "/enterRoom") {
            enterRoom(command_vector[1], user);
        } else if (command_vector[0] == "/test") {
            Message("server", "Hello, u wrote /test!");
        }
    } else {
    }
}

void Backend::addUser(User user) { m_users.insert(user); }

// Probably buggy!
void Backend::addRoom(Room room) { m_rooms.push_back(room); }
void Backend::enterRoom(const std::string &room, User user) {
    auto it = std::find(m_rooms.begin(), m_rooms.end(), room);
    if (it != m_rooms.end()) {
        it->addUser(user);
    }
}
void Backend::removeRoom(const std::string &room) {
    auto itr = std::find(m_rooms.begin(), m_rooms.end(), room);
    if (itr != m_rooms.end())
        m_rooms.erase(itr);
}

void Backend::stop() {
    std::cout << "Backend is stoppin..." << std::endl;

    m_socket.close();
    for (auto it = m_rooms.begin(); it != m_rooms.end(); it++) {
        it = m_rooms.erase(it);
    }
    std::cout << "Backend stopped successfully" << std::endl;
}
