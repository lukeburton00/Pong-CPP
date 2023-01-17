# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/luke/Desktop/Pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/luke/Desktop/Pong

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.25.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.25.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/luke/Desktop/Pong/CMakeFiles /Users/luke/Desktop/Pong//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/luke/Desktop/Pong/CMakeFiles 0
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
# Target rules for targets named Main

# Build rule for target.
Main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Main
.PHONY : Main

# fast build rule for target.
Main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/build
.PHONY : Main/fast

src/Game/game.o: src/Game/game.cpp.o
.PHONY : src/Game/game.o

# target to build an object file
src/Game/game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Game/game.cpp.o
.PHONY : src/Game/game.cpp.o

src/Game/game.i: src/Game/game.cpp.i
.PHONY : src/Game/game.i

# target to preprocess a source file
src/Game/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Game/game.cpp.i
.PHONY : src/Game/game.cpp.i

src/Game/game.s: src/Game/game.cpp.s
.PHONY : src/Game/game.s

# target to generate assembly for a file
src/Game/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Game/game.cpp.s
.PHONY : src/Game/game.cpp.s

src/GameObject/GameObject.o: src/GameObject/GameObject.cpp.o
.PHONY : src/GameObject/GameObject.o

# target to build an object file
src/GameObject/GameObject.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/GameObject/GameObject.cpp.o
.PHONY : src/GameObject/GameObject.cpp.o

src/GameObject/GameObject.i: src/GameObject/GameObject.cpp.i
.PHONY : src/GameObject/GameObject.i

# target to preprocess a source file
src/GameObject/GameObject.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/GameObject/GameObject.cpp.i
.PHONY : src/GameObject/GameObject.cpp.i

src/GameObject/GameObject.s: src/GameObject/GameObject.cpp.s
.PHONY : src/GameObject/GameObject.s

# target to generate assembly for a file
src/GameObject/GameObject.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/GameObject/GameObject.cpp.s
.PHONY : src/GameObject/GameObject.cpp.s

src/Graphics/Shader/Shader.o: src/Graphics/Shader/Shader.cpp.o
.PHONY : src/Graphics/Shader/Shader.o

# target to build an object file
src/Graphics/Shader/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Graphics/Shader/Shader.cpp.o
.PHONY : src/Graphics/Shader/Shader.cpp.o

src/Graphics/Shader/Shader.i: src/Graphics/Shader/Shader.cpp.i
.PHONY : src/Graphics/Shader/Shader.i

# target to preprocess a source file
src/Graphics/Shader/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Graphics/Shader/Shader.cpp.i
.PHONY : src/Graphics/Shader/Shader.cpp.i

src/Graphics/Shader/Shader.s: src/Graphics/Shader/Shader.cpp.s
.PHONY : src/Graphics/Shader/Shader.s

# target to generate assembly for a file
src/Graphics/Shader/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Graphics/Shader/Shader.cpp.s
.PHONY : src/Graphics/Shader/Shader.cpp.s

src/Input/Input.o: src/Input/Input.cpp.o
.PHONY : src/Input/Input.o

# target to build an object file
src/Input/Input.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Input/Input.cpp.o
.PHONY : src/Input/Input.cpp.o

src/Input/Input.i: src/Input/Input.cpp.i
.PHONY : src/Input/Input.i

# target to preprocess a source file
src/Input/Input.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Input/Input.cpp.i
.PHONY : src/Input/Input.cpp.i

src/Input/Input.s: src/Input/Input.cpp.s
.PHONY : src/Input/Input.s

# target to generate assembly for a file
src/Input/Input.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Input/Input.cpp.s
.PHONY : src/Input/Input.cpp.s

src/Time/Time.o: src/Time/Time.cpp.o
.PHONY : src/Time/Time.o

# target to build an object file
src/Time/Time.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Time/Time.cpp.o
.PHONY : src/Time/Time.cpp.o

src/Time/Time.i: src/Time/Time.cpp.i
.PHONY : src/Time/Time.i

# target to preprocess a source file
src/Time/Time.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Time/Time.cpp.i
.PHONY : src/Time/Time.cpp.i

src/Time/Time.s: src/Time/Time.cpp.s
.PHONY : src/Time/Time.s

# target to generate assembly for a file
src/Time/Time.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Time/Time.cpp.s
.PHONY : src/Time/Time.cpp.s

src/Window/Window.o: src/Window/Window.cpp.o
.PHONY : src/Window/Window.o

# target to build an object file
src/Window/Window.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Window/Window.cpp.o
.PHONY : src/Window/Window.cpp.o

src/Window/Window.i: src/Window/Window.cpp.i
.PHONY : src/Window/Window.i

# target to preprocess a source file
src/Window/Window.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Window/Window.cpp.i
.PHONY : src/Window/Window.cpp.i

src/Window/Window.s: src/Window/Window.cpp.s
.PHONY : src/Window/Window.s

# target to generate assembly for a file
src/Window/Window.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Window/Window.cpp.s
.PHONY : src/Window/Window.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Main"
	@echo "... src/Game/game.o"
	@echo "... src/Game/game.i"
	@echo "... src/Game/game.s"
	@echo "... src/GameObject/GameObject.o"
	@echo "... src/GameObject/GameObject.i"
	@echo "... src/GameObject/GameObject.s"
	@echo "... src/Graphics/Shader/Shader.o"
	@echo "... src/Graphics/Shader/Shader.i"
	@echo "... src/Graphics/Shader/Shader.s"
	@echo "... src/Input/Input.o"
	@echo "... src/Input/Input.i"
	@echo "... src/Input/Input.s"
	@echo "... src/Time/Time.o"
	@echo "... src/Time/Time.i"
	@echo "... src/Time/Time.s"
	@echo "... src/Window/Window.o"
	@echo "... src/Window/Window.i"
	@echo "... src/Window/Window.s"
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

