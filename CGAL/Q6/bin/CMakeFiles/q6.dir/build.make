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
CMAKE_SOURCE_DIR = /home/rohit/Assigments/CGAL/Q6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohit/Assigments/CGAL/Q6/bin

# Include any dependencies generated for this target.
include CMakeFiles/q6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/q6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/q6.dir/flags.make

CMakeFiles/q6.dir/q6.cpp.o: CMakeFiles/q6.dir/flags.make
CMakeFiles/q6.dir/q6.cpp.o: ../q6.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohit/Assigments/CGAL/Q6/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/q6.dir/q6.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q6.dir/q6.cpp.o -c /home/rohit/Assigments/CGAL/Q6/q6.cpp

CMakeFiles/q6.dir/q6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q6.dir/q6.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohit/Assigments/CGAL/Q6/q6.cpp > CMakeFiles/q6.dir/q6.cpp.i

CMakeFiles/q6.dir/q6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q6.dir/q6.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohit/Assigments/CGAL/Q6/q6.cpp -o CMakeFiles/q6.dir/q6.cpp.s

# Object files for target q6
q6_OBJECTS = \
"CMakeFiles/q6.dir/q6.cpp.o"

# External object files for target q6
q6_EXTERNAL_OBJECTS =

q6: CMakeFiles/q6.dir/q6.cpp.o
q6: CMakeFiles/q6.dir/build.make
q6: /usr/lib/x86_64-linux-gnu/libmpfr.so
q6: /usr/lib/x86_64-linux-gnu/libgmp.so
q6: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL_Qt5.so.13.0.0
q6: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL.so.13.0.0
q6: /usr/lib/x86_64-linux-gnu/libGL.so
q6: /usr/lib/x86_64-linux-gnu/libGLU.so
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Xml.so.5.6.3
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Script.so.5.6.3
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5OpenGL.so.5.6.3
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Svg.so.5.6.3
q6: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL_Qt5.so.13.0.0
q6: /home/rohit/Projects/cgal/cgal-install/lib/libCGAL.so.13.0.0
q6: /usr/lib/x86_64-linux-gnu/libGL.so
q6: /usr/lib/x86_64-linux-gnu/libGLU.so
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Widgets.so.5.6.3
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Gui.so.5.6.3
q6: /home/rohit/Qt5.6.3/5.6.3/gcc_64/lib/libQt5Core.so.5.6.3
q6: CMakeFiles/q6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rohit/Assigments/CGAL/Q6/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable q6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/q6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/q6.dir/build: q6

.PHONY : CMakeFiles/q6.dir/build

CMakeFiles/q6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/q6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/q6.dir/clean

CMakeFiles/q6.dir/depend:
	cd /home/rohit/Assigments/CGAL/Q6/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohit/Assigments/CGAL/Q6 /home/rohit/Assigments/CGAL/Q6 /home/rohit/Assigments/CGAL/Q6/bin /home/rohit/Assigments/CGAL/Q6/bin /home/rohit/Assigments/CGAL/Q6/bin/CMakeFiles/q6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/q6.dir/depend

