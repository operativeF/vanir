
cmake_minimum_required(VERSION 3.24)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
  boost_tmp
  GIT_REPOSITORY https://github.com/operativeF/tmp.git
  GIT_TAG operativef_dev
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang" AND NOT MSVC)
    set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)
    add_compile_options("-fmodules -stdlib=libc++ -fbuiltin-module-map -fimplicit-module-maps -fprebuilt-module-path=${PREBUILT_MODULE_PATH}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)
endif()

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

if(WIN32)
	# Enable usage of updated __cplusplus macro
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd5050 /utf-8 /D __WIN64__ /D UNICODE /D _UNICODE /Zc:__cplusplus /EHsc /arch:AVX2 /experimental:module /sdl-")	
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(vanir VERSION 1.0)

find_package(Boost REQUIRED COMPONENTS nowide)
find_package(Eigen3 CONFIG REQUIRED)

include_directories(cmake)

add_subdirectory(3rdparty/fmt EXCLUDE_FROM_ALL)

add_subdirectory(benchmark)
add_subdirectory(modules)
add_subdirectory(tests)
