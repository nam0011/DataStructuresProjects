# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/cygdrive/c/Users/Nathan Moore/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Nathan Moore/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mergeSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mergeSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mergeSort.dir/flags.make

CMakeFiles/mergeSort.dir/main.cpp.o: CMakeFiles/mergeSort.dir/flags.make
CMakeFiles/mergeSort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mergeSort.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mergeSort.dir/main.cpp.o -c "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/main.cpp"

CMakeFiles/mergeSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergeSort.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/main.cpp" > CMakeFiles/mergeSort.dir/main.cpp.i

CMakeFiles/mergeSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergeSort.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/main.cpp" -o CMakeFiles/mergeSort.dir/main.cpp.s

CMakeFiles/mergeSort.dir/player.cpp.o: CMakeFiles/mergeSort.dir/flags.make
CMakeFiles/mergeSort.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mergeSort.dir/player.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mergeSort.dir/player.cpp.o -c "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/player.cpp"

CMakeFiles/mergeSort.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergeSort.dir/player.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/player.cpp" > CMakeFiles/mergeSort.dir/player.cpp.i

CMakeFiles/mergeSort.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergeSort.dir/player.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/player.cpp" -o CMakeFiles/mergeSort.dir/player.cpp.s

CMakeFiles/mergeSort.dir/playerList.cpp.o: CMakeFiles/mergeSort.dir/flags.make
CMakeFiles/mergeSort.dir/playerList.cpp.o: ../playerList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mergeSort.dir/playerList.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mergeSort.dir/playerList.cpp.o -c "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/playerList.cpp"

CMakeFiles/mergeSort.dir/playerList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergeSort.dir/playerList.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/playerList.cpp" > CMakeFiles/mergeSort.dir/playerList.cpp.i

CMakeFiles/mergeSort.dir/playerList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergeSort.dir/playerList.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/playerList.cpp" -o CMakeFiles/mergeSort.dir/playerList.cpp.s

# Object files for target mergeSort
mergeSort_OBJECTS = \
"CMakeFiles/mergeSort.dir/main.cpp.o" \
"CMakeFiles/mergeSort.dir/player.cpp.o" \
"CMakeFiles/mergeSort.dir/playerList.cpp.o"

# External object files for target mergeSort
mergeSort_EXTERNAL_OBJECTS =

mergeSort.exe: CMakeFiles/mergeSort.dir/main.cpp.o
mergeSort.exe: CMakeFiles/mergeSort.dir/player.cpp.o
mergeSort.exe: CMakeFiles/mergeSort.dir/playerList.cpp.o
mergeSort.exe: CMakeFiles/mergeSort.dir/build.make
mergeSort.exe: CMakeFiles/mergeSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mergeSort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mergeSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mergeSort.dir/build: mergeSort.exe

.PHONY : CMakeFiles/mergeSort.dir/build

CMakeFiles/mergeSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mergeSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mergeSort.dir/clean

CMakeFiles/mergeSort.dir/depend:
	cd "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort" "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort" "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug" "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug" "/cygdrive/c/Users/Nathan Moore/Desktop/mergeSort/cmake-build-debug/CMakeFiles/mergeSort.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mergeSort.dir/depend

