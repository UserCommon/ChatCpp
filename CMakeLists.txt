cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)

project(ChatCpp VERSION 0.0.0)

add_subdirectory(include)

add_executable(server server.cpp Backend.hpp Backend.cpp)
add_executable(client client.cpp)

target_link_libraries(server include)
target_link_libraries(client include)
