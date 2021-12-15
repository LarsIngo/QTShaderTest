#include "Utility.hpp"

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
        QQmlComponent windowComponent(SpellScaper::Utility::Engine(), QUrl("qrc:/qmls/Window.qml"));
        if (windowComponent.isError())
        {
            qDebug() << windowComponent.errorString();
        }

        SpellScaper::Utility::Instance().window = qobject_cast<QQuickWindow*>(windowComponent.create());

        return Utility::App();
    }

    QGuiApplication* Utility::App()
    {
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

