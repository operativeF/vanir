
cmake_minimum_required(VERSION 3.28)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

FetchContent_Declare(
  boost_tmp
  GIT_REPOSITORY https://github.com/operativeF/tmp.git
  GIT_TAG main
)

# FIXME: Issue with upstream; needs to check for duplications.
# FetchContent_Declare(
#   boost_ext_ut
#   GIT_REPOSITORY https://github.com/boost-ext/ut.git
#   GIT_TAG master
# )

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(vanir VERSION 1.0)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	# Enable usage of updated __cplusplus macro
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd5050 /utf-8 /GR- /D __WIN64__ /D UNICODE /D _UNICODE /Zc:__cplusplus /EHsc")	
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
# To be filled in.
else() # Clang goes here.
# To be filled in.
endif()

include(FetchContent)

FetchContent_MakeAvailable(boost_tmp)

find_package(Eigen3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED) # std::format N/A on GCC yet

include_directories(cmake)

# option(VANIR_ENABLE_BENCHMARK "Build benchmarks of certain important constructs." ON)

# if(VANIR_ENABLE_BENCHMARK)
#     add_subdirectory(benchmark)
# endif()

add_subdirectory(modules)

include(CTest)

add_subdirectory(tests)
