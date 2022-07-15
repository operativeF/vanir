
set(PUPPLE_TESTS
    pupple/pupple_test.cpp
    pupple/pupple_algorithm_test.cpp
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    add_module(metatest metatest/metatest.ixx)
endif()

add_library(MetaTestLib
    STATIC
        metatest/metatest.ixx
)

target_link_libraries(MetaTestLib
    PRIVATE
        fmt::fmt
        nil_tmp
        nilbase
)

add_executable(niltest
    # base/algorithm/strutils.cpp
    base/bitfieldtest.cpp
    test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/base/geometry/shapes.cpp
    ${PUPPLE_TESTS}
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    add_dependencies(niltest metatest.pcm)
endif()

target_compile_features(niltest PRIVATE cxx_std_23)

# target_compile_options(niltest PRIVATE "/d1reportTime")

target_link_libraries(niltest
    PRIVATE
        nilbase
        nil_tmp
        VanirGeometry
        Boost::nowide
        fmt::fmt
        MetaTestLib
)

add_executable(tmp_unit_test
    tmp_units/test.cpp
    tmp_units/tmp_unit_test.cpp
    metatest/metatest.ixx
)

target_link_libraries(tmp_unit_test
    PRIVATE
        nilbase
        nil_tmp
        fmt::fmt
        tmp_units_lib
)

if(WIN32)
    add_subdirectory(windows)
endif()

