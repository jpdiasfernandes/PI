# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/103/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/103/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jose/Universidade/PI/ficha4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jose/Universidade/PI/ficha4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ficha4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ficha4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ficha4.dir/flags.make

CMakeFiles/ficha4.dir/main.c.o: CMakeFiles/ficha4.dir/flags.make
CMakeFiles/ficha4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Universidade/PI/ficha4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ficha4.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ficha4.dir/main.c.o   -c /home/jose/Universidade/PI/ficha4/main.c

CMakeFiles/ficha4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ficha4.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jose/Universidade/PI/ficha4/main.c > CMakeFiles/ficha4.dir/main.c.i

CMakeFiles/ficha4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ficha4.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jose/Universidade/PI/ficha4/main.c -o CMakeFiles/ficha4.dir/main.c.s

CMakeFiles/ficha4.dir/ficha4.c.o: CMakeFiles/ficha4.dir/flags.make
CMakeFiles/ficha4.dir/ficha4.c.o: ../ficha4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Universidade/PI/ficha4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ficha4.dir/ficha4.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ficha4.dir/ficha4.c.o   -c /home/jose/Universidade/PI/ficha4/ficha4.c

CMakeFiles/ficha4.dir/ficha4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ficha4.dir/ficha4.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jose/Universidade/PI/ficha4/ficha4.c > CMakeFiles/ficha4.dir/ficha4.c.i

CMakeFiles/ficha4.dir/ficha4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ficha4.dir/ficha4.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jose/Universidade/PI/ficha4/ficha4.c -o CMakeFiles/ficha4.dir/ficha4.c.s

# Object files for target ficha4
ficha4_OBJECTS = \
"CMakeFiles/ficha4.dir/main.c.o" \
"CMakeFiles/ficha4.dir/ficha4.c.o"

# External object files for target ficha4
ficha4_EXTERNAL_OBJECTS =

ficha4: CMakeFiles/ficha4.dir/main.c.o
ficha4: CMakeFiles/ficha4.dir/ficha4.c.o
ficha4: CMakeFiles/ficha4.dir/build.make
ficha4: CMakeFiles/ficha4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jose/Universidade/PI/ficha4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ficha4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ficha4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ficha4.dir/build: ficha4

.PHONY : CMakeFiles/ficha4.dir/build

CMakeFiles/ficha4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ficha4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ficha4.dir/clean

CMakeFiles/ficha4.dir/depend:
	cd /home/jose/Universidade/PI/ficha4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jose/Universidade/PI/ficha4 /home/jose/Universidade/PI/ficha4 /home/jose/Universidade/PI/ficha4/cmake-build-debug /home/jose/Universidade/PI/ficha4/cmake-build-debug /home/jose/Universidade/PI/ficha4/cmake-build-debug/CMakeFiles/ficha4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ficha4.dir/depend

