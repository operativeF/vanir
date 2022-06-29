

add_executable(WindowsTests
    main_test.ixx
)

target_link_libraries(WindowsTests
    PRIVATE
        nilbase
        MetaTestLib
)

target_link_options(WindowsTests
    PRIVATE
        "/SUBSYSTEM:WINDOWS"
)
