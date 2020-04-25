cmake_minimum_required(VERSION 3.16)
project(Tryout_Shared_Library)

set(CMAKE_CXX_STANDARD 17)

include_directories("/usr/local/include/Demo")
link_directories("/usr/local/lib/Demo")
link_libraries(Demo)

add_executable(Tryout_Shared_Library main.cpp)