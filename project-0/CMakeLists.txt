cmake_minimum_required(VERSION 3.17.5)
project(assignment1p1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(Matlab_ROOT_DIR /usr/local/MATLAB/R2020b)
include(FindMatlab)
matlab_get_version_from_release_name("R2020b" Matlab_VERSION)

find_package(Matlab)
include_directories(${Matlab_INCLUDE_DIRS})

matlab_add_mex(
        NAME part1
        SRC "${CMAKE_CURRENT_SOURCE_DIR}/part1.cpp"

)

set_target_properties(
        part1
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
