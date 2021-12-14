#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>
#include <QtMultimedia>

#include "myItem.hpp"
#include "Map.hpp"

// https://stackoverflow.com/questions/29608535/qquickview-handling-mouse-events-in-c
// https://doc.qt.io/qt-6/qtqml-cppintegration-interactqmlfromcpp.html
// https://stackoverflow.com/questions/68332323/custom-shaders-material-not-working-in-a-custom-qquickitem-object

void RegisterTypes()
{
    qmlRegisterType<SpellScaper::Map>("SpellScaper", 1, 0, "Map");
}

int main(int argc, char *argv[])
{
    RegisterTypes();

    QGuiApplication app(argc, argv);
    QQmlEngine engine;

    QQmlComponent windowComponent(&engine, QUrl("qrc:/qmls/main.qml"));
    QQuickWindow* window = qobject_cast<QQuickWindow*>(windowComponent.create());
    qDebug() << window;

    {
        QQmlComponent objectComp(&engine, QUrl("qrc:/qmls/PingFX.qml"));
        QQuickItem* object = qobject_cast<QQuickItem*>(objectComp.create());
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
        object->setParentItem(window->contentItem());
        object->setParent(&engine);
    }

    //QQuickWindow *window = new QQuickWindow();
    //window->setSource(QUrl("qrc:/qmls/WindowQML.qml"));
    //window->show();

    //QQuickView *view = new QQuickView;
    //view->setSource(QUrl("qrc:/qmls/main.qml"));
    //view->show();

/*
        QQuickView view(QUrl("qrc:/qmls/MyItem.qml"));
        QObject *item = view.rootObject();

        MyClass myClass;
        QObject::connect(item, SIGNAL(qmlSignal(QString)), &myClass, SLOT(cppSlot(QString)));

        view.show();
*/
    /*
    {
        QQmlComponent objectComp(&engine, QUrl("qrc:/qmls/RadarFX.qml"));
        QQuickItem* object = qobject_cast<QQuickItem*>(objectComp.create());
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
        object->setParentItem(window->contentItem());
        object->setParent(&engine);
    }
*/
    //object->setProperty("anchors.right", "parent.right");
    //object->setProperty("anchors.left", "parent.left");
    //object->setProperty("x", window->width() * 0.5);
    //object->setProperty("y", window->height() * 0.5);
    //object->setProperty("width", 500);
    //object->setProperty("height", 500);

    return app.exec();
}
