cmake_minimum_required(VERSION 2.8)

project (EasyPR)

list(APPEND CMAKE_CXX_FLAGS "-std=c++0x")

set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)

set(CMAKE_SOURCE_DIR ./src)

set(SOURCE_FILES
    src/main.c
    src/core/plate.c
    src/core/debug.c
)

add_executable(EasyPR ${SOURCE_FILES})