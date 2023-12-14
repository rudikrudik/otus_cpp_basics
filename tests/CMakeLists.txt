# 'Google_test' is the subproject name
project(google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(containers_tests
        SerialContainer_tests.cpp
        SinglyLinkedList_tests.cpp
        DoubleLinkList_tests.cpp
        SerialContainerMemReserve_tests.cpp)

add_executable(
        serial_container
        SerialContainer_tests.cpp
)

add_executable(
        serial_containerMR
        SerialContainerMemReserve_tests.cpp
)

add_executable(
        singly_linked_container
        SinglyLinkedList_tests.cpp
)

add_executable(
        double_link_container
        DoubleLinkList_tests.cpp
)

target_link_libraries(containers_tests gtest gtest_main)
target_link_libraries(serial_container gtest gtest_main)
target_link_libraries(serial_containerMR gtest gtest_main)
target_link_libraries(singly_linked_container gtest gtest_main)
target_link_libraries(double_link_container gtest gtest_main)