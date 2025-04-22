# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(ppscl)               # project name
set(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# directory with symlinks
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
foreach(header_path 
    src/int/ppint.h
    src/string/ppstring.h
    src/value/ppvalue.h
    src/array/pparray.h
    src/stack/ppstack.h
    src/vector/ppvector.h
    src/list/pplist.h
    src/hashset/pphashset.h
    src/hashmap/pphashmap.h
    src/container/ppcontainer.h
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
    src/int/ppint.c
    src/string/ppstring.c
    src/value/ppvalue.c
    src/array/pparray.c
    src/stack/ppstack.c
    src/vector/ppvector.c
    src/list/pplist.c
    src/hashset/pphashset.c
    src/hashmap/pphashmap.c
    src/container/ppcontainer.c
    
    src/int/ppint-value.c
    src/string/ppstring-value.c
    src/array/pparray-container.c
    src/stack/ppstack-container.c
    src/vector/ppvector-container.c
    src/list/pplist-container.c
    src/hashset/pphashset-container.c
    src/hashmap/pphashmap-container.c
)

option( "Build tests" ON)
if(TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION include)
install(TARGETS containers DESTINATION lib)