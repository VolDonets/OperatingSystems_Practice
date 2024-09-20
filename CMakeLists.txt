cmake_minimum_required(VERSION 3.22)
project(ks_33_1_labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(ks_33_1_labs main.cpp
        string_ops.h string_ops.cpp
        my_dyna_struct.cpp my_dyna_struct.h
        )
