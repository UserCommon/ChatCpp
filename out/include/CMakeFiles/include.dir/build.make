# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/usercommon/ChatCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usercommon/ChatCpp/out

# Include any dependencies generated for this target.
include include/CMakeFiles/include.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/include.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/include.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/include.dir/flags.make

include/CMakeFiles/include.dir/command/Command.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/command/Command.cpp.o: /home/usercommon/ChatCpp/include/command/Command.cpp
include/CMakeFiles/include.dir/command/Command.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/include.dir/command/Command.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/command/Command.cpp.o -MF CMakeFiles/include.dir/command/Command.cpp.o.d -o CMakeFiles/include.dir/command/Command.cpp.o -c /home/usercommon/ChatCpp/include/command/Command.cpp

include/CMakeFiles/include.dir/command/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/command/Command.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/command/Command.cpp > CMakeFiles/include.dir/command/Command.cpp.i

include/CMakeFiles/include.dir/command/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/command/Command.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/command/Command.cpp -o CMakeFiles/include.dir/command/Command.cpp.s

include/CMakeFiles/include.dir/socket/Message.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/socket/Message.cpp.o: /home/usercommon/ChatCpp/include/socket/Message.cpp
include/CMakeFiles/include.dir/socket/Message.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object include/CMakeFiles/include.dir/socket/Message.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/socket/Message.cpp.o -MF CMakeFiles/include.dir/socket/Message.cpp.o.d -o CMakeFiles/include.dir/socket/Message.cpp.o -c /home/usercommon/ChatCpp/include/socket/Message.cpp

include/CMakeFiles/include.dir/socket/Message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/socket/Message.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/socket/Message.cpp > CMakeFiles/include.dir/socket/Message.cpp.i

include/CMakeFiles/include.dir/socket/Message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/socket/Message.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/socket/Message.cpp -o CMakeFiles/include.dir/socket/Message.cpp.s

include/CMakeFiles/include.dir/socket/Package.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/socket/Package.cpp.o: /home/usercommon/ChatCpp/include/socket/Package.cpp
include/CMakeFiles/include.dir/socket/Package.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object include/CMakeFiles/include.dir/socket/Package.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/socket/Package.cpp.o -MF CMakeFiles/include.dir/socket/Package.cpp.o.d -o CMakeFiles/include.dir/socket/Package.cpp.o -c /home/usercommon/ChatCpp/include/socket/Package.cpp

include/CMakeFiles/include.dir/socket/Package.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/socket/Package.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/socket/Package.cpp > CMakeFiles/include.dir/socket/Package.cpp.i

include/CMakeFiles/include.dir/socket/Package.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/socket/Package.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/socket/Package.cpp -o CMakeFiles/include.dir/socket/Package.cpp.s

include/CMakeFiles/include.dir/socket/TCPSocket.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/socket/TCPSocket.cpp.o: /home/usercommon/ChatCpp/include/socket/TCPSocket.cpp
include/CMakeFiles/include.dir/socket/TCPSocket.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object include/CMakeFiles/include.dir/socket/TCPSocket.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/socket/TCPSocket.cpp.o -MF CMakeFiles/include.dir/socket/TCPSocket.cpp.o.d -o CMakeFiles/include.dir/socket/TCPSocket.cpp.o -c /home/usercommon/ChatCpp/include/socket/TCPSocket.cpp

include/CMakeFiles/include.dir/socket/TCPSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/socket/TCPSocket.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/socket/TCPSocket.cpp > CMakeFiles/include.dir/socket/TCPSocket.cpp.i

include/CMakeFiles/include.dir/socket/TCPSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/socket/TCPSocket.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/socket/TCPSocket.cpp -o CMakeFiles/include.dir/socket/TCPSocket.cpp.s

include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o: /home/usercommon/ChatCpp/include/thread_pool/ThreadPool.cpp
include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o -MF CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o.d -o CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o -c /home/usercommon/ChatCpp/include/thread_pool/ThreadPool.cpp

include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/thread_pool/ThreadPool.cpp > CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.i

include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/thread_pool/ThreadPool.cpp -o CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.s

include/CMakeFiles/include.dir/user/Room.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/user/Room.cpp.o: /home/usercommon/ChatCpp/include/user/Room.cpp
include/CMakeFiles/include.dir/user/Room.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object include/CMakeFiles/include.dir/user/Room.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/user/Room.cpp.o -MF CMakeFiles/include.dir/user/Room.cpp.o.d -o CMakeFiles/include.dir/user/Room.cpp.o -c /home/usercommon/ChatCpp/include/user/Room.cpp

include/CMakeFiles/include.dir/user/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/user/Room.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/user/Room.cpp > CMakeFiles/include.dir/user/Room.cpp.i

include/CMakeFiles/include.dir/user/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/user/Room.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/user/Room.cpp -o CMakeFiles/include.dir/user/Room.cpp.s

include/CMakeFiles/include.dir/user/User.cpp.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/user/User.cpp.o: /home/usercommon/ChatCpp/include/user/User.cpp
include/CMakeFiles/include.dir/user/User.cpp.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object include/CMakeFiles/include.dir/user/User.cpp.o"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/user/User.cpp.o -MF CMakeFiles/include.dir/user/User.cpp.o.d -o CMakeFiles/include.dir/user/User.cpp.o -c /home/usercommon/ChatCpp/include/user/User.cpp

include/CMakeFiles/include.dir/user/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/user/User.cpp.i"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/ChatCpp/include/user/User.cpp > CMakeFiles/include.dir/user/User.cpp.i

include/CMakeFiles/include.dir/user/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/user/User.cpp.s"
	cd /home/usercommon/ChatCpp/out/include && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/ChatCpp/include/user/User.cpp -o CMakeFiles/include.dir/user/User.cpp.s

# Object files for target include
include_OBJECTS = \
"CMakeFiles/include.dir/command/Command.cpp.o" \
"CMakeFiles/include.dir/socket/Message.cpp.o" \
"CMakeFiles/include.dir/socket/Package.cpp.o" \
"CMakeFiles/include.dir/socket/TCPSocket.cpp.o" \
"CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o" \
"CMakeFiles/include.dir/user/Room.cpp.o" \
"CMakeFiles/include.dir/user/User.cpp.o"

# External object files for target include
include_EXTERNAL_OBJECTS =

include/libinclude.a: include/CMakeFiles/include.dir/command/Command.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/socket/Message.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/socket/Package.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/socket/TCPSocket.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/thread_pool/ThreadPool.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/user/Room.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/user/User.cpp.o
include/libinclude.a: include/CMakeFiles/include.dir/build.make
include/libinclude.a: include/CMakeFiles/include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/usercommon/ChatCpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libinclude.a"
	cd /home/usercommon/ChatCpp/out/include && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean_target.cmake
	cd /home/usercommon/ChatCpp/out/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/include.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/include.dir/build: include/libinclude.a
.PHONY : include/CMakeFiles/include.dir/build

include/CMakeFiles/include.dir/clean:
	cd /home/usercommon/ChatCpp/out/include && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/include.dir/clean

include/CMakeFiles/include.dir/depend:
	cd /home/usercommon/ChatCpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usercommon/ChatCpp /home/usercommon/ChatCpp/include /home/usercommon/ChatCpp/out /home/usercommon/ChatCpp/out/include /home/usercommon/ChatCpp/out/include/CMakeFiles/include.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : include/CMakeFiles/include.dir/depend

