# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(ppscl)               # project name
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    value/value.h
    array/array.h
    stack/stack.h
    container/container.h

    #sources
    test.c
    value/value.c
    array/array.c
    stack/stack.c
    container/container.c
    array/array-container.c
)

add_executable(test_program test.c ${SOURCE_FILES})
