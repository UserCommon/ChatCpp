#include "include/socket/Message.hpp"
#include "include/socket/TCPSocket.hpp"
#include "include/user/User.hpp"
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <future>
#include <iostream>
#include <string>
#include <thread>
using Client = TCPSocket;

Message inputMessage(const std::string &nickname) {
    std::string msg;
    std::getline(std::cin, msg);
    std::cout.flush();

    // std::cout << msg << std::endl;
    return Message(nickname, msg);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Need to have hostname and port" << std::endl;
        exit(-100);
    }
    TCPSocket client;
    client.connect(argv[1], std::stoi(argv[2]));
    Message hello = client.recvMessage();
    std::cout << hello.getSender() << ": " << hello.getMessage() << std::endl;

    Message init = inputMessage("Unauthorized");
    User user = User(init.getMessage());
    init.writeTo(client.socket_fd);
    std::cout << "Welcome"
              << " " << user.getNickname() << std::endl;
    auto sendFuture = std::async(std::launch::async, [&]() {
        while (true) {
            Message msg = inputMessage(user.getNickname());
            client.sendMessage(msg);
            if (std::strcmp(msg.getMessage().c_str(), "/exit") == 0) {
                exit(0);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });

    auto receiveFuture = std::async(std::launch::async, [&]() {
        while (true) {
            Message response = client.recvMessage();
            if (response.isValid()) {

                // if ((std::strcmp(response.getSender().c_str(), "server") ==
                //      0) &&
                //     (std::strcmp(response.getSender().c_str(), "exit") == 0))
                //     { break;
                // }
                std::cout << response.getSender() << ": "
                          << response.getMessage() << std::endl;
                std::cout.flush();
            }
        }
    });
    // std::chrono::milliseconds timeout(50);
    // Message msg = inputMessage(user.getNickname());
    // client.sendMessage(msg);
    // std::future<Message> future =
    //     std::async([&]() { return inputMessage(user.getNickname());
    //     });
    // if (future.wait_for(timeout) == std::future_status::ready) {
    //     client.sendMessage(future.get());
    // }
    // Message response = client.recvMessage();
    // std::cout << response.getSender() << " " << response.getMessage()
    //           << std::endl;

    sendFuture.get();
    receiveFuture.get();
    std::cout.flush();
    std::cout << "Bye!" << std::endl;
    return 0;
}
