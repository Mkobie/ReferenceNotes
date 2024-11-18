cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 98)

add_executable(comparison_of_common_data_types comparison_of_common_data_types/comparison_of_common_data_types.cpp
        comparison_of_common_data_types/_helper.cpp
        comparison_of_common_data_types/_helper.h
)
add_executable(arrays arrays.cpp)
add_executable(casting casting.cpp)
add_executable(initialization initialization.cpp)
add_executable(pointers_and_references pointers_and_references.cpp)
add_executable(strings strings.cpp)
add_executable(structures structures.cpp)
