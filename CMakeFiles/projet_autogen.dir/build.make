# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/etud/Bureau/InterfaceGraphique/projetTaquin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/etud/Bureau/InterfaceGraphique/projetTaquin

# Utility rule file for projet_autogen.

# Include the progress variables for this target.
include CMakeFiles/projet_autogen.dir/progress.make

CMakeFiles/projet_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/etud/Bureau/InterfaceGraphique/projetTaquin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target projet"
	/usr/bin/cmake -E cmake_autogen /home/etud/Bureau/InterfaceGraphique/projetTaquin/CMakeFiles/projet_autogen.dir/AutogenInfo.json Debug

projet_autogen: CMakeFiles/projet_autogen
projet_autogen: CMakeFiles/projet_autogen.dir/build.make

.PHONY : projet_autogen

# Rule to build all files generated by this target.
CMakeFiles/projet_autogen.dir/build: projet_autogen

.PHONY : CMakeFiles/projet_autogen.dir/build

CMakeFiles/projet_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projet_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projet_autogen.dir/clean

CMakeFiles/projet_autogen.dir/depend:
	cd /home/etud/Bureau/InterfaceGraphique/projetTaquin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/etud/Bureau/InterfaceGraphique/projetTaquin /home/etud/Bureau/InterfaceGraphique/projetTaquin /home/etud/Bureau/InterfaceGraphique/projetTaquin /home/etud/Bureau/InterfaceGraphique/projetTaquin /home/etud/Bureau/InterfaceGraphique/projetTaquin/CMakeFiles/projet_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projet_autogen.dir/depend

