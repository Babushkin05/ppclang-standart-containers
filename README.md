# Standart Containers Library for Procedural-Parametric style of Programming

## installation

download ***ppscl_installer.run*** from a [last release](https://github.com/Babushkin05/ppclang-standart-containers/releases/tag/v1.0.2)

and run this commands:

```
chmod +x ppscl_installer.run
sudo ./ppscl_installer.run
```

## usage

add this to ```CMakeLists.txt``` to link library to your project:

```cmake
find_library(CONTAINERS_LIB containers PATHS /usr/local/lib /path/to/your/lib)
if(NOT CONTAINERS_LIB)
    message(FATAL_ERROR "Containers library not found!")
endif()

# include headers
target_include_directories(my_program PRIVATE /usr/local/include/)

target_link_libraries(
    my_program PRIVATE
    -Wl,--whole-archive
    ${CONTAINERS_LIB}
    -Wl,--no-whole-archive
)
```


## documentation in [doc/](/doc/)

## [more about the procedural-parametric paradigm in general](http://www.softcraft.ru/ppp/)
