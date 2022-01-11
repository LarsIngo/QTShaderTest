# UI Project
QT Quick UI Project.

# Setup Guide
Follow steps in order to setup project for Windows using Qt Creator.

## QT 6.2.2
1. Download and install Qt 6.2.2 [https://www.qt.io/download].

### Qt Creator
1. Open Qt Creator.
2. Open project [.../*ProjectName*/CMakeLists.txt].
3. Configure for MinGW_64 and Run.

# Project Info
General information about the project.

## Structure
CMakeLists.txt contains all source files (e.g. code, image, sounds, shader etc.)
In order to create a new source file, create it and add reference to CMakeLists.txt.

## Custom Qml with C++ code-behind.
1. Create *X*.qml, *X*.cpp, *X*.hpp (Make sure to add Q_Object macro in hpp file).
2. Bind C++ code to Qml file using *qmlRegisterType<X>("NAMESPACE", 1, 0, "X")* in cpp file.

## Shaders
Shaders are written in GLSL, and compiled at build time using Vulkan SPIR-V.
The compiled shaders are accessed using the Qt Resource System (.qrc).

## Deploy using MinGW 64
1. Build the Qt project using MinGW_64 configuration.
2. Locate project build folder [eg. .../build-*ProjectName*-Desktop_Qt_6_2_2_MinGW_64_bit-Release].
3. Locate *windeployqt.exe* in Qt install path [eg. .../Qt/6.2.2/mingw_64/bin/windeployqt.exe].
4. Execute *windeployqt.exe* in shell with the path to the project build folder as the first argument [.../windeployqt.exe .../build-*ProjectName*-Desktop_Qt_6_2_2_MinGW_64_bit-Release].
5. The build folder should now contain all dependencies.
