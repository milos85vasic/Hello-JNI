cmake_minimum_required(VERSION 3.16)
project(Demo VERSION 1.0 DESCRIPTION "Demo shared library")

set(CMAKE_CXX_STANDARD 17)
set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/demo.h.in"
        "${PROJECT_BINARY_DIR}/demo.h"
)

# Make the JNI header file
FIND_PACKAGE(Java COMPONENTS Development) # Requires Java
set(JVM_PROJECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../JVM/Demo")
set(JAVA_JNI_HEADERS "JavaJNIHeaders")
add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/NativeDemo.h" # Destination
        COMMAND
            ${Java_JAVAH_EXECUTABLE} # Execute javah (javac -h) command
            -o "${CMAKE_CURRENT_BINARY_DIR}/NativeDemo.h" # Destination
            -classpath "${JVM_PROJECT_PATH}/build/classes/kotlin/main" # Path to .class files
            demo.NativeDemo # Package.className
        DEPENDS "${JVM_PROJECT_PATH}/build/classes/kotlin/main/demo/NativeDemo.class" # This file is mandatory (must exist)
)
add_custom_target(${JAVA_JNI_HEADERS} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/NativeDemo.h") # Execute on build

# Require JNI
find_package(JNI REQUIRED)

# Include header files
include_directories(
        ${JNI_INCLUDE_DIRS} # Gives us access to jni.h
        ${CMAKE_CURRENT_BINARY_DIR} # Include generated JNI headers from cmake-build-* directory.
)

# Create shared library
file(GLOB LIB_SRC *.h *.cpp)
add_library(${PROJECT_NAME} SHARED ${LIB_SRC})
target_link_libraries(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} ${JAVA_JNI_HEADERS})

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
