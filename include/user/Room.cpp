#include "Room.hpp"

Room::Room(std::string name) {
    this->name = name;
    this->m_users = std::vector<User>();
    this->m_messages = std::vector<Message>();
}

void Room::addUser(User user) {
    std::lock_guard<std::mutex> lock(m_mutex);
    this->m_users.push_back(user);
}

void Room::addMessage(Message msg) {
    std::lock_guard<std::mutex> lock(m_mutex);
    this->m_messages.push_back(msg);
}

std::vector<Message> Room::getMessages() { return m_messages; }

std::vector<User> Room::getUsers() { return m_users; }
