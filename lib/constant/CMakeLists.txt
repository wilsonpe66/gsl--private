# target_compile_features(bsl-lib PRIVATE cxx_std_20)

add_library(gsl-lib-constant INTERFACE)
target_include_directories(gsl-lib-constant INTERFACE includes)

add_subdirectory(test)