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
CMAKE_SOURCE_DIR = /home/sartre/labwork2-IntolerabilisExistentia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sartre/labwork2-IntolerabilisExistentia/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/labwork2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/CMakeFiles/labwork2.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/labwork2.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/labwork2.dir/flags.make

bin/CMakeFiles/labwork2.dir/main.cpp.o: bin/CMakeFiles/labwork2.dir/flags.make
bin/CMakeFiles/labwork2.dir/main.cpp.o: /home/sartre/labwork2-IntolerabilisExistentia/bin/main.cpp
bin/CMakeFiles/labwork2.dir/main.cpp.o: bin/CMakeFiles/labwork2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sartre/labwork2-IntolerabilisExistentia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/labwork2.dir/main.cpp.o"
	cd /home/sartre/labwork2-IntolerabilisExistentia/build/bin && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/CMakeFiles/labwork2.dir/main.cpp.o -MF CMakeFiles/labwork2.dir/main.cpp.o.d -o CMakeFiles/labwork2.dir/main.cpp.o -c /home/sartre/labwork2-IntolerabilisExistentia/bin/main.cpp

bin/CMakeFiles/labwork2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/labwork2.dir/main.cpp.i"
	cd /home/sartre/labwork2-IntolerabilisExistentia/build/bin && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sartre/labwork2-IntolerabilisExistentia/bin/main.cpp > CMakeFiles/labwork2.dir/main.cpp.i

bin/CMakeFiles/labwork2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/labwork2.dir/main.cpp.s"
	cd /home/sartre/labwork2-IntolerabilisExistentia/build/bin && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sartre/labwork2-IntolerabilisExistentia/bin/main.cpp -o CMakeFiles/labwork2.dir/main.cpp.s

# Object files for target labwork2
labwork2_OBJECTS = \
"CMakeFiles/labwork2.dir/main.cpp.o"

# External object files for target labwork2
labwork2_EXTERNAL_OBJECTS =

bin/labwork2: bin/CMakeFiles/labwork2.dir/main.cpp.o
bin/labwork2: bin/CMakeFiles/labwork2.dir/build.make
bin/labwork2: lib/libnumber.a
bin/labwork2: bin/CMakeFiles/labwork2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sartre/labwork2-IntolerabilisExistentia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable labwork2"
	cd /home/sartre/labwork2-IntolerabilisExistentia/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/labwork2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/labwork2.dir/build: bin/labwork2
.PHONY : bin/CMakeFiles/labwork2.dir/build

bin/CMakeFiles/labwork2.dir/clean:
	cd /home/sartre/labwork2-IntolerabilisExistentia/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/labwork2.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/labwork2.dir/clean

bin/CMakeFiles/labwork2.dir/depend:
	cd /home/sartre/labwork2-IntolerabilisExistentia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sartre/labwork2-IntolerabilisExistentia /home/sartre/labwork2-IntolerabilisExistentia/bin /home/sartre/labwork2-IntolerabilisExistentia/build /home/sartre/labwork2-IntolerabilisExistentia/build/bin /home/sartre/labwork2-IntolerabilisExistentia/build/bin/CMakeFiles/labwork2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : bin/CMakeFiles/labwork2.dir/depend

