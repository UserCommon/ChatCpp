#ifndef MESSAGE_H
#define MESSAGE_H
#include <cstdint>
#include <string>

class Message {
  public:
    Message(std::string sender, std::string message);
    Message(std::string sender, std::string message, int size);
    std::string getSender();
    int getSize();
    std::string getMessage();
    void writeTo(int fd);
    static Message readFrom(int fd);

    int size;

  private:
    std::string m_message;
    std::string m_sender;
};

#endif
