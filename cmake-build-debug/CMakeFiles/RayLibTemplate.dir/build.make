# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:\CLION PROJECTS\RayLibTemplate"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\CLION PROJECTS\RayLibTemplate\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/RayLibTemplate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RayLibTemplate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RayLibTemplate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayLibTemplate.dir/flags.make

CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj: CMakeFiles/RayLibTemplate.dir/flags.make
CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj: CMakeFiles/RayLibTemplate.dir/includes_CXX.rsp
CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj: ../src/movethings.cpp
CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj: CMakeFiles/RayLibTemplate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\CLION PROJECTS\RayLibTemplate\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj -MF CMakeFiles\RayLibTemplate.dir\src\movethings.cpp.obj.d -o CMakeFiles\RayLibTemplate.dir\src\movethings.cpp.obj -c "H:\CLION PROJECTS\RayLibTemplate\src\movethings.cpp"

CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\CLION PROJECTS\RayLibTemplate\src\movethings.cpp" > CMakeFiles\RayLibTemplate.dir\src\movethings.cpp.i

CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\CLION PROJECTS\RayLibTemplate\src\movethings.cpp" -o CMakeFiles\RayLibTemplate.dir\src\movethings.cpp.s

# Object files for target RayLibTemplate
RayLibTemplate_OBJECTS = \
"CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj"

# External object files for target RayLibTemplate
RayLibTemplate_EXTERNAL_OBJECTS =

RayLibTemplate.exe: CMakeFiles/RayLibTemplate.dir/src/movethings.cpp.obj
RayLibTemplate.exe: CMakeFiles/RayLibTemplate.dir/build.make
RayLibTemplate.exe: libs/raylib/raylib/libraylib.a
RayLibTemplate.exe: libs/raylib/raylib/external/glfw/src/libglfw3.a
RayLibTemplate.exe: CMakeFiles/RayLibTemplate.dir/linklibs.rsp
RayLibTemplate.exe: CMakeFiles/RayLibTemplate.dir/objects1.rsp
RayLibTemplate.exe: CMakeFiles/RayLibTemplate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\CLION PROJECTS\RayLibTemplate\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RayLibTemplate.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RayLibTemplate.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayLibTemplate.dir/build: RayLibTemplate.exe
.PHONY : CMakeFiles/RayLibTemplate.dir/build

CMakeFiles/RayLibTemplate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RayLibTemplate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RayLibTemplate.dir/clean

CMakeFiles/RayLibTemplate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\CLION PROJECTS\RayLibTemplate" "H:\CLION PROJECTS\RayLibTemplate" "H:\CLION PROJECTS\RayLibTemplate\cmake-build-debug" "H:\CLION PROJECTS\RayLibTemplate\cmake-build-debug" "H:\CLION PROJECTS\RayLibTemplate\cmake-build-debug\CMakeFiles\RayLibTemplate.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/RayLibTemplate.dir/depend

