# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build

# Include any dependencies generated for this target.
include CMakeFiles/cmake_testapp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cmake_testapp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cmake_testapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmake_testapp.dir/flags.make

CMakeFiles/cmake_testapp.dir/Date.cpp.o: CMakeFiles/cmake_testapp.dir/flags.make
CMakeFiles/cmake_testapp.dir/Date.cpp.o: /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/Date.cpp
CMakeFiles/cmake_testapp.dir/Date.cpp.o: CMakeFiles/cmake_testapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmake_testapp.dir/Date.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake_testapp.dir/Date.cpp.o -MF CMakeFiles/cmake_testapp.dir/Date.cpp.o.d -o CMakeFiles/cmake_testapp.dir/Date.cpp.o -c /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/Date.cpp

CMakeFiles/cmake_testapp.dir/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cmake_testapp.dir/Date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/Date.cpp > CMakeFiles/cmake_testapp.dir/Date.cpp.i

CMakeFiles/cmake_testapp.dir/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cmake_testapp.dir/Date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/Date.cpp -o CMakeFiles/cmake_testapp.dir/Date.cpp.s

CMakeFiles/cmake_testapp.dir/testDate.cpp.o: CMakeFiles/cmake_testapp.dir/flags.make
CMakeFiles/cmake_testapp.dir/testDate.cpp.o: /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/testDate.cpp
CMakeFiles/cmake_testapp.dir/testDate.cpp.o: CMakeFiles/cmake_testapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cmake_testapp.dir/testDate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake_testapp.dir/testDate.cpp.o -MF CMakeFiles/cmake_testapp.dir/testDate.cpp.o.d -o CMakeFiles/cmake_testapp.dir/testDate.cpp.o -c /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/testDate.cpp

CMakeFiles/cmake_testapp.dir/testDate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cmake_testapp.dir/testDate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/testDate.cpp > CMakeFiles/cmake_testapp.dir/testDate.cpp.i

CMakeFiles/cmake_testapp.dir/testDate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cmake_testapp.dir/testDate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/testDate.cpp -o CMakeFiles/cmake_testapp.dir/testDate.cpp.s

# Object files for target cmake_testapp
cmake_testapp_OBJECTS = \
"CMakeFiles/cmake_testapp.dir/Date.cpp.o" \
"CMakeFiles/cmake_testapp.dir/testDate.cpp.o"

# External object files for target cmake_testapp
cmake_testapp_EXTERNAL_OBJECTS =

cmake_testapp: CMakeFiles/cmake_testapp.dir/Date.cpp.o
cmake_testapp: CMakeFiles/cmake_testapp.dir/testDate.cpp.o
cmake_testapp: CMakeFiles/cmake_testapp.dir/build.make
cmake_testapp: CMakeFiles/cmake_testapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cmake_testapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmake_testapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmake_testapp.dir/build: cmake_testapp
.PHONY : CMakeFiles/cmake_testapp.dir/build

CMakeFiles/cmake_testapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmake_testapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmake_testapp.dir/clean

CMakeFiles/cmake_testapp.dir/depend:
	cd /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build /home/salma/Desktop/Learning/Embedded_Linux_tasks/CmakeFiles/build/CMakeFiles/cmake_testapp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cmake_testapp.dir/depend

