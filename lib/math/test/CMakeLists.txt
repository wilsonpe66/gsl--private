cmake_minimum_required(VERSION 3.18.4)

add_executable(gsl-lib-math-complex.test complex-math-test.cpp)
target_link_libraries(gsl-lib-math-complex.test
                      PUBLIC gtest_main gsl-lib-constant gsl-lib-math)

add_test(gsl-lib-math-complex-test
         "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/gsl-lib-math-complex.test")
