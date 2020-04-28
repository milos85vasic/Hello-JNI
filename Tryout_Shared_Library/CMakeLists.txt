cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME Tryout_Shared_Library)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

# Require JNI
find_package(JNI REQUIRED)

# Include header files
include_directories(${JNI_INCLUDE_DIRS}) # Access to jni.h
include_directories("/usr/local/include/Demo") # Access to shared library header files

link_directories("/usr/local/lib/Demo") # Link shared library
link_libraries(Demo)

add_executable(${PROJECT_NAME} main.cpp)