cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 98)

add_executable(modifying_algorithms algorithms/modifying_algorithms.cpp)
add_executable(non_modifying_algorithms algorithms/non_modifying_algorithms.cpp)
add_executable(numeric_algorithms algorithms/numeric_algorithms.cpp)
add_executable(sorting_algorithms algorithms/sorting_algorithms.cpp)

add_executable(iterators containers_and_data_structures/iterators.cpp)
add_executable(lists containers_and_data_structures/lists.cpp)
add_executable(maps containers_and_data_structures/maps.cpp)
add_executable(queues containers_and_data_structures/queues.cpp)
add_executable(sets containers_and_data_structures/sets.cpp)
add_executable(stacks containers_and_data_structures/stacks.cpp)
add_executable(vectors containers_and_data_structures/vectors.cpp)

