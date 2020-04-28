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
set(JVM_PROJECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../JVM/Demo")
set(JAVA_JNI_HEADERS "JavaJNIHeaders")
ADD_CUSTOM_COMMAND(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/NativeDemo.h"
        COMMAND
            ${Java_JAVAH_EXECUTABLE}
            -o "${CMAKE_CURRENT_BINARY_DIR}/NativeDemo.h"
            -classpath "${JVM_PROJECT_PATH}/build/classes/kotlin/main"
            demo.NativeDemo
        DEPENDS "${JVM_PROJECT_PATH}/build/classes/kotlin/main/demo/NativeDemo.class")
ADD_CUSTOM_TARGET(${JAVA_JNI_HEADERS} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/NativeDemo.h")

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
TARGET_LINK_LIBRARIES(${PROJECT_NAME})
ADD_DEPENDENCIES(${PROJECT_NAME} ${JAVA_JNI_HEADERS})

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
