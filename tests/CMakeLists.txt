
add_executable(niltest
    metatest.ixx
    test.cpp
)

target_compile_features(niltest PRIVATE cxx_std_23)

target_link_libraries(niltest
    PRIVATE
        nilbase
        stdlib_module
        fmt::fmt
)
