# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "G:\Program Files\JetBrains\CLion 2022.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Program Files\JetBrains\CLion 2022.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\CLionProjects\GitHub-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\CLionProjects\GitHub-C\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/9th.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/9th.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/9th.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/9th.dir/flags.make

CMakeFiles/9th.dir/C_Premium/9th.c.obj: CMakeFiles/9th.dir/flags.make
CMakeFiles/9th.dir/C_Premium/9th.c.obj: ../C_Premium/9th.c
CMakeFiles/9th.dir/C_Premium/9th.c.obj: CMakeFiles/9th.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\CLionProjects\GitHub-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/9th.dir/C_Premium/9th.c.obj"
	F:\PROGRA~1\MINGW-~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/9th.dir/C_Premium/9th.c.obj -MF CMakeFiles\9th.dir\C_Premium\9th.c.obj.d -o CMakeFiles\9th.dir\C_Premium\9th.c.obj -c F:\CLionProjects\GitHub-C\C_Premium\9th.c

CMakeFiles/9th.dir/C_Premium/9th.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/9th.dir/C_Premium/9th.c.i"
	F:\PROGRA~1\MINGW-~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\CLionProjects\GitHub-C\C_Premium\9th.c > CMakeFiles\9th.dir\C_Premium\9th.c.i

CMakeFiles/9th.dir/C_Premium/9th.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/9th.dir/C_Premium/9th.c.s"
	F:\PROGRA~1\MINGW-~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\CLionProjects\GitHub-C\C_Premium\9th.c -o CMakeFiles\9th.dir\C_Premium\9th.c.s

# Object files for target 9th
9th_OBJECTS = \
"CMakeFiles/9th.dir/C_Premium/9th.c.obj"

# External object files for target 9th
9th_EXTERNAL_OBJECTS =

9th.exe: CMakeFiles/9th.dir/C_Premium/9th.c.obj
9th.exe: CMakeFiles/9th.dir/build.make
9th.exe: CMakeFiles/9th.dir/linklibs.rsp
9th.exe: CMakeFiles/9th.dir/objects1.rsp
9th.exe: CMakeFiles/9th.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\CLionProjects\GitHub-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 9th.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\9th.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/9th.dir/build: 9th.exe
.PHONY : CMakeFiles/9th.dir/build

CMakeFiles/9th.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\9th.dir\cmake_clean.cmake
.PHONY : CMakeFiles/9th.dir/clean

CMakeFiles/9th.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\CLionProjects\GitHub-C F:\CLionProjects\GitHub-C F:\CLionProjects\GitHub-C\cmake-build-debug F:\CLionProjects\GitHub-C\cmake-build-debug F:\CLionProjects\GitHub-C\cmake-build-debug\CMakeFiles\9th.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/9th.dir/depend

