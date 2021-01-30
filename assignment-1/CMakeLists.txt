cmake_minimum_required(VERSION 3.17.5)
project(assignment1p1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

#add_library(some_mex_module part1.cpp)
#add_executable(assignment1p2 part2.cpp)
include(FindMatlab)
matlab_get_version_from_release_name("R2020a" Matlab_VERSION)
find_package(Matlab)

#target_link_libraries(assignment1p1 ${Matlab_ROOT_DIR}/extern/include/mex.hpp)

message(STATUS ${Matlab_INCLUDE_DIRS})

include_directories(${Matlab_INCLUDE_DIRS})

#matlab_add_mex(NAME some_mex_module SRC part1.cpp)

matlab_add_mex(
        NAME part1
        SRC "${CMAKE_CURRENT_SOURCE_DIR}/part1.cpp"

)

set_target_properties(
        part1
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
