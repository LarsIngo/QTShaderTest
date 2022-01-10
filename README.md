# UI Project
QT Quick UI Project.

# Setup Guide
Follow steps in order to setup project for Windows using Qt Creator.

## QT 6.2.2
1. Download and install Qt 6.2.2 [https://www.qt.io/download].

### Qt Creator
1. Open Qt Creator.
2. Open project [.../*ProjectName*/CMakeLists.txt].
3. Configure and Run.

# Project Info
General information about the project.

## Structure
CMakeLists.txt contains all source files (e.g. code, image, sounds, shader etc.)
In order to create a new source file, create it and add reference to CMakeLists.txt.

## Custom Qml with C++ code-behind.
1. Create *X*.qml, *X*.cpp, *X*.hpp (Make sure to add Q_Object macro in hpp file).
2. Bind C++ code to Qml file using *qmlRegisterType<X>("NAMESPACE", 1, 0, "X")* in cpp file.

## Shaders
Shaders are written in GLSL, and complied at build time using Vulkan SPIR-V.
The compled shaders are accessed using the Qt Resource System (.qrc).