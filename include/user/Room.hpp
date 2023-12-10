#ifndef ROOM_H
#define ROOM_H
#include "../socket/Message.hpp"
#include "User.hpp"
#include <mutex>
#include <vector>

class Room {
    // Everything is copy...
  public:
    std::string name;
    Room(std::string name);

    void addUser(User user);
    void addMessage(Message msg);

    std::vector<Message> getMessages();
    std::vector<User> getUsers();

  private:
    std::vector<User> m_users;
    std::vector<Message> m_messages;
    std::mutex m_mutex;
};

#endif
