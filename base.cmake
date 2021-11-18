if(IS_PAB_PROJECT_SETUP)
  return()
endif()
set(IS_PAB_PROJECT_SETUP TRUE)

if(${PROJECT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
  message(STATUS "CMAKE_BUILD_TYPE is \"${CMAKE_BUILD_TYPE}\"")
  message(STATUS "PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}")
  message(STATUS "CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")
  if(CMAKE_BUILD_TYPE STREQUAL "doc")

  elseif(CMAKE_BUILD_TYPE STREQUAL "Release")

  elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")

  else()
    message(
      FATAL_ERROR "Supported CMAKE_BUILD_TYPE values are [doc, Release, Debug]")
  endif()

  if(EXISTS "src")
    file(GLOB_RECURSE ALL_SOURCE_FILES1 src/*.cpp src/*.hpp src/*.h)
  endif()

  if(EXISTS "test")
    file(GLOB_RECURSE ALL_SOURCE_FILES2 test/*.cpp test/*.hpp test/*.h)
  endif()

  add_custom_target(
    format-code
    COMMAND clang-format-12 -style=Google -i ${ALL_SOURCE_FILES1}
            ${ALL_SOURCE_FILES2}
    COMMENT "Formating all cpp files")

  if(CMAKE_BUILD_TYPE MATCHES "^doc")
    set(CMAKE_INSTALL_PREFIX /tmp/)

    # first we can indicate the documentation build as an option and set it to
    # ON by default
    option(BUILD_DOC "Build documentation" ON)

    # check if Doxygen is installed
    find_package(Doxygen)
    if(DOXYGEN_FOUND)

      # set input and output files
      set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
      set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

      # request to configure the file
      configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
      message("Doxygen build started")

      # note the option ALL which allows to build the docs together with the
      # application
      add_custom_target(
        doc-doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
    else(DOXYGEN_FOUND)
      message(
        FATAL_ERROR
          "Doxygen need to be installed to generate the doxygen documentation")
    endif(DOXYGEN_FOUND)
  else() # Not doc
    message(STATUS "Setting up executables  ${MY_EXES}")

    if(EXISTS "${PROJECT_BINARY_DIR}/config.hpp.in")
      configure_file(config.hpp.in config.hpp)
    endif()

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    set(PROJECT_WARN_FLAGS "-Wall -Wextra -Wpedantic")
    set(PROJECT_CXX_FLAGS "${PROJECT_WARN_FLAGS}")

    set(CMAKE_CXX_FLAGS_RELEASE
        "${CMAKE_CXX_FLAGS_RELEASE} ${PROJECT_CXX_FLAGS} -O3 -flto -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS_DEBUG} ${PROJECT_CXX_FLAGS} -g -DDEBUG=1")

    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/archive")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

    add_custom_target(
      syntax-debug
      COMMAND make 2>&1 | head -n100
      COMMENT "Syntax Debuging")

    add_custom_target(
      install-system-dependancies
      COMMAND sudo apt install -y git doxygen python3-pip
      COMMENT "Installing Linux Package Dependancies"
      COMMAND pip3 install cmake-format)

    if(CMAKE_BUILD_TYPE MATCHES "Release")
      set(FULL_NAME_REL_EXEC_LIST ${MY_EXES})
      list(TRANSFORM FULL_NAME_REL_EXEC_LIST PREPEND bin/)

      set(FULL_NAME_INSTALLED_EXEC_LIST ${FULL_NAME_REL_EXEC_LIST})
      list(TRANSFORM FULL_NAME_INSTALLED_EXEC_LIST
           PREPEND ${CMAKE_INSTALL_PREFIX}/)

      add_custom_target(
        uninstall
        COMMAND rm -f ${FULL_NAME_INSTALLED_EXEC_LIST}
        COMMENT "Uninstalling the application ${FULL_NAME_INSTALLED_EXEC_LIST}")
    else() # Debug
      set(CMAKE_INSTALL_PREFIX /tmp/)
      message("Debug mode ${PROJECT_BINARY_DIR}")
      if(EXISTS ../test)
        message(STATUS "Debug mode - tests exists")
        if(EXISTS ../vendors/googletest)
          message(STATUS "Setting up tests")
          if(NOT TARGET gtest)
            add_subdirectory(vendors/googletest)
          endif()
          enable_testing()
          add_subdirectory(test)
          message(STATUS "Setting up tests done")
        else()
          message(FATAL_ERROR "Missing Google Test")
        endif()
      else()
        message(STATUS "No tests")
      endif()
    endif()
  endif()

endif()
