set(ux_socket_ut "UX_SOCKET_UT")

add_library(UX_WRAPS ${CMAKE_SOURCE_DIR}/test/mocks/ux_wraps.c)
set_target_properties(UX_WRAPS PROPERTIES COMPILE_FLAGS ${CLANG_COVERAGE_COMPILE_FLAGS})

set(TEST_SRC
        socket_test.cpp
        ux_socket_test.cpp)

add_executable(${ux_socket_ut} ${TEST_SRC})

target_include_directories(${ux_socket_ut} PRIVATE
    ${CMAKE_SOURCE_DIR}/inc/
    ${CMAKE_SOURCE_DIR}/test/mocks/)

target_link_libraries(${ux_socket_ut}
        ${CLANG_COVERAGE_COMPILE_FLAGS}
        gtest
        gmock
        pthread
            -Wl,--wrap=socket
            -Wl,--wrap=close
            -Wl,--wrap=remove
            -Wl,--wrap=bind
            -Wl,--wrap=listen
            -Wl,--wrap=accept
            -Wl,--wrap=connect
        UX_WRAPS
        ${UX_SOCKET} )
set_target_properties(${ux_socket_ut} PROPERTIES COMPILE_FLAGS ${CLANG_COVERAGE_COMPILE_FLAGS})
