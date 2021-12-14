#include "Utility.hpp"

namespace SpellScaper
{
    Utility::Utility()
    {
        /*
        QQmlComponent objectComp(&engine, QUrl("qrc:/qmls/PingFX.qml"));
        QQuickItem* object = qobject_cast<QQuickItem*>(objectComp.create());
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
        object->setParentItem(window->contentItem());
        object->setParent(&engine);
        */
    }

    Utility::~Utility()
    {
    }

    Utility& Utility::Instance()
    {
        static Utility instance;
        return instance;
    }

    QQmlEngine& Utility::Engine()
    {
        return Utility::Instance().engine;
    }
}

