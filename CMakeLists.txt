cmake_minimum_required(VERSION 3.3)
project(ChatCpp)

file(GLOB_RECURSE SOURCES "class/*.cpp")
file(GLOB_RECURSE HEADERS "class/*.hpp")
add_library(lib ${SOURCES} ${HEADERS})

add_executable(server server.cpp)
add_executable(client client.cpp)

target_link_libraries(server lib)
target_link_libraries(client lib)
