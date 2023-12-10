cmake_minimum_required(VERSION 3.3)

# Create a library from the source files in the "lib" folder
file(GLOB_RECURSE LIB_SOURCES "*.cpp")
file(GLOB_RECURSE LIB_HEADERS "*.hpp")
add_library(include ${LIB_SOURCES} ${LIB_HEADERS})

# Set the C++ standard
set_property(TARGET include PROPERTY CXX_STANDARD 20)
