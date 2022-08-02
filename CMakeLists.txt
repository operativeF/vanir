
cmake_minimum_required(VERSION 3.24)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
  boost_tmp
  GIT_REPOSITORY https://github.com/operativeF/tmp.git
  GIT_TAG operativef_dev
)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(vanir VERSION 1.0)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 3c375311-a3c9-4396-a187-3227ef642046)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	# Enable usage of updated __cplusplus macro
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd5050 /utf-8 /GR- /D __WIN64__ /D UNICODE /D _UNICODE /Zc:__cplusplus /EHsc")	
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

  string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
    "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> <SOURCE> -nologo -TP"
    " -showIncludes"
    " -scanDependencies <DYNDEP_FILE>"
    " -Fo<OBJECT>"
    )
  
  set(CMAKE_EXPERIMENTAL_CXX_SCANDEP_DEPFILE_FORMAT "msvc")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "msvc")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "@<MODULE_MAP_FILE>")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
    "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -E -x c++ <SOURCE>"
    " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
    " -fmodules-ts -fdep-file=<DYNDEP_FILE> -fdep-output=<OBJECT> -fdep-format=trtbd"
    " -o <PREPROCESSED_SOURCE>")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "-fmodules-ts -fmodule-mapper=<MODULE_MAP_FILE> -fdep-format=trtbd -x c++")
else() # TODO: Clang goes here.
  string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
  "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -E -x c++ <SOURCE>"
  " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
  " -fmodules-ts -fdep-file=<DYNDEP_FILE> -fdep-output=<OBJECT> -fdep-format=trtbd"
  " -o <PREPROCESSED_SOURCE>")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "-fmodules-ts -fmodule-mapper=<MODULE_MAP_FILE> -fdep-format=trtbd -x c++")
endif()

find_package(Boost REQUIRED COMPONENTS nowide)
find_package(Eigen3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

include_directories(cmake)

# add_subdirectory(3rdparty/fmt EXCLUDE_FROM_ALL)

if(VANIR_ENABLE_BENCHMARK)
    add_subdirectory(benchmark)
endif()

add_subdirectory(modules)

include(CTest)

add_subdirectory(tests)
