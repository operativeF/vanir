
add_executable(niltest
    metatest/metatest.ixx
    base/algorithm/strutils.cpp
    test.cpp
)

target_compile_features(niltest PRIVATE cxx_std_23)

target_link_libraries(niltest
    PRIVATE
        nilbase
        stdlib_module
        fmt::fmt
)
