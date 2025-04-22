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
target_link_libraries(my_program PRIVATE
    -Wl,--whole-archive
    containers
    -Wl,--no-whole-archive
)
```


## documentation in [/doc](/doc/)

## [more about the procedural-parametric paradigm in general](http://www.softcraft.ru/ppp/)
