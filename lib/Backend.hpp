#ifndef BACKEND_H
#define BACKEND_H
#include "socket/Message.hpp"
#include "socket/TCPSocket.hpp"
#include "user/Room.hpp"
#include <set>

// Предоставляет Handler'ы удобные...
class Backend {
  public:
    Backend();           // Create instance
    static void start(); // Start socket and other stuff
    void addRoom(Room room);
    void enterRoom(const std::string &room, User user);
    void removeRoom(const std::string &room);
    void addUser(User user);
    void stop();
    void handleMessage(Message &&msg, User &user);

  private:
    std::vector<Room> m_rooms;
    std::set<User> m_users;
    TCPServer m_socket;
};

#endif // !BACKENG_H
