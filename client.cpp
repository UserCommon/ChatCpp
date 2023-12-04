#include "lib/socket/Message.hpp"
#include "lib/socket/TCPSocket.hpp"
#include "lib/user/User.hpp"
#include <iostream>

Message inputMessage(const std::string &nickname) {
    std::string msg;
    std::cin >> msg;
    return Message(msg, nickname);
}

int main() {
    TCPSocket client;
    client.connect("127.0.0.1", 8080);
    std::cout << "Enter nickname!" << std::endl;
    Message init = inputMessage("Unauthorized");
    User user = User(init.getData());

    while (true) {
        Message input = inputMessage(user.getNickname());
        client.sendMessage(input);
        Message response = client.recvMessage();
        std::cout << response.getSender() << " " << response.getData()
                  << std::endl;
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
