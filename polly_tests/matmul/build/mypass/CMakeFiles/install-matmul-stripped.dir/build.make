# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build

# Utility rule file for install-matmul-stripped.

# Include any custom commands dependencies for this target.
include mypass/CMakeFiles/install-matmul-stripped.dir/compiler_depend.make

# Include the progress variables for this target.
include mypass/CMakeFiles/install-matmul-stripped.dir/progress.make

mypass/CMakeFiles/install-matmul-stripped:
	cd /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build/mypass && /opt/homebrew/Cellar/cmake/3.23.0/bin/cmake -DCMAKE_INSTALL_COMPONENT="matmul" -DCMAKE_INSTALL_DO_STRIP=1 -P /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build/cmake_install.cmake

install-matmul-stripped: mypass/CMakeFiles/install-matmul-stripped
install-matmul-stripped: mypass/CMakeFiles/install-matmul-stripped.dir/build.make
.PHONY : install-matmul-stripped

# Rule to build all files generated by this target.
mypass/CMakeFiles/install-matmul-stripped.dir/build: install-matmul-stripped
.PHONY : mypass/CMakeFiles/install-matmul-stripped.dir/build

mypass/CMakeFiles/install-matmul-stripped.dir/clean:
	cd /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build/mypass && $(CMAKE_COMMAND) -P CMakeFiles/install-matmul-stripped.dir/cmake_clean.cmake
.PHONY : mypass/CMakeFiles/install-matmul-stripped.dir/clean

mypass/CMakeFiles/install-matmul-stripped.dir/depend:
	cd /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/mypass /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build/mypass /Users/stevenschaefer/final_projet_EECS583/polly_tests/matmul/build/mypass/CMakeFiles/install-matmul-stripped.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mypass/CMakeFiles/install-matmul-stripped.dir/depend

