cmake_minimum_required(VERSION 3.8)

project(06_homework)

add_executable(06_homework
        main.cpp
        SerialContainer.hpp
        SinglyLinkedList.hpp
        SerialContaineriterator.hpp
        SinglyLinkedListiterator.hpp
        DoubleLinkList.hpp)

set_target_properties(06_homework PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

if (MSVC)
    message(STATUS "MSVC DETECTED")
    target_compile_options(06_homework PUBLIC /W4 /WX)
else()
    target_compile_options(06_homework PUBLIC -Wall -Wextra -Werror -pedantic)
endif()