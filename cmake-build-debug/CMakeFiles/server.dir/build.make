# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/miketerentyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/miketerentyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/starters/server_starter.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/starters/server_starter.cpp.o: ../starters/server_starter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/starters/server_starter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/starters/server_starter.cpp.o -c /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/starters/server_starter.cpp

CMakeFiles/server.dir/starters/server_starter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/starters/server_starter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/starters/server_starter.cpp > CMakeFiles/server.dir/starters/server_starter.cpp.i

CMakeFiles/server.dir/starters/server_starter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/starters/server_starter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/starters/server_starter.cpp -o CMakeFiles/server.dir/starters/server_starter.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/starters/server_starter.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/starters/server_starter.cpp.o
server: CMakeFiles/server.dir/build.make
server: libserver-lib.a
server: libcommon.a
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug /Users/miketerentyev/itmo/2-year/tmp/os-net-descriptor-passing/cmake-build-debug/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

