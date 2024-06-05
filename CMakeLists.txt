cmake_minimum_required(VERSION 3.24)
project(monty_hall)

set(CMAKE_CXX_STANDARD 23)

# Set compiler flags for optimization
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # General optimization flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -mtune=native")

    # Link-time optimization
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")

    # Additional flags to potentially improve performance
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -funroll-loops -fstrict-aliasing")
endif ()

add_executable(monty_hall cpp/main.cpp)

set_target_properties(monty_hall PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)