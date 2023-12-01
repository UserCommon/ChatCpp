#ifndef SOCKETINIT
#define SOCKETINIT

#include "Package.hpp"
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

class TCPSocket {
  public:
    TCPSocket(uint32_t standard_pkg_size);
    bool connect(const std::string &address, int port);
    void send(Package<std::string> &&);
    Package<std::string> receive();
    void close();

    uint32_t standard_pkg_size;
    ~TCPSocket();

  private:
    int socket_fd;
    struct sockaddr_in server;
};

#endif
