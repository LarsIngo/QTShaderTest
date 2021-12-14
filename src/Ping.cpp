#include "Ping.hpp"

namespace SpellScaper
{
    Ping::Ping() : QQuickItem()
    {
        /*
        QQmlComponent objectComp(&engine, QUrl("qrc:/qmls/PingFX.qml"));
        QQuickItem* object = qobject_cast<QQuickItem*>(objectComp.create());
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
        object->setParentItem(window->contentItem());
        object->setParent(&engine);
        */
    }

    Ping::~Ping()
    {
    }
}

