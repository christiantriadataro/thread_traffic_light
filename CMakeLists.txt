cmake_minimum_required(VERSION 3.30)
project(traffic_light)


set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILE main.cpp)

add_executable(run_dev ${SOURCE_FILE})
include_directories(lib)
add_subdirectory(lib)
target_link_libraries(run_dev traffic_light_lib)

#enable_testing()
add_subdirectory(tests)
#include_directories(tests)
