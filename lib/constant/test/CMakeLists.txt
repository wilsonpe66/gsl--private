cmake_minimum_required(VERSION 3.18.4)

add_executable(gsl-lib-constant.test test.cpp)
target_link_libraries(gsl-lib-constant.test PRIVATE gtest_main gsl-lib-constant)

add_test(gsl-lib-constant-test
         "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/gsl-lib-constant.test")
