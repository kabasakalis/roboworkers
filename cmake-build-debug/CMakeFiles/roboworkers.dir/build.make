# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /opt/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spiros/cpp/roboworkers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spiros/cpp/roboworkers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/roboworkers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roboworkers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roboworkers.dir/flags.make

CMakeFiles/roboworkers.dir/src/backoffice.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/backoffice.cpp.o: ../src/backoffice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roboworkers.dir/src/backoffice.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/backoffice.cpp.o -c /home/spiros/cpp/roboworkers/src/backoffice.cpp

CMakeFiles/roboworkers.dir/src/backoffice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/backoffice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/backoffice.cpp > CMakeFiles/roboworkers.dir/src/backoffice.cpp.i

CMakeFiles/roboworkers.dir/src/backoffice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/backoffice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/backoffice.cpp -o CMakeFiles/roboworkers.dir/src/backoffice.cpp.s

CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.requires

CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.provides: CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.provides

CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/backoffice.cpp.o


CMakeFiles/roboworkers.dir/src/identifiable.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/identifiable.cpp.o: ../src/identifiable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/roboworkers.dir/src/identifiable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/identifiable.cpp.o -c /home/spiros/cpp/roboworkers/src/identifiable.cpp

CMakeFiles/roboworkers.dir/src/identifiable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/identifiable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/identifiable.cpp > CMakeFiles/roboworkers.dir/src/identifiable.cpp.i

CMakeFiles/roboworkers.dir/src/identifiable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/identifiable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/identifiable.cpp -o CMakeFiles/roboworkers.dir/src/identifiable.cpp.s

CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.requires

CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.provides: CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.provides

CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/identifiable.cpp.o


CMakeFiles/roboworkers.dir/src/lift.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/lift.cpp.o: ../src/lift.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/roboworkers.dir/src/lift.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/lift.cpp.o -c /home/spiros/cpp/roboworkers/src/lift.cpp

CMakeFiles/roboworkers.dir/src/lift.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/lift.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/lift.cpp > CMakeFiles/roboworkers.dir/src/lift.cpp.i

CMakeFiles/roboworkers.dir/src/lift.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/lift.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/lift.cpp -o CMakeFiles/roboworkers.dir/src/lift.cpp.s

CMakeFiles/roboworkers.dir/src/lift.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/lift.cpp.o.requires

CMakeFiles/roboworkers.dir/src/lift.cpp.o.provides: CMakeFiles/roboworkers.dir/src/lift.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/lift.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/lift.cpp.o.provides

CMakeFiles/roboworkers.dir/src/lift.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/lift.cpp.o


CMakeFiles/roboworkers.dir/src/main.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/roboworkers.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/main.cpp.o -c /home/spiros/cpp/roboworkers/src/main.cpp

CMakeFiles/roboworkers.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/main.cpp > CMakeFiles/roboworkers.dir/src/main.cpp.i

CMakeFiles/roboworkers.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/main.cpp -o CMakeFiles/roboworkers.dir/src/main.cpp.s

CMakeFiles/roboworkers.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/main.cpp.o.requires

CMakeFiles/roboworkers.dir/src/main.cpp.o.provides: CMakeFiles/roboworkers.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/main.cpp.o.provides

CMakeFiles/roboworkers.dir/src/main.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/main.cpp.o


CMakeFiles/roboworkers.dir/src/move.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/move.cpp.o: ../src/move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/roboworkers.dir/src/move.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/move.cpp.o -c /home/spiros/cpp/roboworkers/src/move.cpp

CMakeFiles/roboworkers.dir/src/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/move.cpp > CMakeFiles/roboworkers.dir/src/move.cpp.i

CMakeFiles/roboworkers.dir/src/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/move.cpp -o CMakeFiles/roboworkers.dir/src/move.cpp.s

CMakeFiles/roboworkers.dir/src/move.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/move.cpp.o.requires

CMakeFiles/roboworkers.dir/src/move.cpp.o.provides: CMakeFiles/roboworkers.dir/src/move.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/move.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/move.cpp.o.provides

CMakeFiles/roboworkers.dir/src/move.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/move.cpp.o


CMakeFiles/roboworkers.dir/src/package.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/package.cpp.o: ../src/package.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/roboworkers.dir/src/package.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/package.cpp.o -c /home/spiros/cpp/roboworkers/src/package.cpp

CMakeFiles/roboworkers.dir/src/package.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/package.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/package.cpp > CMakeFiles/roboworkers.dir/src/package.cpp.i

CMakeFiles/roboworkers.dir/src/package.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/package.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/package.cpp -o CMakeFiles/roboworkers.dir/src/package.cpp.s

CMakeFiles/roboworkers.dir/src/package.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/package.cpp.o.requires

CMakeFiles/roboworkers.dir/src/package.cpp.o.provides: CMakeFiles/roboworkers.dir/src/package.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/package.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/package.cpp.o.provides

CMakeFiles/roboworkers.dir/src/package.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/package.cpp.o


CMakeFiles/roboworkers.dir/src/product.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/product.cpp.o: ../src/product.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/roboworkers.dir/src/product.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/product.cpp.o -c /home/spiros/cpp/roboworkers/src/product.cpp

CMakeFiles/roboworkers.dir/src/product.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/product.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/product.cpp > CMakeFiles/roboworkers.dir/src/product.cpp.i

CMakeFiles/roboworkers.dir/src/product.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/product.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/product.cpp -o CMakeFiles/roboworkers.dir/src/product.cpp.s

CMakeFiles/roboworkers.dir/src/product.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/product.cpp.o.requires

CMakeFiles/roboworkers.dir/src/product.cpp.o.provides: CMakeFiles/roboworkers.dir/src/product.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/product.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/product.cpp.o.provides

CMakeFiles/roboworkers.dir/src/product.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/product.cpp.o


CMakeFiles/roboworkers.dir/src/putdown.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/putdown.cpp.o: ../src/putdown.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/roboworkers.dir/src/putdown.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/putdown.cpp.o -c /home/spiros/cpp/roboworkers/src/putdown.cpp

CMakeFiles/roboworkers.dir/src/putdown.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/putdown.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/putdown.cpp > CMakeFiles/roboworkers.dir/src/putdown.cpp.i

CMakeFiles/roboworkers.dir/src/putdown.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/putdown.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/putdown.cpp -o CMakeFiles/roboworkers.dir/src/putdown.cpp.s

CMakeFiles/roboworkers.dir/src/putdown.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/putdown.cpp.o.requires

CMakeFiles/roboworkers.dir/src/putdown.cpp.o.provides: CMakeFiles/roboworkers.dir/src/putdown.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/putdown.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/putdown.cpp.o.provides

CMakeFiles/roboworkers.dir/src/putdown.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/putdown.cpp.o


CMakeFiles/roboworkers.dir/src/task.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/task.cpp.o: ../src/task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/roboworkers.dir/src/task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/task.cpp.o -c /home/spiros/cpp/roboworkers/src/task.cpp

CMakeFiles/roboworkers.dir/src/task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/task.cpp > CMakeFiles/roboworkers.dir/src/task.cpp.i

CMakeFiles/roboworkers.dir/src/task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/task.cpp -o CMakeFiles/roboworkers.dir/src/task.cpp.s

CMakeFiles/roboworkers.dir/src/task.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/task.cpp.o.requires

CMakeFiles/roboworkers.dir/src/task.cpp.o.provides: CMakeFiles/roboworkers.dir/src/task.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/task.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/task.cpp.o.provides

CMakeFiles/roboworkers.dir/src/task.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/task.cpp.o


CMakeFiles/roboworkers.dir/src/warehouse.cpp.o: CMakeFiles/roboworkers.dir/flags.make
CMakeFiles/roboworkers.dir/src/warehouse.cpp.o: ../src/warehouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/roboworkers.dir/src/warehouse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboworkers.dir/src/warehouse.cpp.o -c /home/spiros/cpp/roboworkers/src/warehouse.cpp

CMakeFiles/roboworkers.dir/src/warehouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboworkers.dir/src/warehouse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spiros/cpp/roboworkers/src/warehouse.cpp > CMakeFiles/roboworkers.dir/src/warehouse.cpp.i

CMakeFiles/roboworkers.dir/src/warehouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboworkers.dir/src/warehouse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spiros/cpp/roboworkers/src/warehouse.cpp -o CMakeFiles/roboworkers.dir/src/warehouse.cpp.s

CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.requires:

.PHONY : CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.requires

CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.provides: CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboworkers.dir/build.make CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.provides.build
.PHONY : CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.provides

CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.provides.build: CMakeFiles/roboworkers.dir/src/warehouse.cpp.o


# Object files for target roboworkers
roboworkers_OBJECTS = \
"CMakeFiles/roboworkers.dir/src/backoffice.cpp.o" \
"CMakeFiles/roboworkers.dir/src/identifiable.cpp.o" \
"CMakeFiles/roboworkers.dir/src/lift.cpp.o" \
"CMakeFiles/roboworkers.dir/src/main.cpp.o" \
"CMakeFiles/roboworkers.dir/src/move.cpp.o" \
"CMakeFiles/roboworkers.dir/src/package.cpp.o" \
"CMakeFiles/roboworkers.dir/src/product.cpp.o" \
"CMakeFiles/roboworkers.dir/src/putdown.cpp.o" \
"CMakeFiles/roboworkers.dir/src/task.cpp.o" \
"CMakeFiles/roboworkers.dir/src/warehouse.cpp.o"

# External object files for target roboworkers
roboworkers_EXTERNAL_OBJECTS =

roboworkers: CMakeFiles/roboworkers.dir/src/backoffice.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/identifiable.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/lift.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/main.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/move.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/package.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/product.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/putdown.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/task.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/src/warehouse.cpp.o
roboworkers: CMakeFiles/roboworkers.dir/build.make
roboworkers: CMakeFiles/roboworkers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable roboworkers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roboworkers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roboworkers.dir/build: roboworkers

.PHONY : CMakeFiles/roboworkers.dir/build

CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/backoffice.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/identifiable.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/lift.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/main.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/move.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/package.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/product.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/putdown.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/task.cpp.o.requires
CMakeFiles/roboworkers.dir/requires: CMakeFiles/roboworkers.dir/src/warehouse.cpp.o.requires

.PHONY : CMakeFiles/roboworkers.dir/requires

CMakeFiles/roboworkers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roboworkers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roboworkers.dir/clean

CMakeFiles/roboworkers.dir/depend:
	cd /home/spiros/cpp/roboworkers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spiros/cpp/roboworkers /home/spiros/cpp/roboworkers /home/spiros/cpp/roboworkers/cmake-build-debug /home/spiros/cpp/roboworkers/cmake-build-debug /home/spiros/cpp/roboworkers/cmake-build-debug/CMakeFiles/roboworkers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roboworkers.dir/depend

