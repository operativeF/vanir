#############################################################################
# Name:        CMakeLists.txt
# Purpose:     Primary CMake for wxWidgets
# Author:      Tobias Taschner
# Created:     2016-09-20
# Copyright:   (c) 2016 wxWidgets development team
# Licence:     wxWindows licence
#############################################################################

cmake_minimum_required(VERSION 3.11)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

if(WIN32)
	# Enable usage of updated __cplusplus macro
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D __WIN64__ /D UNICODE /D _UNICODE /Zc:__cplusplus /EHsc /arch:AVX2")	
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_SYSROOT_FLAG_CODE "list(APPEND CMAKE_CXX_SOURCE_FILE_EXTENSIONS ixx)")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(vanir VERSION 1.0)

find_package(Boost REQUIRED COMPONENTS nowide)

add_subdirectory(3rdparty/fmt EXCLUDE_FROM_ALL)

add_subdirectory(modules)
add_subdirectory(tests)
