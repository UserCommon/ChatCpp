#ifndef MESSAGE_H
#define MESSAGE_H
#include "Package.hpp"
#include <cstdint>
#include <string>

class Message : public Package<std::string> {
  public:
    Message();
    Message(std::string &&sender, std::string &&message);
    Message(std::string &&sender, std::string &&message, uint32_t size);
    std::string getSender();
    void writeTo(int fd);
    static Message readFrom(int fd);

  private:
    std::string m_sender;
};

#endif
