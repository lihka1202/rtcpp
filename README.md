# rtcpp

A Ray tracing in C++ (Demo).
A lot of this is from the `Ray Tracing in one weekend` Course. I'll be experimenting randomly to see if things are the way I expect them to be, or if I understand things to be what they need to be.

# Outputting a basic image
The basic image is done by creating a plain text ppm (Portable PixMap).
Here is a good descriptipon of this picked from [here](https://paulbourke.net/dataformats/ppm/).
>A PPM file consists of two parts, a header and the image data. The header consists of at least three parts normally delineated by carriage returns and/or linefeeds but the PPM specification only requires white space. The first "line" is a magic PPM identifier, it can be "P3" or "P6" (not including the double quotes!). The next line consists of the width and height of the image as ASCII numbers. The last part of the header gives the maximum value of the colour components for the pixels, this allows the format to describe more than single byte (0..255) colour values. In addition to the above required lines, a comment can be placed anywhere with a "#" character, the comment extends to the end of the line.

For any file, P3 usually mean that this is in text.
Each line is following a new line character
```
P3 
3 2 # The size
255 # The max colour
255 0 0     0 255 0     0 0 255
255 255 0   255 255 255     0 0 0
```
In our case the aim is to create a 256x256 pixel image, an example is created in `image.ppm`. In order to view this you can use [this](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html) and upload the image there.

But a few things need to be done before this can blindly be done.

## Setup
### Install Cmake
If you're like me and have run into this error too many times:
`cmake: The term 'cmake' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.`
It just means that you don't have CMake installed and you should install it using an MSI online or just use winget. For example

```bash
winget install kitware.cmake
```

### Set up CmakeLists.txt
You need a `CmakeLists.txt`.

`CMakeLists.txt` is a file used by CMake, a cross-platform build system generator. This file contains instructions and configurations that tell CMake how to build your project. Here’s what it typically includes and what it’s used for:
- Project Configuration: You can specify the name of the project, the version, and any languages used (like C, C++, etc.).
```cmake
project(MyProject VERSION 1.0.0 LANGUAGES CXX)
```
- Defining Targets: You can define build targets like executables, libraries, etc. A target can be an executable or a library that you want to build.
```cmake
add_executable(MyExecutable main.cpp)
add_library(MyLibrary STATIC library.cpp)
```
- Specifying Source Files: You specify which source files are part of the project.
```cmake
set(SOURCES main.cpp file1.cpp file2.cpp)
```
- Setting Build Options: You can set various build options like compiler flags, include directories, and linking libraries.
```cmake
target_compile_options(MyExecutable PRIVATE -Wall -Wextra)
target_include_directories(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(MyExecutable PRIVATE MyLibrary)
```
- Handling Dependencies: CMake can be used to manage project dependencies, downloading and integrating them into your build.
```cmake
find_package(OpenCV REQUIRED)
target_link_libraries(MyExecutable PRIVATE ${OpenCV_LIBS})
```
- Custom Commands: You can define custom commands to be run during the build process, such as generating files or running tests.
```cmake
add_custom_command(
    TARGET MyExecutable
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/MyExecutable ${CMAKE_SOURCE_DIR}/bin
)
```

## Start coding
Now we can start coding, can reference from `randomImage.cc`.

Note that we need the following commands:

### Command Guide
`cmake -B build`: 
`cmake --build build`:
`build\Debug\inOneWeekend.exe > image.ppm`

