cmake_minimum_required(VERSION 3.22)
project(ks_33_1_labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(ks_33_1_labs main.cpp
        string_ops.h string_ops.cpp
        my_dyna_struct.cpp my_dyna_struct.h
        )

add_executable(infinite_print
        inf_print/main.cpp
)

add_executable(threading_example
        threading_example/main_simple_example.cpp
)

add_executable(threading_example_v2
        threading_example/main_simple_data_mutating.cpp
)
