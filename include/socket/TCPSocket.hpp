#ifndef SOCKETINIT
#define SOCKETINIT

#include "Message.hpp"
#include "Package.hpp"
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

class ClientData {
  public:
    ClientData() = default;
    ClientData(int new_socket, sockaddr address, socklen_t len);
    int new_socket;
    sockaddr address;
    socklen_t len;
    bool isValid();
};

class TCPSocket {
  public:
    TCPSocket();
    bool connect(const std::string &address, int port);
    void send(const void *buf, size_t len);
    void sendMessage(Message m);
    Message recvMessage();
    void receive(void *buf, size_t len);
    void close();

    uint32_t standard_pkg_size;
    ~TCPSocket();

    int socket_fd;

  protected:
    struct sockaddr_in server;
};

class TCPServer : public TCPSocket {
  public:
    TCPServer() : TCPSocket(){};
    ClientData accept(); // int is fd
    void bind(const std::string &address, int port);
    void listen(int max_users);
};

#endif
