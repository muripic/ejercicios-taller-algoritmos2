# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/muripic/Documents/AED_II/06_ejercitacion_iteradores

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej7.dir/flags.make

CMakeFiles/ej7.dir/tests/algo_tests.cpp.o: CMakeFiles/ej7.dir/flags.make
CMakeFiles/ej7.dir/tests/algo_tests.cpp.o: ../tests/algo_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej7.dir/tests/algo_tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej7.dir/tests/algo_tests.cpp.o -c /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/tests/algo_tests.cpp

CMakeFiles/ej7.dir/tests/algo_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej7.dir/tests/algo_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/tests/algo_tests.cpp > CMakeFiles/ej7.dir/tests/algo_tests.cpp.i

CMakeFiles/ej7.dir/tests/algo_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej7.dir/tests/algo_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/tests/algo_tests.cpp -o CMakeFiles/ej7.dir/tests/algo_tests.cpp.s

# Object files for target ej7
ej7_OBJECTS = \
"CMakeFiles/ej7.dir/tests/algo_tests.cpp.o"

# External object files for target ej7
ej7_EXTERNAL_OBJECTS =

ej7: CMakeFiles/ej7.dir/tests/algo_tests.cpp.o
ej7: CMakeFiles/ej7.dir/build.make
ej7: tests/google-test/libgtest.a
ej7: tests/google-test/libgtest_main.a
ej7: tests/google-test/libgtest.a
ej7: CMakeFiles/ej7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej7.dir/build: ej7

.PHONY : CMakeFiles/ej7.dir/build

CMakeFiles/ej7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej7.dir/clean

CMakeFiles/ej7.dir/depend:
	cd /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muripic/Documents/AED_II/06_ejercitacion_iteradores /home/muripic/Documents/AED_II/06_ejercitacion_iteradores /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug /home/muripic/Documents/AED_II/06_ejercitacion_iteradores/cmake-build-debug/CMakeFiles/ej7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej7.dir/depend

