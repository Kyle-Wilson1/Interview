# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/github/Interview/ali

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/github/Interview/ali/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ali.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ali.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ali.dir/flags.make

CMakeFiles/ali.dir/main.cpp.o: CMakeFiles/ali.dir/flags.make
CMakeFiles/ali.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/github/Interview/ali/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ali.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ali.dir/main.cpp.o -c /workspace/github/Interview/ali/main.cpp

CMakeFiles/ali.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ali.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/github/Interview/ali/main.cpp > CMakeFiles/ali.dir/main.cpp.i

CMakeFiles/ali.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ali.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/github/Interview/ali/main.cpp -o CMakeFiles/ali.dir/main.cpp.s

CMakeFiles/ali.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ali.dir/main.cpp.o.requires

CMakeFiles/ali.dir/main.cpp.o.provides: CMakeFiles/ali.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ali.dir/build.make CMakeFiles/ali.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ali.dir/main.cpp.o.provides

CMakeFiles/ali.dir/main.cpp.o.provides.build: CMakeFiles/ali.dir/main.cpp.o


# Object files for target ali
ali_OBJECTS = \
"CMakeFiles/ali.dir/main.cpp.o"

# External object files for target ali
ali_EXTERNAL_OBJECTS =

ali: CMakeFiles/ali.dir/main.cpp.o
ali: CMakeFiles/ali.dir/build.make
ali: CMakeFiles/ali.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspace/github/Interview/ali/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ali"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ali.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ali.dir/build: ali

.PHONY : CMakeFiles/ali.dir/build

CMakeFiles/ali.dir/requires: CMakeFiles/ali.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ali.dir/requires

CMakeFiles/ali.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ali.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ali.dir/clean

CMakeFiles/ali.dir/depend:
	cd /workspace/github/Interview/ali/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/github/Interview/ali /workspace/github/Interview/ali /workspace/github/Interview/ali/cmake-build-debug /workspace/github/Interview/ali/cmake-build-debug /workspace/github/Interview/ali/cmake-build-debug/CMakeFiles/ali.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ali.dir/depend

