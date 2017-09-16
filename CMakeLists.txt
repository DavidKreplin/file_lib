cmake_minimum_required(VERSION 2.8.9)
project(file_lib)

# Code
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Compile library
add_library(file_lib ${SOURCES})

# Export header files incase of included submodule
target_include_directories(file_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# configuration for "make install" and "make doc" (if standalone)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)

  # check if Doxygen is installed
  find_package(Doxygen)
  if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # create command "make doc"
    add_custom_target( doc
          COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
          WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
          COMMENT "Generating API documentation with Doxygen" VERBATIM)
  else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
  endif (DOXYGEN_FOUND)

  # Copy libirary file (file_lib.a)
  install (TARGETS file_lib ARCHIVE DESTINATION lib LIBRARY DESTINATION lib) 
  # Copy header files
  install (FILES include/test.h DESTINATION include/file_lib)

else()
  # called as a subdirectory => no installation 
endif()



