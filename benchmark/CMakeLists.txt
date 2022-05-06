
add_executable(benchmain
    test.cpp
)

target_link_libraries(benchmain
    PRIVATE
        nil_tmp
)
