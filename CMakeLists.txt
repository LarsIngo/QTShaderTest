cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME ShaderTest)

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
    main.cpp
    utility.cpp
)

set(PROJECT_HEADERS
    utility.hpp
)

set(PROJECT_QMLS
    "qmls/main.qml"
    "qmls/ImageFX.qml"
    "qmls/TestLabel.qml"
    "qmls/PingFX.qml"
    "qmls/RadarFX.qml"
)

set(PROJECT_IMAGES
    "images/spellscaper.png"
    "images/triangle.png"
    "images/map.png"
    "images/radarNoise.png"
)

set(PROJECT_SOUNDS
    "sounds/ping01.wav"
)

set(PROJECT_SHADERS
    "shaders/ping.frag"
    "shaders/ping.vert"
    "shaders/radar.frag"
    "shaders/radar.vert"
)

qt_add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PRIVATE
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

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
