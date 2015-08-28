# Install script for directory: /home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src

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
   "/marvelinfoscope/marvelinfoscope.egarcia_marvelinfoscope.ini;/marvelinfoscope/marvelinfoscope.egarcia_marvelinfoscope-settings.ini")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/marvelinfoscope" TYPE FILE FILES
    "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/src/marvelinfoscope.egarcia_marvelinfoscope.ini"
    "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/src/marvelinfoscope.egarcia_marvelinfoscope-settings.ini"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/marvelinfoscope/icon.png;/marvelinfoscope/logo.png;/marvelinfoscope/screenshot.png")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/marvelinfoscope" TYPE FILE FILES
    "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/data/icon.png"
    "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/data/logo.png"
    "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/MarvelInfoScope/src/data/screenshot.png"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/marvelinfoscope" TYPE SHARED_LIBRARY FILES "/home/egarcia/Development/UbuntuTouch/marvel-info-ut-scope/build-MarvelInfoScope-UbuntuSDK_for_armhf_GCC_ubuntu_sdk_15_04_vivid-Default/src/libmarvelinfoscope.egarcia_marvelinfoscope.so")
  if(EXISTS "$ENV{DESTDIR}/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/arm-linux-gnueabihf-strip" "$ENV{DESTDIR}/marvelinfoscope/libmarvelinfoscope.egarcia_marvelinfoscope.so")
    endif()
  endif()
endif()

