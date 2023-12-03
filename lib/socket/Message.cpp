#include "Message.hpp"
#include "Package.hpp"
#include <cstdint>
#include <sstream>
#include <unistd.h>
#include <vector>

Message::Message() {}

Message::Message(std::string &&sender, std::string &&message)
    : Message::Message(
          std::move(sender), std::move(message),
          static_cast<uint32_t>(sender.length() + message.length() + 1)){};

Message::Message(std::string &&sender, std::string &&message, uint32_t size)
    : Package(std::move(message), size), m_sender(sender) {}

std::vector<std::string> splitString(const std::string &input) {
    std::vector<std::string> result;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}

Message Message::readFrom(int fd) {
    std::string data;
    uint32_t length;

    ::read(fd, &length, sizeof(length));
    char buff[length + 1];
    ::read(fd, &buff, length);
    buff[length] = '\0';

    std::string str(buff);
    std::vector<std::string> splitted = splitString(str);
    return Message(std::move(splitted[0]), std::move(splitted[1])); // BUG
}

void Message::writeTo(int fd) {
    ::write(fd, &size, sizeof(size));
    ::write(fd, m_sender.c_str(), sizeof(m_sender.c_str()));
    ::write(fd, " ", sizeof(" "));
    ::write(fd, m_data.c_str(), sizeof(m_data.c_str()));
}
