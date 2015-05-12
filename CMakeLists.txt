cmake_minimum_required(VERSION 2.8)

project (EasyPR)

list(APPEND CMAKE_CXX_FLAGS "-lm")

set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)

set(CMAKE_SOURCE_DIR ./src)

set(SOURCE_FILES
    src/easypr.c
    src/core/plate.c
    src/core/pr.c
    src/core/debug.c
    src/core/global.c
)

add_executable(EasyPR ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(EasyPR m)
