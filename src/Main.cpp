#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>
#include <QtMultimedia>

#include "Utility.hpp"
#include "Map.hpp"
#include "Ping.hpp"
#include "Radar.hpp"
#include "Window.hpp"

// https://stackoverflow.com/questions/29608535/qquickview-handling-mouse-events-in-c
// https://doc.qt.io/qt-6/qtqml-cppintegration-interactqmlfromcpp.html
// https://stackoverflow.com/questions/68332323/custom-shaders-material-not-working-in-a-custom-qquickitem-object

int main(int argc, char *argv[])
{
    qmlRegisterType<SpellScaper::Map>("SpellScaper", 1, 0, "Map");
    qmlRegisterType<SpellScaper::Ping>("SpellScaper", 1, 0, "Ping");
    qmlRegisterType<SpellScaper::Radar>("SpellScaper", 1, 0, "Radar");
    qmlRegisterType<SpellScaper::Window>("SpellScaper", 1, 0, "Window");

    QGuiApplication* app = SpellScaper::Utility::Initialize(argc, argv);

    return app->exec();
}
