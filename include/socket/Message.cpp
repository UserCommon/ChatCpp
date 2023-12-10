#include "Message.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <unistd.h>
#include <vector>

std::string Message::getSender() { return this->m_sender; }

Message::Message(std::string sender, std::string message)
    : Message::Message(sender, message,
                       static_cast<int>(sender.length() + message.length())){};

Message::Message(std::string sender, std::string message, int size)
    : m_message(message), size(size + 1), m_sender(sender) {}

void splitString(const std::string &input, std::string &firstPart,
                 std::string &secondPart) {
    size_t pos = input.find(' ');
    if (pos != std::string::npos) {
        firstPart = input.substr(0, pos);
        secondPart = input.substr(pos + 1);
    } else {
        firstPart = input;
        secondPart = "";
    }
}

Message Message::readFrom(int fd) {
    std::string data;
    int length = 0;

    if (::read(fd, &length, sizeof(length)) <= 0) {
        std::cerr << "failed to read length" << std::endl;
    }
    char buff[length];
    for (int i = 0; i < length; i++) {
        buff[i] = 'A';
    }
    ::read(fd, &buff, length);

    std::string str(buff, length);
    std::string one, two;
    splitString(str, one, two);
    return Message(one, two); // BUG
}

void Message::writeTo(int fd) {
    std::string response = m_sender + " " + m_message;
    int size_n = std::strlen(response.c_str()) + 1;

    ::write(fd, &(size_n), sizeof(size_n));
    ::write(fd, response.c_str(), size_n);
}

int Message::getSize() { return size; }
std::string Message::getMessage() { return m_message; }
