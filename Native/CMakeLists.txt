cmake_minimum_required(VERSION 3.16)
project(Demo VERSION 1.0 DESCRIPTION "Demo shared library")

set(CMAKE_CXX_STANDARD 17)
set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/demo.h.in"
        "${PROJECT_BINARY_DIR}/demo.h"
)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Create shared library
add_library(${PROJECT_NAME} SHARED demo_library.cpp demo_library.h)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

# Example install log:
# Install the project...
# -- Install configuration: "Debug"
# -- Up-to-date: /usr/local/lib/Demo/libDemo.dylib
# -- Up-to-date: /usr/local/include/Demo/demo_library.h
