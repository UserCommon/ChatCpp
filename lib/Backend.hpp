#ifndef BACKEND_H
#define BACKEND_H
#include "socket/Message.hpp"
#include "socket/TCPSocket.hpp"
#include "user/Room.hpp"
#include <set>

// Предоставляет Handler'ы удобные...
class Backend {
  public:
    Backend(const std::string &addr, int port); // Create instance
    static void start(const std::string &addr,
                      int port); // Start socket and other stuff
    void addRoom(Room room);
    void enterRoom(const std::string &room, User user);
    void removeRoom(const std::string &room);
    void addUser(User user);
    void stop();
    void handleMessage(Message msg, User user, ClientData data);

  private:
    std::vector<Room> m_rooms;
    std::set<User> m_users;
    TCPServer m_socket;
};

#endif // !BACKENG_H
