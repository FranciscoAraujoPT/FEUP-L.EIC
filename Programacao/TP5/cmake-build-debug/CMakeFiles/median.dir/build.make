# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/median.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/median.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/median.dir/flags.make

CMakeFiles/median.dir/median.cpp.o: CMakeFiles/median.dir/flags.make
CMakeFiles/median.dir/median.cpp.o: ../median.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/median.dir/median.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/median.dir/median.cpp.o -c /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/median.cpp

CMakeFiles/median.dir/median.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/median.dir/median.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/median.cpp > CMakeFiles/median.dir/median.cpp.i

CMakeFiles/median.dir/median.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/median.dir/median.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/median.cpp -o CMakeFiles/median.dir/median.cpp.s

# Object files for target median
median_OBJECTS = \
"CMakeFiles/median.dir/median.cpp.o"

# External object files for target median
median_EXTERNAL_OBJECTS =

median: CMakeFiles/median.dir/median.cpp.o
median: CMakeFiles/median.dir/build.make
median: CMakeFiles/median.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable median"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/median.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/median.dir/build: median
.PHONY : CMakeFiles/median.dir/build

CMakeFiles/median.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/median.dir/cmake_clean.cmake
.PHONY : CMakeFiles/median.dir/clean

CMakeFiles/median.dir/depend:
	cd /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5 /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5 /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug /Users/franciscoaraujo/Desktop/FEUP-L.EIC/Programacao/TP5/cmake-build-debug/CMakeFiles/median.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/median.dir/depend
