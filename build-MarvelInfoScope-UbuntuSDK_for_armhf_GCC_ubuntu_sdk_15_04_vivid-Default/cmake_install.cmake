# Install script for directory: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "//manifest.json")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/" TYPE FILE FILES "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/manifest.json")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "//marvelinfoscope.apparmor")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/" TYPE FILE FILES "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/marvelinfoscope.apparmor")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/po/cmake_install.cmake")
  include("/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/src/cmake_install.cmake")
  include("/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
