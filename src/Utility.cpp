#include "Utility.hpp"
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

