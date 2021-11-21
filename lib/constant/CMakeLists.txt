add_library(gsl-lib-constant INTERFACE)
target_include_directories(gsl-lib-constant INTERFACE includes)

add_subdirectory(test)
