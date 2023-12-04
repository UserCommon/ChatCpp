#include "TCPSocket.hpp"
#include "Message.hpp"
#include <arpa/inet.h>
#include <sys/socket.h>

ClientData::ClientData(int new_socket, sockaddr addr, socklen_t len)
    : new_socket(new_socket), address(addr), len(len) {}

TCPSocket::TCPSocket() : socket_fd(-1) {}

bool TCPSocket::connect(const std::string &address, int port) {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return false;
    }

    server.sin_addr.s_addr = inet_addr(address.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (::connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return false;
    }
    return true;
}

void TCPSocket::sendMessage(Message m) { m.writeTo(socket_fd); }
Message TCPSocket::recvMessage() { return Message::readFrom(socket_fd); }

void TCPServer::bind(const std::string &adress, int port) {
    sockaddr_in serv_addr, client_addr;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(adress.c_str());

    if (::bind(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        std::cerr << "Failed, can't bind!" << std::endl;
        std::exit(-320);
    }
}

ClientData TCPServer::accept() {
    int new_fd;
    socklen_t addr_len;
    sockaddr addr;
    new_fd = ::accept(socket_fd, (sockaddr *)&addr, &addr_len);
    return ClientData(new_fd, addr, addr_len);
}

bool ClientData::isValid() { return (new_socket < 0) ? false : true; }

void TCPServer::listen(int max_users) { ::listen(socket_fd, max_users); }

void TCPSocket::send(const void *buf, size_t len) {
    ::send(socket_fd, buf, len, 0);
}

void TCPSocket::receive(void *buf, size_t len) {
    ::recv(socket_fd, buf, len, 0);
}

void TCPSocket::close() {
    ::close(socket_fd);
    socket_fd = -1;
}

TCPSocket::~TCPSocket() {
    if (socket_fd != -1) {
        close();
    }
}
