# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default

# Include any dependencies generated for this target.
include tests/gmock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include tests/gmock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/gmock/gtest/CMakeFiles/gtest.dir/flags.make

tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: tests/gmock/gtest/CMakeFiles/gtest.dir/flags.make
tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: /usr/src/gtest/src/gtest-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest && /usr/bin/arm-linux-gnueabihf-g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /usr/src/gtest/src/gtest-all.cc

tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest && /usr/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /usr/src/gtest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest && /usr/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /usr/src/gtest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:
.PHONY : tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f tests/gmock/gtest/CMakeFiles/gtest.dir/build.make tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

tests/gmock/gtest/libgtest.a: tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
tests/gmock/gtest/libgtest.a: tests/gmock/gtest/CMakeFiles/gtest.dir/build.make
tests/gmock/gtest/libgtest.a: tests/gmock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgtest.a"
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/gmock/gtest/CMakeFiles/gtest.dir/build: tests/gmock/gtest/libgtest.a
.PHONY : tests/gmock/gtest/CMakeFiles/gtest.dir/build

tests/gmock/gtest/CMakeFiles/gtest.dir/requires: tests/gmock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
.PHONY : tests/gmock/gtest/CMakeFiles/gtest.dir/requires

tests/gmock/gtest/CMakeFiles/gtest.dir/clean:
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : tests/gmock/gtest/CMakeFiles/gtest.dir/clean

tests/gmock/gtest/CMakeFiles/gtest.dir/depend:
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope /usr/src/gtest /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/gmock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/gmock/gtest/CMakeFiles/gtest.dir/depend

