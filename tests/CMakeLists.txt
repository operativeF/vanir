
set(PUPPLE_TESTS
    pupple/element_test.cpp
    # pupple/map_test.cpp
    pupple/pupple_test.cpp
    pupple/pupple_algorithm_test.cpp
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    add_module(metatest metatest/metatest.ixx)
endif()

add_executable(niltest
    metatest/metatest.ixx
    # base/algorithm/strutils.cpp
    base/bitfieldtest.cpp
    test.cpp
    ${PUPPLE_TESTS}
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    add_dependencies(niltest metatest.pcm)
endif()

target_compile_features(niltest PRIVATE cxx_std_23)

target_link_libraries(niltest
    PRIVATE
        nilbase
        nil_tmp
        Boost::nowide
        fmt::fmt
)
