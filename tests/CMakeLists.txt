
set(PUPPLE_TESTS
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

add_executable(tmp_test
    tmp/all_of_test.ixx
    tmp/any_of_test.ixx
    tmp/clamp_test.ixx
    tmp/contains_test.ixx
    tmp/count_if_test.ixx
    tmp/drop_test.ixx
    tmp/each_test.ixx
    tmp/erase_test.ixx
    tmp/extrema_test.ixx
    tmp/filter_test.ixx
    tmp/find_if_test.ixx
    tmp/flatten_test.ixx
    tmp/fold_left_test.ixx
    tmp/fold_right_test.ixx
    tmp/index_test.ixx
    tmp/insert_test.ixx
    tmp/join_test.ixx
    tmp/logic_test.ixx
    tmp/none_of_test.ixx
    tmp/partition_test.ixx
    tmp/pop_front_test.ixx
    tmp/product_test.ixx
    tmp/push_back_test.ixx
    tmp/push_front_test.ixx
    tmp/range_math_test.ixx
    tmp/remove_if_test.ixx
    tmp/repeat_sequence_test.ixx
    tmp/replace_if_test.ixx
    tmp/reverse_test.ixx
    tmp/rotate_test.ixx
    tmp/set_test.ixx
    tmp/size_test.ixx
    tmp/sort_test.ixx
    tmp/swap_test.ixx
    tmp/take_test.ixx
    tmp/tee_test.ixx
    tmp/transform_test.ixx
    
    tmp/tmp_all_tests.ixx
    tmp/test.cpp
)

target_link_libraries(tmp_test
    PRIVATE
        nil_tmp
)
