# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11

# Include any dependencies generated for this target.
include CMakeFiles/lesson11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lesson11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson11.dir/flags.make

CMakeFiles/lesson11.dir/lesson11.c.o: CMakeFiles/lesson11.dir/flags.make
CMakeFiles/lesson11.dir/lesson11.c.o: lesson11.c
CMakeFiles/lesson11.dir/lesson11.c.o: CMakeFiles/lesson11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/monrisk1/file/os_learning/multi_thread_programming/lesson11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lesson11.dir/lesson11.c.o"
	/usr/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lesson11.dir/lesson11.c.o -MF CMakeFiles/lesson11.dir/lesson11.c.o.d -o CMakeFiles/lesson11.dir/lesson11.c.o -c /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11/lesson11.c

CMakeFiles/lesson11.dir/lesson11.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lesson11.dir/lesson11.c.i"
	/usr/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11/lesson11.c > CMakeFiles/lesson11.dir/lesson11.c.i

CMakeFiles/lesson11.dir/lesson11.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lesson11.dir/lesson11.c.s"
	/usr/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11/lesson11.c -o CMakeFiles/lesson11.dir/lesson11.c.s

# Object files for target lesson11
lesson11_OBJECTS = \
"CMakeFiles/lesson11.dir/lesson11.c.o"

# External object files for target lesson11
lesson11_EXTERNAL_OBJECTS =

lesson11: CMakeFiles/lesson11.dir/lesson11.c.o
lesson11: CMakeFiles/lesson11.dir/build.make
lesson11: CMakeFiles/lesson11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/monrisk1/file/os_learning/multi_thread_programming/lesson11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lesson11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson11.dir/build: lesson11
.PHONY : CMakeFiles/lesson11.dir/build

CMakeFiles/lesson11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson11.dir/clean

CMakeFiles/lesson11.dir/depend:
	cd /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11 /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11 /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11 /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11 /opt/monrisk1/file/os_learning/multi_thread_programming/lesson11/CMakeFiles/lesson11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson11.dir/depend

