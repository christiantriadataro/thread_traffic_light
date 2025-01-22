cmake_minimum_required(VERSION 3.30)
project(traffic_light)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILE src/main.cpp)

add_executable(run_dev ${SOURCE_FILE} lib/traffic_light.cpp)
include_directories(lib)
add_subdirectory(lib)
target_link_libraries(run_dev traffic_light_lib)
#
#add_subdirectory(tests)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

#add_executable(run_dev ${SOURCE_FILE})
enable_testing()
add_subdirectory(tests)
#add_executable(
#        run_test
#        hello_test.cc
#)
#target_link_libraries(
#        run_test
#        GTest::gtest_main
#)

#include(GoogleTest)
#gtest_discover_tests(run_test)