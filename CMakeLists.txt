cmake_minimum_required(VERSION 3.18.4)
get_property(IS_PETE_GSL_SETUP GLOBAL PROPERTY IS_PETE_GSL_SETUP_PROP)
if(IS_PETE_GSL_SETUP)
  message("target pete-gsl is already setup")
  return()
endif()
set_property(GLOBAL PROPERTY IS_PETE_STD_LIB_SETUP_PROP TRUE)

project("Pete GSL" VERSION "0.1.0")

enable_testing()

include(base.cmake)

add_subdirectory("lib")
add_subdirectory("vendors")


install(DIRECTORY includes/pete-gsl-lib
        DESTINATION "include/pete-gsl-${PROJECT_VERSION}")
