# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\timru\Documents\cpp\physics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\timru\Documents\cpp\physics\build

# Include any dependencies generated for this target.
include CMakeFiles/oreid.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/oreid.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/oreid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oreid.dir/flags.make

CMakeFiles/oreid.dir/main.cpp.obj: CMakeFiles/oreid.dir/flags.make
CMakeFiles/oreid.dir/main.cpp.obj: CMakeFiles/oreid.dir/includes_CXX.rsp
CMakeFiles/oreid.dir/main.cpp.obj: C:/Users/timru/Documents/cpp/physics/main.cpp
CMakeFiles/oreid.dir/main.cpp.obj: CMakeFiles/oreid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\timru\Documents\cpp\physics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oreid.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/oreid.dir/main.cpp.obj -MF CMakeFiles\oreid.dir\main.cpp.obj.d -o CMakeFiles\oreid.dir\main.cpp.obj -c C:\Users\timru\Documents\cpp\physics\main.cpp

CMakeFiles/oreid.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/oreid.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\timru\Documents\cpp\physics\main.cpp > CMakeFiles\oreid.dir\main.cpp.i

CMakeFiles/oreid.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/oreid.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\timru\Documents\cpp\physics\main.cpp -o CMakeFiles\oreid.dir\main.cpp.s

# Object files for target oreid
oreid_OBJECTS = \
"CMakeFiles/oreid.dir/main.cpp.obj"

# External object files for target oreid
oreid_EXTERNAL_OBJECTS =

oreid.exe: CMakeFiles/oreid.dir/main.cpp.obj
oreid.exe: CMakeFiles/oreid.dir/build.make
oreid.exe: /lib/libraylib.a
oreid.exe: CMakeFiles/oreid.dir/linkLibs.rsp
oreid.exe: CMakeFiles/oreid.dir/objects1.rsp
oreid.exe: CMakeFiles/oreid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\timru\Documents\cpp\physics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable oreid.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\oreid.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oreid.dir/build: oreid.exe
.PHONY : CMakeFiles/oreid.dir/build

CMakeFiles/oreid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\oreid.dir\cmake_clean.cmake
.PHONY : CMakeFiles/oreid.dir/clean

CMakeFiles/oreid.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\timru\Documents\cpp\physics C:\Users\timru\Documents\cpp\physics C:\Users\timru\Documents\cpp\physics\build C:\Users\timru\Documents\cpp\physics\build C:\Users\timru\Documents\cpp\physics\build\CMakeFiles\oreid.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/oreid.dir/depend
