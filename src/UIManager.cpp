#include "UIManager.hpp"

#include "Line.hpp"
#include "Map.hpp"
#include "Ping.hpp"
#include "Radar.hpp"
#include "Window.hpp"

namespace SpellScaper
{
    UIManager::UIManager()
    {
        // Antialiasing.
        QSurfaceFormat format;
        format.setSamples(4);
        QSurfaceFormat::setDefaultFormat(format);

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
        // https://wiki.qt.io/Introduction_to_Qt_Quick_for_C++_Developers
        qmlRegisterType<SpellScaper::Line>("SpellScaper", 1, 0, "Line");
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

    QObject* UIManager::InstantiateObject(const QUrl& url, float lifetime)
    {
        QQmlComponent component(UIManager::Engine(), url);
        if (component.isError())
        {
            qDebug() << component.errorString();
            return nullptr;
        }

        QObject* object =  component.create();

        if (lifetime > 0.0f)
        {
            QTimer::singleShot(lifetime * 1000, object, [object](){ object->deleteLater(); });
        }

        return object;
    }
}
