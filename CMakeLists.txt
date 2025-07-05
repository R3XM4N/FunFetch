cmake_minimum_required(VERSION 3.10)
project(FunFetch)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#source files
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

#Executable
add_executable(FunFetch ${SRC_FILES})

#include directories
target_include_directories(FunFetch PRIVATE ${PROJECT_SOURCE_DIR}/src)