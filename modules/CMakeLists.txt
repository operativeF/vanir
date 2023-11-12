#  Copyright 2021 Thomas Figueroa.
#  Distributed under the Boost Software License, Version 1.0.
#
#  See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

set(PUPPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pupple)
set(TMP_UNITS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp_units)

set(PUPPLE_IXX
    ${PUPPLE_DIR}/Pupple-Algorithm.ixx
    ${PUPPLE_DIR}/Pupple-Element.ixx
    ${PUPPLE_DIR}/Pupple-Impl.ixx
    # ${PUPPLE_DIR}/new_pupple.ixx
    ${PUPPLE_DIR}/Pupple.ixx
)

set(INTERNAL_UTILITIES_IXX
    ${CMAKE_CURRENT_SOURCE_DIR}/utility/three_way_impl.ixx
)

set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base)
set(ALGO_DIR ${BASE_DIR}/algorithm)

set(BASE_ALGORITHM
    ${BASE_DIR}/bitfield.ixx
    ${ALGO_DIR}/bit_manip.ixx
    # ${BASE_DIR}/ccexpr.ixx
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
    set(WIN_ONLY_INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/unique_hnd.ixx
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/windef.ixx
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/window_styles.ixx
    )
    set(WIN_HEADER_FILES ${CMAKE_SOURCE_DIR}/include/windows/main.h)
endif()

add_library(nilbase
        ${WIN_HEADER_FILES}
)

add_dependencies(nilbase boost_tmp)

target_sources(nilbase
    PUBLIC
    FILE_SET nilbase_modules TYPE CXX_MODULES FILES
    ${PUPPLE_IXX}
    ${BASE_ALGORITHM}
    ${STRING_ALGORITHM}
    # ${WIN_ONLY_INTERFACE}
    ${INTERNAL_UTILITIES_IXX}
)

target_link_libraries(nilbase
    PRIVATE
        boost_tmp
        fmt::fmt
)

add_subdirectory(geometry)
