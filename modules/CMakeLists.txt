#  Copyright 2021 Thomas Figueroa.
#  Distributed under the Boost Software License, Version 1.0.
#
#  See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

set(TMP_ALGO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp/algorithm)
set(TMP_DETAIL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp/detail)
set(TMP_FUSION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp/fusion)
set(TMP_SEQ_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp/sequence)
set(TMP_MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp)
set(PUPPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pupple)
set(TMP_UNITS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp_units)

set(TMP_ALGO_IXX
    ${TMP_ALGO_DIR}/all_of.ixx
    ${TMP_ALGO_DIR}/any_of.ixx
    ${TMP_ALGO_DIR}/clamp.ixx
    ${TMP_ALGO_DIR}/contains.ixx
    ${TMP_ALGO_DIR}/count_if.ixx
    ${TMP_ALGO_DIR}/extrema.ixx
    ${TMP_ALGO_DIR}/filter.ixx
    ${TMP_ALGO_DIR}/find_if.ixx
    ${TMP_ALGO_DIR}/flatten.ixx
    ${TMP_ALGO_DIR}/fold_left.ixx
    ${TMP_ALGO_DIR}/fold_right.ixx
    ${TMP_ALGO_DIR}/gather.ixx
    ${TMP_ALGO_DIR}/none_of.ixx
    ${TMP_ALGO_DIR}/pairing.ixx
    ${TMP_ALGO_DIR}/product.ixx
    ${TMP_ALGO_DIR}/range_math.ixx
    ${TMP_ALGO_DIR}/remove_if.ixx
    ${TMP_ALGO_DIR}/remove_pairs.ixx
    ${TMP_ALGO_DIR}/sort.ixx
    ${TMP_ALGO_DIR}/transform.ixx
    ${TMP_ALGO_DIR}/tmp_algorithm.ixx
)

set(TMP_MAIN_IXX
    ${TMP_MAIN_DIR}/always.ixx
    ${TMP_MAIN_DIR}/call.ixx
    ${TMP_MAIN_DIR}/comparison.ixx
    ${TMP_MAIN_DIR}/decay.ixx
    ${TMP_MAIN_DIR}/fusion.ixx
    ${TMP_MAIN_DIR}/identity.ixx
    ${TMP_MAIN_DIR}/if.ixx
    ${TMP_MAIN_DIR}/lift.ixx
    ${TMP_MAIN_DIR}/logic.ixx
    ${TMP_MAIN_DIR}/pack.ixx
    ${TMP_MAIN_DIR}/tmp_base.ixx
    ${TMP_MAIN_DIR}/try.ixx
    ${TMP_MAIN_DIR}/vocabulary.ixx
)

set(TMP_DETAIL_IXX
    ${TMP_DETAIL_DIR}/detail.ixx
    ${TMP_DETAIL_DIR}/dispatch.ixx
)

set(TMP_SEQ_IXX
    ${TMP_SEQ_DIR}/container.ixx
    ${TMP_SEQ_DIR}/drop.ixx
    ${TMP_SEQ_DIR}/each.ixx
    ${TMP_SEQ_DIR}/erase.ixx
    ${TMP_SEQ_DIR}/index.ixx
    ${TMP_SEQ_DIR}/insert.ixx
    ${TMP_SEQ_DIR}/join.ixx
    ${TMP_SEQ_DIR}/make_sequence.ixx
    ${TMP_SEQ_DIR}/pop_back.ixx
    ${TMP_SEQ_DIR}/pop_front.ixx
    ${TMP_SEQ_DIR}/push_back.ixx
    ${TMP_SEQ_DIR}/push_front.ixx
    ${TMP_SEQ_DIR}/reverse.ixx
    ${TMP_SEQ_DIR}/rotate.ixx
    ${TMP_SEQ_DIR}/sequence.ixx
    ${TMP_SEQ_DIR}/set.ixx
    ${TMP_SEQ_DIR}/size.ixx
    ${TMP_SEQ_DIR}/swap.ixx
    ${TMP_SEQ_DIR}/take.ixx
    ${TMP_SEQ_DIR}/tee.ixx
    ${TMP_SEQ_DIR}/unpack.ixx
    ${TMP_SEQ_DIR}/zip_with_index.ixx
    ${TMP_SEQ_DIR}/zip.ixx
)

set(PUPPLE_IXX
    ${PUPPLE_DIR}/meta_element.ixx
    # ${PUPPLE_DIR}/meta_map.ixx
    ${PUPPLE_DIR}/pupple.ixx
    ${PUPPLE_DIR}/pupple_algorithm.ixx
)

set(TMP_BASE_IXX
    ${CMAKE_CURRENT_SOURCE_DIR}/tmp.ixx
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(tmp_module IN LISTS ${TMP_ALGO_IXX} ${TMP_MAIN_IXX} ${TMP_DETAIL_IXX} ${TMP_SEQ_IXX} ${PUPPLE_IXX} ${TMP_BASE_IXX})
        string(REGEX REPLACE "\/(.+)\.ixx" "\\1" module_file_name ${tmp_module})
        add_module(${module_file_name} ${tmp_module})
    endforeach()
endif()

add_library(nil_tmp
    STATIC
        ${TMP_ALGO_IXX}
        ${TMP_MAIN_IXX}
        ${TMP_DETAIL_IXX}
        ${TMP_SEQ_IXX}
        ${PUPPLE_IXX}
        ${TMP_BASE_IXX}
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(mod_name IN LISTS ${TMP_ALGO_IXX} ${TMP_MAIN_IXX} ${TMP_DETAIL_IXX} ${TMP_SEQ_IXX} ${PUPPLE_IXX} ${TMP_BASE_IXX})
        string(REGEX REPLACE "\/([A-z_]+)\.ixx" "\\1" module_without_ext ${mod_name})
        string(APPEND module_without_ext ".pcm")
        add_dependencies(nil_tmp ${module_without_ext})
    endforeach()
endif()

set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base)
set(ALGO_DIR ${BASE_DIR}/algorithm)

set(BASE_ALGORITHM
    ${BASE_DIR}/bitfield.ixx
    ${ALGO_DIR}/bit_manip.ixx
    ${ALGO_DIR}/charutils.ixx
    ${BASE_DIR}/static_vector.ixx
    ${ALGO_DIR}/stringutils.ixx
)

set(STRING_ALGORITHM
    ${ALGO_DIR}/strings/modifying.ixx
    ${ALGO_DIR}/strings/nonmodifying.ixx
    ${ALGO_DIR}/strings/unsafe.ixx
)

if(MSVC)
    set(WIN_IXX
        ${CMAKE_CURRENT_SOURCE_DIR}/win/unique_hnd.ixx
        ${CMAKE_CURRENT_SOURCE_DIR}/win/windef.ixx
        ${CMAKE_CURRENT_SOURCE_DIR}/win/window_styles.ixx
    )
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(algo_mod IN LISTS ${BASE_ALGORITHM} ${STRING_ALGORITHM})
        string(REGEX REPLACE "\/([A-z_]+)\.ixx" "\\1" algo_module_name ${algo_mod})
        add_module(${algo_module_name} ${algo_mod})
    endforeach()
endif()

add_library(nilbase
        ${BASE_ALGORITHM}
        ${STRING_ALGORITHM}
        ${WIN_IXX}
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(algo_mod IN LISTS ${BASE_ALGORITHM} ${STRING_ALGORITHM})
        string(REGEX REPLACE "\/([A-z_]+)\.ixx" "\\1" algo_module_name ${algo_mod})
        string(APPEND algo_module_name ".pcm")
        add_dependencies(nilbase ${algo_module_name})
    endforeach()
endif()

target_link_libraries(nilbase
    PRIVATE
        nil_tmp
        fmt::fmt
)

set(TMP_UNITS_ENGINE_IXX
    ${TMP_UNITS_DIR}/engine/base.ixx
    ${TMP_UNITS_DIR}/engine/conversions.ixx
    ${TMP_UNITS_DIR}/engine/evaluators.ixx
    ${TMP_UNITS_DIR}/engine/forward_types.ixx
    ${TMP_UNITS_DIR}/engine/type_dispatcher.ixx
)

set(TMP_UNITS_IXX
    ${TMP_UNITS_DIR}/units/anything.ixx
)

add_library(tmp_units_lib
    STATIC
        ${TMP_UNITS_ENGINE_IXX}
        ${TMP_UNITS_IXX}
)

target_link_libraries(tmp_units_lib
    PRIVATE
        nil_tmp
)
