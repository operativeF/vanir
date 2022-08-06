
set(PUPPLE_TESTS
    pupple/pupple_test.cpp
    pupple/pupple_algorithm_test.cpp
)

add_library(MetaTestLib)

target_sources(MetaTestLib
    PUBLIC
    FILE_SET boost_tmp_modules TYPE CXX_MODULES FILES
    metatest/metatest.ixx
)

target_link_libraries(MetaTestLib
    PRIVATE
        fmt::fmt
        nilbase
)

if(MSVC)
    target_compile_options(MetaTestLib PUBLIC /reference std=C:/dev/STL/std.ifc)
endif()

add_executable(niltest
    # base/algorithm/strutils.cpp
    base/bitfieldtest.cpp
    test.cpp
    ${PUPPLE_TESTS}
)

target_compile_features(niltest PRIVATE cxx_std_23)

add_test(NAME niltest COMMAND niltest)

target_link_libraries(niltest
    PRIVATE
        nilbase
        fmt::fmt
        MetaTestLib
)

target_link_directories(niltest PRIVATE C:/dev/STL/out/x64/out/lib/amd64)
