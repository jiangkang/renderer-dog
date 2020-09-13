# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/T5/CppPractice/renderer-dog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/T5/CppPractice/renderer-dog

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.17.3/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Volumes/T5/CppPractice/renderer-dog/CMakeFiles /Volumes/T5/CppPractice/renderer-dog/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Volumes/T5/CppPractice/renderer-dog/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named renderer-dog

# Build rule for target.
renderer-dog: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 renderer-dog
.PHONY : renderer-dog

# fast build rule for target.
renderer-dog/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/build
.PHONY : renderer-dog/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/main.cpp.s
.PHONY : main.cpp.s

src/demo_sdl.o: src/demo_sdl.cpp.o

.PHONY : src/demo_sdl.o

# target to build an object file
src/demo_sdl.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/src/demo_sdl.cpp.o
.PHONY : src/demo_sdl.cpp.o

src/demo_sdl.i: src/demo_sdl.cpp.i

.PHONY : src/demo_sdl.i

# target to preprocess a source file
src/demo_sdl.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/src/demo_sdl.cpp.i
.PHONY : src/demo_sdl.cpp.i

src/demo_sdl.s: src/demo_sdl.cpp.s

.PHONY : src/demo_sdl.s

# target to generate assembly for a file
src/demo_sdl.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/src/demo_sdl.cpp.s
.PHONY : src/demo_sdl.cpp.s

src/renderer.o: src/renderer.cpp.o

.PHONY : src/renderer.o

# target to build an object file
src/renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/src/renderer.cpp.o
.PHONY : src/renderer.cpp.o

src/renderer.i: src/renderer.cpp.i

.PHONY : src/renderer.i

# target to preprocess a source file
src/renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/src/renderer.cpp.i
.PHONY : src/renderer.cpp.i

src/renderer.s: src/renderer.cpp.s

.PHONY : src/renderer.s

# target to generate assembly for a file
src/renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/renderer-dog.dir/build.make CMakeFiles/renderer-dog.dir/src/renderer.cpp.s
.PHONY : src/renderer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... renderer-dog"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/demo_sdl.o"
	@echo "... src/demo_sdl.i"
	@echo "... src/demo_sdl.s"
	@echo "... src/renderer.o"
	@echo "... src/renderer.i"
	@echo "... src/renderer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

