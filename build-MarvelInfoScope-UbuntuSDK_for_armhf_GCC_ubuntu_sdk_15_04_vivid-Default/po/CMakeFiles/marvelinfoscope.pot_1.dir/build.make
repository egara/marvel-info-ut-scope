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

# Utility rule file for marvelinfoscope.pot_1.

# Include the progress variables for this target.
include po/CMakeFiles/marvelinfoscope.pot_1.dir/progress.make

po/CMakeFiles/marvelinfoscope.pot_1: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot

/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/POTFILES.in
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/data/marvelinfoscope.ini.in
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/data/marvelinfoscope-settings.ini.in
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/client.cpp
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/client.h
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/localization.h
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/preview.cpp
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/preview.h
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/query.cpp
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/query.h
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/scope.cpp
/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/scope.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot"
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po && /usr/bin/intltool-update --pot --gettext-package="marvelinfoscope"

marvelinfoscope.pot_1: po/CMakeFiles/marvelinfoscope.pot_1
marvelinfoscope.pot_1: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po/marvelinfoscope.pot
marvelinfoscope.pot_1: po/CMakeFiles/marvelinfoscope.pot_1.dir/build.make
.PHONY : marvelinfoscope.pot_1

# Rule to build all files generated by this target.
po/CMakeFiles/marvelinfoscope.pot_1.dir/build: marvelinfoscope.pot_1
.PHONY : po/CMakeFiles/marvelinfoscope.pot_1.dir/build

po/CMakeFiles/marvelinfoscope.pot_1.dir/clean:
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/po && $(CMAKE_COMMAND) -P CMakeFiles/marvelinfoscope.pot_1.dir/cmake_clean.cmake
.PHONY : po/CMakeFiles/marvelinfoscope.pot_1.dir/clean

po/CMakeFiles/marvelinfoscope.pot_1.dir/depend:
	cd /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/po /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/po /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/po/CMakeFiles/marvelinfoscope.pot_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : po/CMakeFiles/marvelinfoscope.pot_1.dir/depend

