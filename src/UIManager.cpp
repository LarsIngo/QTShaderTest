#include "UIManager.hpp"

#include "Map.hpp"
#include "Ping.hpp"
#include "Radar.hpp"
#include "Window.hpp"

namespace SpellScaper
{
    UIManager::UIManager()
    {
        this->engine = new QQmlEngine();
    }

    UIManager::~UIManager()
    {
        delete this->engine;
        delete this->app;
        delete this->window;
    }

    UIManager& UIManager::Instance()
    {
        static UIManager instance;
        return instance;
    }

    QGuiApplication* UIManager::Initialize(int argc, char *argv[])
    {
        qmlRegisterType<SpellScaper::Map>("SpellScaper", 1, 0, "Map");
        qmlRegisterType<SpellScaper::Ping>("SpellScaper", 1, 0, "Ping");
        qmlRegisterType<SpellScaper::Radar>("SpellScaper", 1, 0, "Radar");
        qmlRegisterType<SpellScaper::Window>("SpellScaper", 1, 0, "Window");

        UIManager::Instance().app = new QGuiApplication(argc, argv);

        SpellScaper::UIManager::Instance().window = UIManager::InstantiateObject<SpellScaper::Window>(QUrl("qrc:/qmls/Window.qml"));

        return UIManager::Instance().app;
    }

    QQmlEngine* UIManager::Engine()
    {
        return UIManager::Instance().engine;
    }

    QQuickWindow* UIManager::Window()
    {
        return UIManager::Instance().window;
    }
}
