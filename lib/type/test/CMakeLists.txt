cmake_minimum_required(VERSION 3.18.4)

add_executable(gsl-lib-type-complex.test complex-test.cpp)
target_link_libraries(gsl-lib-type-complex.test PRIVATE gtest_main gsl-lib-type
                                                        gsl-lib-constant)

add_test(gsl-lib-type-complex-test
         "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/gsl-lib-type-complex.test")
