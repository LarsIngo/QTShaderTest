cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME UIProject)

project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS
    Core
    Quick
    Multimedia
    ShaderTools
    REQUIRED
)

set(PROJECT_SOURCES
    "src/Main.cpp"
    "src/UIManager.cpp"

    "src/Line.cpp"
    "src/Map.cpp"
    "src/Ping.cpp"
    "src/PingController.cpp"
    "src/Radar.cpp"
    "src/Window.cpp"
)

set(PROJECT_HEADERS
    "src/UIManager.hpp"

    "src/Line.hpp"
    "src/Map.hpp"
    "src/Ping.hpp"
    "src/PingController.hpp"
    "src/Radar.hpp"
    "src/Window.hpp"
)

set(PROJECT_QMLS
    "qmls/Line.qml"
    "qmls/Map.qml"
    "qmls/Ping.qml"
    "qmls/PingController.qml"
    "qmls/Radar.qml"
    "qmls/Window.qml"
)

set(PROJECT_IMAGES
    "images/Map.png"
    "images/RadarNoise.png"
    "images/PingControllerColor.png"
    "images/PingControllerMask.png"
    "images/PingIconUp.png"
    "images/PingIconDown.png"
    "images/PingIconLeft.png"
    "images/PingIconRight.png"
)

set(PROJECT_SOUNDS
    "sounds/Ping01.wav"
    "sounds/Ping02.wav"
)

set(PROJECT_SHADERS
    "shaders/Ping.frag"
    "shaders/Ping.vert"
    "shaders/PingController.frag"
    "shaders/PingController.vert"
    "shaders/Radar.frag"
    "shaders/Radar.vert"
)

qt_add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

target_compile_definitions(${PROJECT_NAME}
  PUBLIC $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt6::Core
    Qt6::Quick
    Qt6::Multimedia
)

qt6_add_resources(${PROJECT_NAME} "resources"
    PREFIX
        "/"
    FILES
        ${PROJECT_QMLS}
        ${PROJECT_IMAGES}
        ${PROJECT_SOUNDS}
)

qt6_add_shaders(${PROJECT_NAME} "shaders"
    BATCHABLE
    PRECOMPILE
    OPTIMIZED
    PREFIX
        "/"
    FILES
        ${PROJECT_SHADERS}
)
