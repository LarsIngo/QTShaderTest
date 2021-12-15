#include "Utility.hpp"

#include "Map.hpp"
#include "Ping.hpp"
#include "Radar.hpp"
#include "Window.hpp"

namespace SpellScaper
{
    Utility::Utility()
    {
        this->engine = new QQmlEngine();
    }

    Utility::~Utility()
    {
        delete this->engine;
        delete this->app;
        delete this->window;
    }

    Utility& Utility::Instance()
    {
        static Utility instance;
        return instance;
    }

    QGuiApplication* Utility::Initialize(int argc, char *argv[])
    {
        qmlRegisterType<SpellScaper::Map>("SpellScaper", 1, 0, "Map");
        qmlRegisterType<SpellScaper::Ping>("SpellScaper", 1, 0, "Ping");
        qmlRegisterType<SpellScaper::Radar>("SpellScaper", 1, 0, "Radar");
        qmlRegisterType<SpellScaper::Window>("SpellScaper", 1, 0, "Window");

        Utility::Instance().app = new QGuiApplication(argc, argv);

        SpellScaper::Utility::Instance().window = Utility::InstantiateObject<SpellScaper::Window>(QUrl("qrc:/qmls/Window.qml"));

        return Utility::Instance().app;
    }

    QQmlEngine* Utility::Engine()
    {
        return Utility::Instance().engine;
    }

    QQuickWindow* Utility::Window()
    {
        return Utility::Instance().window;
    }
}
