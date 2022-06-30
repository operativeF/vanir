
set(GEOMETRY_IXX 
    ${CMAKE_CURRENT_SOURCE_DIR}/base/arc.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/circle.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/curve.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/ellipse.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/line.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/point.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/polygon.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/polyline.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/rect.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/base/segment.ixx

    ${CMAKE_CURRENT_SOURCE_DIR}/base/shapes.ixx
    
    ${CMAKE_CURRENT_SOURCE_DIR}/operations/general_op.ixx
    ${CMAKE_CURRENT_SOURCE_DIR}/operations/vector_op.ixx

    ${CMAKE_CURRENT_SOURCE_DIR}/operations/operations.ixx

    ${CMAKE_CURRENT_SOURCE_DIR}/geometry.ixx
)

add_library(VanirGeometry
    STATIC
        ${GEOMETRY_IXX}
)

target_link_libraries(VanirGeometry
    PRIVATE
        fmt::fmt
        Eigen3::Eigen
)
