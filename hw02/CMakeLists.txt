cmake_minimum_required(VERSION 3.1)
project(hw02)

# Configure compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES Clang OR ${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
  # using regular Clang or AppleClang or GCC
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic -Wold-style-cast")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS "/permissive- /W4 /EHsc")
  add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif()

# Setup C++ and C sources
set(BIN_SOURCES config.cpp)
set(BIN_SOURCES_C config.c)
set(HEADERS config.hpp config.h)
file(GLOB TEST_SOURCES test*.cpp)

# Build object files just once, use them in both normal executable and tests
add_library(config OBJECT ${BIN_SOURCES})
add_library(configC OBJECT ${BIN_SOURCES_C})

# Setup binaries

add_executable(hw02_C main.c $<TARGET_OBJECTS:configC>)
set_target_properties(hw02_C PROPERTIES LINKER_LANGUAGE C)

add_executable(hw02 main.cpp $<TARGET_OBJECTS:config>)
set_target_properties(hw02 PROPERTIES LINKER_LANGUAGE CXX)

add_executable(hw02_tests ${TEST_SOURCES} $<TARGET_OBJECTS:config>)

configure_file(input.txt input.txt COPYONLY)
