cmake_minimum_required(VERSION 3.8)

project(task5_polimor)

add_executable(task5_polimor
        main.cpp
        )

set_target_properties(task5_polimor PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

if (MSVC)
    target_compile_options(task5_polimor PUBLIC /W4 /WX)
else()
    target_compile_options(task5_polimor PUBLIC -Wall -Wextra -Werror -pedantic)
endif()


