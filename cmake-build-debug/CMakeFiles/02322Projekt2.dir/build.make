# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\blued\Documents\Github repos\02322Projekt2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\blued\Documents\Github repos\02322Projekt2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/02322Projekt2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/02322Projekt2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/02322Projekt2.dir/flags.make

CMakeFiles/02322Projekt2.dir/Main.c.obj: CMakeFiles/02322Projekt2.dir/flags.make
CMakeFiles/02322Projekt2.dir/Main.c.obj: ../Main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\blued\Documents\Github repos\02322Projekt2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/02322Projekt2.dir/Main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\02322Projekt2.dir\Main.c.obj   -c "C:\Users\blued\Documents\Github repos\02322Projekt2\Main.c"

CMakeFiles/02322Projekt2.dir/Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/02322Projekt2.dir/Main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\blued\Documents\Github repos\02322Projekt2\Main.c" > CMakeFiles\02322Projekt2.dir\Main.c.i

CMakeFiles/02322Projekt2.dir/Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/02322Projekt2.dir/Main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\blued\Documents\Github repos\02322Projekt2\Main.c" -o CMakeFiles\02322Projekt2.dir\Main.c.s

# Object files for target 02322Projekt2
02322Projekt2_OBJECTS = \
"CMakeFiles/02322Projekt2.dir/Main.c.obj"

# External object files for target 02322Projekt2
02322Projekt2_EXTERNAL_OBJECTS =

02322Projekt2.exe: CMakeFiles/02322Projekt2.dir/Main.c.obj
02322Projekt2.exe: CMakeFiles/02322Projekt2.dir/build.make
02322Projekt2.exe: CMakeFiles/02322Projekt2.dir/linklibs.rsp
02322Projekt2.exe: CMakeFiles/02322Projekt2.dir/objects1.rsp
02322Projekt2.exe: CMakeFiles/02322Projekt2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\blued\Documents\Github repos\02322Projekt2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 02322Projekt2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\02322Projekt2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/02322Projekt2.dir/build: 02322Projekt2.exe

.PHONY : CMakeFiles/02322Projekt2.dir/build

CMakeFiles/02322Projekt2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\02322Projekt2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/02322Projekt2.dir/clean

CMakeFiles/02322Projekt2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\blued\Documents\Github repos\02322Projekt2" "C:\Users\blued\Documents\Github repos\02322Projekt2" "C:\Users\blued\Documents\Github repos\02322Projekt2\cmake-build-debug" "C:\Users\blued\Documents\Github repos\02322Projekt2\cmake-build-debug" "C:\Users\blued\Documents\Github repos\02322Projekt2\cmake-build-debug\CMakeFiles\02322Projekt2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/02322Projekt2.dir/depend

