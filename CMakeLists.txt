cmake_minimum_required(VERSION 3.3)
project(
  ChatCpp
  VERSION 0.0.0
  LANGUAGES CXX)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)

file(GLOB_RECURSE SOURCES "lib/*.cpp")
file(GLOB_RECURSE HEADERS "lib/*.hpp")
add_library(lib ${SOURCES} ${HEADERS})

add_executable(server server.cpp)
add_executable(client client.cpp)

target_link_libraries(server lib)
target_link_libraries(client lib)
