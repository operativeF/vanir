
# Part of FIXME in main cmakelist
# FetchContent_MakeAvailable(boost_ext_ut)

set(PUPPLE_TESTS
    pupple/pupple_test.cpp
    pupple/pupple_algorithm_test.cpp
)

add_executable(niltest
    # base/algorithm/strutils.cpp
    base/bitfieldtest.cpp
    test.cpp
    ${PUPPLE_TESTS}
)

target_sources(niltest
    PUBLIC
    FILE_SET niltest_modules TYPE CXX_MODULES FILES
    ${CMAKE_CURRENT_LIST_DIR}/ut.ixx
)

target_compile_features(niltest PRIVATE cxx_std_23)

add_test(NAME niltest COMMAND niltest)

target_link_libraries(niltest
    PRIVATE
        nilbase

)
