cmake_minimum_required(VERSION 3.18.4)

add_executable(gsl-lib-math.test  test.cpp)
target_link_libraries(gsl-lib-math.test PRIVATE gtest_main gsl-lib-math)

add_test(gsl-lib-math "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/gsl-lib-math.test")