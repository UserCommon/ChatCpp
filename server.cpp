#include "Backend.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 2) {
        Backend::start("127.0.0.1", std::stoi(argv[1]));
    } else {
        Backend::start("127.0.0.1", 8082);
    }
    return 0;
}
