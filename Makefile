# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joao/Downloads/PDI/example_code_02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joao/Downloads/PDI/example_code_02

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/joao/Downloads/PDI/example_code_02/CMakeFiles /home/joao/Downloads/PDI/example_code_02/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/joao/Downloads/PDI/example_code_02/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Asteroids

# Build rule for target.
Asteroids: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Asteroids
.PHONY : Asteroids

# fast build rule for target.
Asteroids/fast:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/build
.PHONY : Asteroids/fast

src/Application.o: src/Application.cpp.o
.PHONY : src/Application.o

# target to build an object file
src/Application.cpp.o:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Application.cpp.o
.PHONY : src/Application.cpp.o

src/Application.i: src/Application.cpp.i
.PHONY : src/Application.i

# target to preprocess a source file
src/Application.cpp.i:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Application.cpp.i
.PHONY : src/Application.cpp.i

src/Application.s: src/Application.cpp.s
.PHONY : src/Application.s

# target to generate assembly for a file
src/Application.cpp.s:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Application.cpp.s
.PHONY : src/Application.cpp.s

src/Objects.o: src/Objects.cpp.o
.PHONY : src/Objects.o

# target to build an object file
src/Objects.cpp.o:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Objects.cpp.o
.PHONY : src/Objects.cpp.o

src/Objects.i: src/Objects.cpp.i
.PHONY : src/Objects.i

# target to preprocess a source file
src/Objects.cpp.i:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Objects.cpp.i
.PHONY : src/Objects.cpp.i

src/Objects.s: src/Objects.cpp.s
.PHONY : src/Objects.s

# target to generate assembly for a file
src/Objects.cpp.s:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Objects.cpp.s
.PHONY : src/Objects.cpp.s

src/Player.o: src/Player.cpp.o
.PHONY : src/Player.o

# target to build an object file
src/Player.cpp.o:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Player.cpp.o
.PHONY : src/Player.cpp.o

src/Player.i: src/Player.cpp.i
.PHONY : src/Player.i

# target to preprocess a source file
src/Player.cpp.i:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Player.cpp.i
.PHONY : src/Player.cpp.i

src/Player.s: src/Player.cpp.s
.PHONY : src/Player.s

# target to generate assembly for a file
src/Player.cpp.s:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/Player.cpp.s
.PHONY : src/Player.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... Asteroids"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... src/Application.o"
	@echo "... src/Application.i"
	@echo "... src/Application.s"
	@echo "... src/Objects.o"
	@echo "... src/Objects.i"
	@echo "... src/Objects.s"
	@echo "... src/Player.o"
	@echo "... src/Player.i"
	@echo "... src/Player.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

