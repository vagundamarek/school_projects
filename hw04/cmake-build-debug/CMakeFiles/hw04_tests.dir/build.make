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
CMAKE_SOURCE_DIR = /home/marek/Documents/pb161/hw04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Documents/pb161/hw04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw04_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw04_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw04_tests.dir/flags.make

CMakeFiles/hw04_tests.dir/test_main.cpp.o: CMakeFiles/hw04_tests.dir/flags.make
CMakeFiles/hw04_tests.dir/test_main.cpp.o: ../test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw04_tests.dir/test_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw04_tests.dir/test_main.cpp.o -c /home/marek/Documents/pb161/hw04/test_main.cpp

CMakeFiles/hw04_tests.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw04_tests.dir/test_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/pb161/hw04/test_main.cpp > CMakeFiles/hw04_tests.dir/test_main.cpp.i

CMakeFiles/hw04_tests.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw04_tests.dir/test_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/pb161/hw04/test_main.cpp -o CMakeFiles/hw04_tests.dir/test_main.cpp.s

CMakeFiles/hw04_tests.dir/test_student.cpp.o: CMakeFiles/hw04_tests.dir/flags.make
CMakeFiles/hw04_tests.dir/test_student.cpp.o: ../test_student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw04_tests.dir/test_student.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw04_tests.dir/test_student.cpp.o -c /home/marek/Documents/pb161/hw04/test_student.cpp

CMakeFiles/hw04_tests.dir/test_student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw04_tests.dir/test_student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/pb161/hw04/test_student.cpp > CMakeFiles/hw04_tests.dir/test_student.cpp.i

CMakeFiles/hw04_tests.dir/test_student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw04_tests.dir/test_student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/pb161/hw04/test_student.cpp -o CMakeFiles/hw04_tests.dir/test_student.cpp.s

# Object files for target hw04_tests
hw04_tests_OBJECTS = \
"CMakeFiles/hw04_tests.dir/test_main.cpp.o" \
"CMakeFiles/hw04_tests.dir/test_student.cpp.o"

# External object files for target hw04_tests
hw04_tests_EXTERNAL_OBJECTS =

hw04_tests: CMakeFiles/hw04_tests.dir/test_main.cpp.o
hw04_tests: CMakeFiles/hw04_tests.dir/test_student.cpp.o
hw04_tests: CMakeFiles/hw04_tests.dir/build.make
hw04_tests: CMakeFiles/hw04_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Documents/pb161/hw04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hw04_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw04_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw04_tests.dir/build: hw04_tests

.PHONY : CMakeFiles/hw04_tests.dir/build

CMakeFiles/hw04_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw04_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw04_tests.dir/clean

CMakeFiles/hw04_tests.dir/depend:
	cd /home/marek/Documents/pb161/hw04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Documents/pb161/hw04 /home/marek/Documents/pb161/hw04 /home/marek/Documents/pb161/hw04/cmake-build-debug /home/marek/Documents/pb161/hw04/cmake-build-debug /home/marek/Documents/pb161/hw04/cmake-build-debug/CMakeFiles/hw04_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw04_tests.dir/depend

