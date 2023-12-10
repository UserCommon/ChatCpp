#ifndef BACKEND_H
#define BACKEND_H
#include "include/socket/Message.hpp"
#include "include/socket/TCPSocket.hpp"
#include "include/user/Room.hpp"
#include "include/user/User.hpp"
#include <mutex>
#include <unordered_map>
#include <vector>

struct NicknameEquality {
    bool operator()(const std::string &u1, const std::string &u2) const;
};
// Предоставляет Handler'ы удобные...
class Backend {
  public:
    Backend(const std::string &addr, int port); // Create instance
    static void start(const std::string &addr,
                      int port); // Start socket and other stuff
    // void addRoom(Room room);
    // void enterRoom(const std::string &room, User user);
    // void removeRoom(const std::string &room);
    void addUser(const User &user, ClientData data);
    void removeUser(const User &user);
    void stop();
    void handleMessage(Message msg, User user, ClientData data);
    void printMap();
    int getUserSocket(const std::string &name);

  private:
    // std::vector<Room> m_rooms;
    std::unordered_map<std::string, ClientData, std::hash<std::string>,
                       NicknameEquality>
        m_usermap;
    TCPServer m_socket;
    std::mutex m_mutex;
};

#endif // !BACKENG_H
