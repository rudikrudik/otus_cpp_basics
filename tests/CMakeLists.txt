# 'Google_test' is the subproject name
project(google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(containers_tests
        SerialContainer_tests.cpp
        SinglyLinkedList_tests.cpp)

target_link_libraries(containers_tests gtest gtest_main)