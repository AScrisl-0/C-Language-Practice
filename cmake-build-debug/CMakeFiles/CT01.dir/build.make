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
include CMakeFiles/CT01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CT01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CT01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CT01.dir/flags.make

CMakeFiles/CT01.dir/CT01.c.obj: CMakeFiles/CT01.dir/flags.make
CMakeFiles/CT01.dir/CT01.c.obj: ../CT01.c
CMakeFiles/CT01.dir/CT01.c.obj: CMakeFiles/CT01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\CLionProjects\GitHub-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CT01.dir/CT01.c.obj"
	F:\PROGRA~1\MINGW-~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CT01.dir/CT01.c.obj -MF CMakeFiles\CT01.dir\CT01.c.obj.d -o CMakeFiles\CT01.dir\CT01.c.obj -c F:\CLionProjects\GitHub-C\CT01.c

CMakeFiles/CT01.dir/CT01.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CT01.dir/CT01.c.i"
	F:\PROGRA~1\MINGW-~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\CLionProjects\GitHub-C\CT01.c > CMakeFiles\CT01.dir\CT01.c.i

CMakeFiles/CT01.dir/CT01.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CT01.dir/CT01.c.s"
	F:\PROGRA~1\MINGW-~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\CLionProjects\GitHub-C\CT01.c -o CMakeFiles\CT01.dir\CT01.c.s

# Object files for target CT01
CT01_OBJECTS = \
"CMakeFiles/CT01.dir/CT01.c.obj"

# External object files for target CT01
CT01_EXTERNAL_OBJECTS =

CT01.exe: CMakeFiles/CT01.dir/CT01.c.obj
CT01.exe: CMakeFiles/CT01.dir/build.make
CT01.exe: CMakeFiles/CT01.dir/linklibs.rsp
CT01.exe: CMakeFiles/CT01.dir/objects1.rsp
CT01.exe: CMakeFiles/CT01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\CLionProjects\GitHub-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable CT01.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CT01.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CT01.dir/build: CT01.exe
.PHONY : CMakeFiles/CT01.dir/build

CMakeFiles/CT01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CT01.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CT01.dir/clean

CMakeFiles/CT01.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\CLionProjects\GitHub-C F:\CLionProjects\GitHub-C F:\CLionProjects\GitHub-C\cmake-build-debug F:\CLionProjects\GitHub-C\cmake-build-debug F:\CLionProjects\GitHub-C\cmake-build-debug\CMakeFiles\CT01.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CT01.dir/depend

