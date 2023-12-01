#include "TCPSocket.hpp"
#include "Package.hpp"

TCPSocket::TCPSocket(uint32_t standard_pkg_size)
    : standard_pkg_size(standard_pkg_size), socket_fd(-1){};

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

void TCPSocket::send(Package<std::string> &&pkg) {
    ::send(socket_fd, (char *)&pkg, standard_pkg_size, 0);
}

Package<std::string> TCPSocket::receive() {
    Package<std::string> mt;
    ::recv(socket_fd, (char *)&mt, standard_pkg_size, 0);
    return mt;
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
