cmake_minimum_required(VERSION 3.16)
project(Demo VERSION 1.0.0 DESCRIPTION "Demo shared library")

set(CMAKE_CXX_STANDARD 17)
set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/demo.h.in"
        "${PROJECT_BINARY_DIR}/demo.h"
        @ONLY
)

include(GNUInstallDirs)
add_library(Demo SHARED demo_library.cpp demo_library.h)

set_target_properties(
        Demo PROPERTIES
        VERSION ${Demo_VERSION_MAJOR}
        SOVERSION ${Demo_VERSION_MINOR}
        PUBLIC_HEADER demo_library.h
)

target_include_directories(Demo PRIVATE .)

install(
        TARGETS Demo
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_BINARY_DIR}/demo.h DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Install log:
# -- Install configuration: "Debug"
# -- Installing: /usr/local/lib/libDemo.1.dylib
# -- Installing: /usr/local/lib/libDemo.0.dylib
# -- Installing: /usr/local/lib/libDemo.dylib
# -- Installing: /usr/local/include/demo_library.h
# -- Installing: /usr/local/share/pkgconfig/demo.h
