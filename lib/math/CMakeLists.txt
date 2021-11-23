add_library(gsl-lib-math-includes INTERFACE)
target_include_directories(gsl-lib-math-includes INTERFACE includes)

add_library(gsl-lib-math STATIC src/complex.cpp)
target_link_libraries(gsl-lib-math PUBLIC gsl-lib-type gsl-lib-constant
                                          gsl-lib-math-includes)

add_subdirectory(test)
