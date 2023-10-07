cmake_minimum_required(VERSION 3.8)

project(01.hello_world)

add_executable(hello_world 
    hello_world.cpp
    example.cpp
    example.h
        move_me_out.h move_me_out.cpp)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(hello_world PUBLIC /W4 /WX)
else()
    target_compile_options(hello_world PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
