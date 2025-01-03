cmake_minimum_required(VERSION 3.28)
project(ReferenceNotes)

set(CMAKE_CXX_STANDARD 98)

# Enable folders for IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(control_flow)
add_subdirectory(data_types)
add_subdirectory(dependency_injection)
add_subdirectory(design_patterns)
add_subdirectory(dynamic_memory)
add_subdirectory(exception_handling)
add_subdirectory(functions)
add_subdirectory(oop)
add_subdirectory(operators)
add_subdirectory(stl)
add_subdirectory(working_with_external_data)

add_custom_target(run_all
        COMMAND ${CMAKE_BINARY_DIR}/control_flow/control_flow_loops
        COMMAND ${CMAKE_BINARY_DIR}/control_flow/if_else_and_switch_statements
        COMMAND ${CMAKE_BINARY_DIR}/control_flow/jump_statements

        COMMAND ${CMAKE_BINARY_DIR}/data_types/comparison_of_common_data_types
        COMMAND ${CMAKE_BINARY_DIR}/data_types/arrays
        COMMAND ${CMAKE_BINARY_DIR}/data_types/casting
        COMMAND ${CMAKE_BINARY_DIR}/data_types/initialization
        COMMAND ${CMAKE_BINARY_DIR}/data_types/pointers_and_references
        COMMAND ${CMAKE_BINARY_DIR}/data_types/strings
        COMMAND ${CMAKE_BINARY_DIR}/data_types/structures

        COMMAND ${CMAKE_BINARY_DIR}/dependency_injection/dependency_injection

        COMMAND ${CMAKE_BINARY_DIR}/design_patterns/strategy_pattern

        COMMAND ${CMAKE_BINARY_DIR}/dynamic_memory/dynamic_memory

        COMMAND ${CMAKE_BINARY_DIR}/exception_handling/exception_handling

        COMMAND ${CMAKE_BINARY_DIR}/functions/functions
        COMMAND ${CMAKE_BINARY_DIR}/functions/template_functions

        COMMAND ${CMAKE_BINARY_DIR}/oop/oop_basics
        COMMAND ${CMAKE_BINARY_DIR}/oop/oop_copy_depth
        COMMAND ${CMAKE_BINARY_DIR}/oop/oop_inheritance
        COMMAND ${CMAKE_BINARY_DIR}/oop/oop_polymorphism
        COMMAND ${CMAKE_BINARY_DIR}/oop/template_classes

        COMMAND ${CMAKE_BINARY_DIR}/operators/operators

        COMMAND ${CMAKE_BINARY_DIR}/stl/modifying_algorithms
        COMMAND ${CMAKE_BINARY_DIR}/stl/non_modifying_algorithms
        COMMAND ${CMAKE_BINARY_DIR}/stl/numeric_algorithms
        COMMAND ${CMAKE_BINARY_DIR}/stl/sorting_algorithms
        COMMAND ${CMAKE_BINARY_DIR}/stl/iterators
        COMMAND ${CMAKE_BINARY_DIR}/stl/lists
        COMMAND ${CMAKE_BINARY_DIR}/stl/maps
        COMMAND ${CMAKE_BINARY_DIR}/stl/queues
        COMMAND ${CMAKE_BINARY_DIR}/stl/sets
        COMMAND ${CMAKE_BINARY_DIR}/stl/stacks
        COMMAND ${CMAKE_BINARY_DIR}/stl/vectors

        COMMAND ${CMAKE_BINARY_DIR}/working_with_external_data/command_line_interface
        COMMAND ${CMAKE_BINARY_DIR}/working_with_external_data/working_with_files
)
