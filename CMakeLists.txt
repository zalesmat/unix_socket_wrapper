cmake_minimum_required(VERSION 3.10)
project(MZ_UX_SOCKET)

set(CMAKE_CXX_STANDARD 14)

set(CLANG_COVERAGE_COMPILE_FLAGS
    "-fprofile-instr-generate=codecov_data.profraw -fcoverage-mapping")
set(CMAKE_CXX_FLAGS "-g -O0")

set (SRC
        src/socket.cpp
        src/ux_socket.cpp)

set(UX_SOCKET "_mz_uxsocket")
add_library(${UX_SOCKET} ${SRC})
target_include_directories(${UX_SOCKET} PRIVATE
        inc/)
set_target_properties(${UX_SOCKET} PROPERTIES COMPILE_FLAGS ${CLANG_COVERAGE_COMPILE_FLAGS})

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE inc/)
target_link_libraries(${PROJECT_NAME} ${UX_SOCKET})

include(gtest.cmake)
include(gmock.cmake)

add_subdirectory(test)
