# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/marek/Downloads/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/marek/Downloads/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marek/Documents/pb161/hw01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Documents/pb161/hw01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw01_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw01_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw01_tests.dir/flags.make

CMakeFiles/hw01_tests.dir/test-main.cpp.o: CMakeFiles/hw01_tests.dir/flags.make
CMakeFiles/hw01_tests.dir/test-main.cpp.o: ../test-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw01_tests.dir/test-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw01_tests.dir/test-main.cpp.o -c /home/marek/Documents/pb161/hw01/test-main.cpp

CMakeFiles/hw01_tests.dir/test-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw01_tests.dir/test-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/pb161/hw01/test-main.cpp > CMakeFiles/hw01_tests.dir/test-main.cpp.i

CMakeFiles/hw01_tests.dir/test-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw01_tests.dir/test-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/pb161/hw01/test-main.cpp -o CMakeFiles/hw01_tests.dir/test-main.cpp.s

CMakeFiles/hw01_tests.dir/test-student.cpp.o: CMakeFiles/hw01_tests.dir/flags.make
CMakeFiles/hw01_tests.dir/test-student.cpp.o: ../test-student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw01_tests.dir/test-student.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw01_tests.dir/test-student.cpp.o -c /home/marek/Documents/pb161/hw01/test-student.cpp

CMakeFiles/hw01_tests.dir/test-student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw01_tests.dir/test-student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/pb161/hw01/test-student.cpp > CMakeFiles/hw01_tests.dir/test-student.cpp.i

CMakeFiles/hw01_tests.dir/test-student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw01_tests.dir/test-student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/pb161/hw01/test-student.cpp -o CMakeFiles/hw01_tests.dir/test-student.cpp.s

CMakeFiles/hw01_tests.dir/zoo.cpp.o: CMakeFiles/hw01_tests.dir/flags.make
CMakeFiles/hw01_tests.dir/zoo.cpp.o: ../zoo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw01_tests.dir/zoo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw01_tests.dir/zoo.cpp.o -c /home/marek/Documents/pb161/hw01/zoo.cpp

CMakeFiles/hw01_tests.dir/zoo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw01_tests.dir/zoo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/pb161/hw01/zoo.cpp > CMakeFiles/hw01_tests.dir/zoo.cpp.i

CMakeFiles/hw01_tests.dir/zoo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw01_tests.dir/zoo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/pb161/hw01/zoo.cpp -o CMakeFiles/hw01_tests.dir/zoo.cpp.s

CMakeFiles/hw01_tests.dir/handler.cpp.o: CMakeFiles/hw01_tests.dir/flags.make
CMakeFiles/hw01_tests.dir/handler.cpp.o: ../handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw01_tests.dir/handler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw01_tests.dir/handler.cpp.o -c /home/marek/Documents/pb161/hw01/handler.cpp

CMakeFiles/hw01_tests.dir/handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw01_tests.dir/handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/pb161/hw01/handler.cpp > CMakeFiles/hw01_tests.dir/handler.cpp.i

CMakeFiles/hw01_tests.dir/handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw01_tests.dir/handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/pb161/hw01/handler.cpp -o CMakeFiles/hw01_tests.dir/handler.cpp.s

# Object files for target hw01_tests
hw01_tests_OBJECTS = \
"CMakeFiles/hw01_tests.dir/test-main.cpp.o" \
"CMakeFiles/hw01_tests.dir/test-student.cpp.o" \
"CMakeFiles/hw01_tests.dir/zoo.cpp.o" \
"CMakeFiles/hw01_tests.dir/handler.cpp.o"

# External object files for target hw01_tests
hw01_tests_EXTERNAL_OBJECTS =

hw01_tests: CMakeFiles/hw01_tests.dir/test-main.cpp.o
hw01_tests: CMakeFiles/hw01_tests.dir/test-student.cpp.o
hw01_tests: CMakeFiles/hw01_tests.dir/zoo.cpp.o
hw01_tests: CMakeFiles/hw01_tests.dir/handler.cpp.o
hw01_tests: CMakeFiles/hw01_tests.dir/build.make
hw01_tests: CMakeFiles/hw01_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Documents/pb161/hw01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable hw01_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw01_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw01_tests.dir/build: hw01_tests

.PHONY : CMakeFiles/hw01_tests.dir/build

CMakeFiles/hw01_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw01_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw01_tests.dir/clean

CMakeFiles/hw01_tests.dir/depend:
	cd /home/marek/Documents/pb161/hw01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Documents/pb161/hw01 /home/marek/Documents/pb161/hw01 /home/marek/Documents/pb161/hw01/cmake-build-debug /home/marek/Documents/pb161/hw01/cmake-build-debug /home/marek/Documents/pb161/hw01/cmake-build-debug/CMakeFiles/hw01_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw01_tests.dir/depend

