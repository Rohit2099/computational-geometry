# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rohit/Assigments/CGAL/Q1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohit/Assigments/CGAL/Q1/bin

# Include any dependencies generated for this target.
include CMakeFiles/q1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/q1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/q1.dir/flags.make

CMakeFiles/q1.dir/q1.cpp.o: CMakeFiles/q1.dir/flags.make
CMakeFiles/q1.dir/q1.cpp.o: ../q1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohit/Assigments/CGAL/Q1/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/q1.dir/q1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q1.dir/q1.cpp.o -c /home/rohit/Assigments/CGAL/Q1/q1.cpp

CMakeFiles/q1.dir/q1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q1.dir/q1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohit/Assigments/CGAL/Q1/q1.cpp > CMakeFiles/q1.dir/q1.cpp.i

CMakeFiles/q1.dir/q1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q1.dir/q1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohit/Assigments/CGAL/Q1/q1.cpp -o CMakeFiles/q1.dir/q1.cpp.s

# Object files for target q1
q1_OBJECTS = \
"CMakeFiles/q1.dir/q1.cpp.o"

# External object files for target q1
q1_EXTERNAL_OBJECTS =

q1: CMakeFiles/q1.dir/q1.cpp.o
q1: CMakeFiles/q1.dir/build.make
q1: /usr/lib/x86_64-linux-gnu/libmpfr.so
q1: /usr/lib/x86_64-linux-gnu/libgmp.so
q1: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL_Qt5.so.13.0.0
q1: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL.so.13.0.0
q1: /usr/lib/x86_64-linux-gnu/libGL.so
q1: /usr/lib/x86_64-linux-gnu/libGLU.so
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Xml.so.5.6.3
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Script.so.5.6.3
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5OpenGL.so.5.6.3
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Svg.so.5.6.3
q1: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL_Qt5.so.13.0.0
q1: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL.so.13.0.0
q1: /usr/lib/x86_64-linux-gnu/libGL.so
q1: /usr/lib/x86_64-linux-gnu/libGLU.so
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Widgets.so.5.6.3
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Gui.so.5.6.3
q1: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Core.so.5.6.3
q1: CMakeFiles/q1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rohit/Assigments/CGAL/Q1/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable q1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/q1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/q1.dir/build: q1

.PHONY : CMakeFiles/q1.dir/build

CMakeFiles/q1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/q1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/q1.dir/clean

CMakeFiles/q1.dir/depend:
	cd /home/rohit/Assigments/CGAL/Q1/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohit/Assigments/CGAL/Q1 /home/rohit/Assigments/CGAL/Q1 /home/rohit/Assigments/CGAL/Q1/bin /home/rohit/Assigments/CGAL/Q1/bin /home/rohit/Assigments/CGAL/Q1/bin/CMakeFiles/q1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/q1.dir/depend
