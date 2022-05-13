cmake_minimum_required(VERSION 3.5)

project(lab_5_6_BENCHMARK)

set(MAIN_BENCHMARK_TEST graph_fun_benchmark.h graph_fun_benchmark.cpp)

include(FetchContent)

FetchContent_Declare(
        googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.6.1
)

FetchContent_MakeAvailable(googlebenchmark)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

add_executable(${PROJECT_NAME} ${MAIN_BENCHMARK_TEST})

#set(BENCHMARK_FORMAT json)

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        BENCHMARK_OUT_FORMAT json
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../function_graph
)

target_link_libraries(
        ${PROJECT_NAME}
        benchmark_main
        benchmark
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Werror -Wall -Wimplicit-fallthrough -pedantic-errors
            )
endif()


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_HOME_DIRECTORY}/lab_5_6/benchmark)
install(FILES ${MAIN_BENCHMARK_TEST} DESTINATION ${CMAKE_HOME_DIRECTORY}/lab_5_6/benchmark )

#set(CPACK_GENERATOR "DEB")
#include(CPack)




