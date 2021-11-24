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
    ShaderTools
    REQUIRED
)

set(PROJECT_SOURCES
    main.cpp
    #qml.qrc #TODOremove
)

set(PROJECT_HEADERS
)

set(PROJECT_RESOURCES
    "images/spellscaper.png"
    "main.qml"
    "MyShaderEffect.qml"
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
)

qt6_add_resources(${PROJECT_NAME} "resources"
    PREFIX
        "/"
    FILES
        ${PROJECT_RESOURCES}
)

qt6_add_shaders(${PROJECT_NAME} "shaders"
    BATCHABLE
    PRECOMPILE
    OPTIMIZED
    PREFIX
        "/"
    FILES
        "shaders/wiggleblender.frag"
        "shaders/wiggleblender.vert"
)


# https://doc.qt.io/qt-6/qtshadertools-build.html
# https://99designs.com/logo-design/contests/design-iconic-logo-indie-game-studio-1127780/entries
#qt6_add_shaders(${PROJECT_NAME} "porting-example-shaders"
#    #GLSL "300es,330"
#    BATCHABLE
#    PRECOMPILE
#    OPTIMIZED
#    PREFIX
#        "/shaders"
#    FILES
#        "shaders/wiggleblender.vert"
#        "shaders/wiggleblender.frag"
#)


#qt_import_qml_plugins(${PROJECT_NAME})
#qt_finalize_executable(${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
