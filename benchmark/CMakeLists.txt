
set(BENCHMARKS
    ${CMAKE_CURRENT_SOURCE_DIR}/tuple_benchmark.cpp
)

add_executable(benchmark_tests
    ${BENCHMARKS}
)

target_link_libraries(benchmark_tests
    PRIVATE
        celero
)
