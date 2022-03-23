# WIP

## Installation

### C++ Installation 
- MINGW64
- Path /bin + test

### CMAKE Installation
- Path /bin + test

### VSCode configuration
- Install CMAKE extension
- .vscode folder with c_cpp_properties.json, launch.json, settings.json and tasks.json 

### git clone googleTest - in lib/googletest

### Follow the structure

<pre>
|-- .vscode
|-- build
|-- lib
|  `-- googletest (git clone)
|
|--src
|  |-- *.cpp
|  |-- main.cpp
|  `-- CMakeLists.txt
|
|--tst
|  |-- *.cpp
|  |-- main.cpp
|  `-- CMakeLists.txt
|
`--CMakeLists.txt
</pre>

## Build and launch

1. CMake: Build
2. Run executables (or 2 tasks in tasks.json)
