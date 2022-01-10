#include "UIManager.hpp"

#include "Map.hpp"
#include "Ping.hpp"
#include "PingController.hpp"
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
        // Bind C++ class to QML type.
        qmlRegisterType<SpellScaper::Map>("SpellScaper", 1, 0, "Map");
        qmlRegisterType<SpellScaper::Ping>("SpellScaper", 1, 0, "Ping");
        qmlRegisterType<SpellScaper::PingController>("SpellScaper", 1, 0, "PingController");
        qmlRegisterType<SpellScaper::Radar>("SpellScaper", 1, 0, "Radar");
        qmlRegisterType<SpellScaper::Window>("SpellScaper", 1, 0, "Window");

        // Initialize app.
        UIManager::Instance().app = new QGuiApplication(argc, argv);

        // Create window.
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

    // Create an instance of QML type and
    QObject* UIManager::InstantiateObject(const QUrl& url, float lifetime)
    {
        // Create QML component.
        QQmlComponent component(UIManager::Engine(), url);
        if (component.isError())
        {
            qDebug() << component.errorString();
            return nullptr;
        }

        // Create object.
        QObject* object = component.create();

        // Check whether object should be deleted after some time.
        if (lifetime > 0.0f)
        {
            // Delete object after lifetime
            QTimer::singleShot(lifetime * 1000, object, [object](){ object->deleteLater(); });
        }

        return object;
    }
}
