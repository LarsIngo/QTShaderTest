#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>
#include <QtMultimedia>

#include "myItem.hpp"

// https://stackoverflow.com/questions/29608535/qquickview-handling-mouse-events-in-c
// https://doc.qt.io/qt-6/qtqml-cppintegration-interactqmlfromcpp.html
// https://stackoverflow.com/questions/68332323/custom-shaders-material-not-working-in-a-custom-qquickitem-object

int main(int argc, char *argv[])
{
    //qmlRegisterType<MyItem>("SpellTech", 1, 0, "MyItem");

    QGuiApplication app(argc, argv);

    QQuickWindow::setDefaultAlphaBuffer(true);

    QQmlEngine engine;
    QQmlComponent windowComponent(&engine, QUrl("qrc:/qmls/main.qml"));
    QQuickWindow* window = qobject_cast<QQuickWindow*>(windowComponent.create());
    //qDebug() << window;

    /*
    {
        QSoundEffect effect;
        effect.setSource(QUrl("qrc:/sounds/ping01.wav"));
        effect.setLoopCount(QSoundEffect::Infinite);
        effect.setVolume(0.25f);
        effect.play();
    }
    */

    /*
    {
        QQmlComponent objectComp(&engine, QUrl("qrc:/qmls/PingFX.qml"));
        QQuickItem* object = qobject_cast<QQuickItem*>(objectComp.create());
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
        object->setParentItem(window->contentItem());
        object->setParent(&engine);
    }
    */

    {
        QQmlComponent objectComp(&engine, QUrl("qrc:/qmls/RadarFX.qml"));
        QQuickItem* object = qobject_cast<QQuickItem*>(objectComp.create());
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
        object->setParentItem(window->contentItem());
        object->setParent(&engine);

        MyItem myItem;
        QObject::connect(object, SIGNAL(qmlSignal(QString)),
                         &myItem, SLOT(cppSlot(QString)));
    }

    //object->setProperty("anchors.right", "parent.right");
    //object->setProperty("anchors.left", "parent.left");
    //object->setProperty("x", window->width() * 0.5);
    //object->setProperty("y", window->height() * 0.5);
    //object->setProperty("width", 500);
    //object->setProperty("height", 500);

    return app.exec();
}
