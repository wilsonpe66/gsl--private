# add_library(bsl-lib-includes INTERFACE)
# target_include_directories(bsl-lib-includes INTERFACE includes)

# add_library(bsl-lib STATIC src/fileutils1.cpp  src/hierReg.cpp  src/matutils1.cpp  src/mnormal.cpp  src/mvn1.cpp  src/reg1.cpp  src/truncdraws.cpp  src/wishart.cpp)
# target_link_libraries(bsl-lib PUBLIC  bsl-lib-includes)
# target_link_libraries(bsl-lib PRIVATE  lgsl)

# target_compile_features(bsl-lib PRIVATE cxx_std_20)

add_subdirectory("constant")
add_subdirectory("type")
add_subdirectory("math")
