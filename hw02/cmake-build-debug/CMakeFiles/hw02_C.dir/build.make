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
CMAKE_SOURCE_DIR = /home/marek/Documents/pb161/hw02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Documents/pb161/hw02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw02_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw02_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw02_C.dir/flags.make

CMakeFiles/hw02_C.dir/main.c.o: CMakeFiles/hw02_C.dir/flags.make
CMakeFiles/hw02_C.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/pb161/hw02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hw02_C.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hw02_C.dir/main.c.o   -c /home/marek/Documents/pb161/hw02/main.c

CMakeFiles/hw02_C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw02_C.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marek/Documents/pb161/hw02/main.c > CMakeFiles/hw02_C.dir/main.c.i

CMakeFiles/hw02_C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw02_C.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marek/Documents/pb161/hw02/main.c -o CMakeFiles/hw02_C.dir/main.c.s

# Object files for target hw02_C
hw02_C_OBJECTS = \
"CMakeFiles/hw02_C.dir/main.c.o"

# External object files for target hw02_C
hw02_C_EXTERNAL_OBJECTS = \
"/home/marek/Documents/pb161/hw02/cmake-build-debug/CMakeFiles/configC.dir/config.c.o"

hw02_C: CMakeFiles/hw02_C.dir/main.c.o
hw02_C: CMakeFiles/configC.dir/config.c.o
hw02_C: CMakeFiles/hw02_C.dir/build.make
hw02_C: CMakeFiles/hw02_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Documents/pb161/hw02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hw02_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw02_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw02_C.dir/build: hw02_C

.PHONY : CMakeFiles/hw02_C.dir/build

CMakeFiles/hw02_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw02_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw02_C.dir/clean

CMakeFiles/hw02_C.dir/depend:
	cd /home/marek/Documents/pb161/hw02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Documents/pb161/hw02 /home/marek/Documents/pb161/hw02 /home/marek/Documents/pb161/hw02/cmake-build-debug /home/marek/Documents/pb161/hw02/cmake-build-debug /home/marek/Documents/pb161/hw02/cmake-build-debug/CMakeFiles/hw02_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw02_C.dir/depend

