
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base)
set(ALGO_DIR ${BASE_DIR}/algorithm)

set(BASE_ALGORITHM
    ${BASE_DIR}/bitfield.ixx

    ${ALGO_DIR}/charutils.ixx
    ${ALGO_DIR}/stringutils.ixx
)

set(STRING_ALGORITHM
    ${ALGO_DIR}/strings/modifying.ixx
    ${ALGO_DIR}/strings/nonmodifying.ixx
    ${ALGO_DIR}/strings/unsafe.ixx
)

add_library(stdlib_module
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/stdlib/stdlib.ixx
)

add_library(nilbase
    STATIC
        ${BASE_ALGORITHM}
        ${STRING_ALGORITHM}
)

target_link_libraries(nilbase
    PRIVATE
        boost_tmp
        fmt::fmt
        Boost::nowide
        stdlib_module
)
