
add_executable(niltest
    metatest.ixx
    test.cpp
)

target_compile_features(niltest PRIVATE cxx_std_23)

target_link_libraries(niltest
    PRIVATE
        nilbase
        Boost::nowide
        stdlib_module

        kernel32
        user32
        comdlg32
        winspool
        shell32
        comctl32
        ole32
        oleaut32
        uuid
        rpcrt4
        advapi32
        wininet
)
