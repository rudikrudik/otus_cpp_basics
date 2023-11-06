cmake_minimum_required(VERSION 3.8)
project(guess_the_number)

set(CMAKE_CXX_STANDARD 17)

add_executable(guess_the_number
        main.cpp
        randomNumber.cpp
        fileIO.cpp
        consoleIO.cpp
        )

set_target_properties(guess_the_number PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

if (MSVC)
    target_compile_options(guess_the_number PUBLIC /W4 /WX)
else()
    target_compile_options(guess_the_number PUBLIC -Wall -Wextra -Werror -pedantic)
endif()