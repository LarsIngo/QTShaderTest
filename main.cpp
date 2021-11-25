#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtMultimedia>
#include <QtQuick>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/qmls/main.qml"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl)
        {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        },
        Qt::QueuedConnection);

    engine.load(url);

    QSoundEffect effect;
    effect.setSource(QStringLiteral("qrc:/sounds/ping01.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(0.25f);
    effect.play();

/*
    // Using QQuickView
    QQuickView view;
    view.setSource(QStringLiteral("qrc:/qmls/TestLabel.qml"));
    view.show();
    QObject *object = view.rootObject();
        */

    return app.exec();
}
