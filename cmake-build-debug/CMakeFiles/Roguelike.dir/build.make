# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/alexander/Загрузки/clion-2019.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alexander/Загрузки/clion-2019.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Roguelike.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Roguelike.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Roguelike.dir/flags.make

CMakeFiles/Roguelike.dir/main.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Roguelike.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/main.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/main.cpp

CMakeFiles/Roguelike.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/main.cpp > CMakeFiles/Roguelike.dir/main.cpp.i

CMakeFiles/Roguelike.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/main.cpp -o CMakeFiles/Roguelike.dir/main.cpp.s

CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.o: ../Models/Characters/Knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Knight.cpp

CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Knight.cpp > CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.i

CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Knight.cpp -o CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.s

CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.o: ../Models/Characters/Zombie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Zombie.cpp

CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Zombie.cpp > CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.i

CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Zombie.cpp -o CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.s

CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.o: ../Models/Characters/Dragon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Dragon.cpp

CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Dragon.cpp > CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.i

CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Dragon.cpp -o CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.s

CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.o: ../Models/CharactersLogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/CharactersLogic.cpp

CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/CharactersLogic.cpp > CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.i

CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/CharactersLogic.cpp -o CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.s

CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.o: ../Models/Characters/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Bullet.cpp

CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Bullet.cpp > CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.i

CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Characters/Bullet.cpp -o CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.s

CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.o: ../Models/Settings/Settings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Settings/Settings.cpp

CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Settings/Settings.cpp > CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.i

CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Settings/Settings.cpp -o CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.s

CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.o: ../Models/Windows/PauseMenuWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Windows/PauseMenuWindow.cpp

CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Windows/PauseMenuWindow.cpp > CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.i

CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Windows/PauseMenuWindow.cpp -o CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.s

CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.o: CMakeFiles/Roguelike.dir/flags.make
CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.o: ../Models/Windows/MessageWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.o -c /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Windows/MessageWindow.cpp

CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Windows/MessageWindow.cpp > CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.i

CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/Models/Windows/MessageWindow.cpp -o CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.s

# Object files for target Roguelike
Roguelike_OBJECTS = \
"CMakeFiles/Roguelike.dir/main.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.o" \
"CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.o"

# External object files for target Roguelike
Roguelike_EXTERNAL_OBJECTS =

Roguelike: CMakeFiles/Roguelike.dir/main.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Characters/Knight.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Characters/Zombie.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Characters/Dragon.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/CharactersLogic.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Characters/Bullet.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Settings/Settings.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Windows/PauseMenuWindow.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/Models/Windows/MessageWindow.cpp.o
Roguelike: CMakeFiles/Roguelike.dir/build.make
Roguelike: CMakeFiles/Roguelike.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Roguelike"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Roguelike.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Roguelike.dir/build: Roguelike

.PHONY : CMakeFiles/Roguelike.dir/build

CMakeFiles/Roguelike.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Roguelike.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Roguelike.dir/clean

CMakeFiles/Roguelike.dir/depend:
	cd /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug /home/alexander/Документы/CLionProjects/roguelike-game-ALMikhai/cmake-build-debug/CMakeFiles/Roguelike.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Roguelike.dir/depend
