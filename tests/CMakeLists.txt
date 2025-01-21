project(tests)

add_subdirectory(googletests)

add_executable(run_test traffic_light_test.cpp)
target_link_libraries(run_test traffic_light_lib)
target_link_libraries(run_test gtest gtest_main)