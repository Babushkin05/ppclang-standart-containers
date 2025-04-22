# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(ppscl)               # project name
set(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# directory with symlinks
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
foreach(header_path 
    src/int/int.h
    src/value/value.h
    src/array/array.h
    src/stack/stack.h
    src/vector/vector.h
    src/list/list.h
    src/hashset/hashset.h
    src/hashmap.h
    src/container/container.h
)
    get_filename_component(header_name ${header_path} NAME)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/${header_path}
        ${CMAKE_BINARY_DIR}/include/${header_name}
    )
endforeach()

include_directories(
    ${CMAKE_BINARY_DIR}/include  
    ${CMAKE_SOURCE_DIR}/src     
)

add_library(containers STATIC
    src/int/int.c
    src/value/value.c
    src/array/array.c
    src/stack/stack.c
    src/vector/vector.c
    src/list/list.c
    src/hashset/hashset.c
    src/hashmap/hashmap.c
    src/container/container.c
    
    src/int/int-value.c
    src/array/array-container.c
    src/stack/stack-container.c
    src/vector/vector-container.c
    src/list/list-container.c
    src/hashset/hashset-container.c
    src/hashmap/hashmap-container.c
)

option( "Build tests" ON)
if(TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION include)
install(TARGETS containers DESTINATION lib)