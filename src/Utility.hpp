#pragma once

#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>

namespace SpellScaper
{
    class Utility
    {
    private:
        Utility();
        ~Utility();

        QGuiApplication* app;
        QQmlEngine* engine;
        QQuickWindow* window;

        static Utility& Instance();
    public:
        static QGuiApplication* Initialize(int argc, char *argv[]);
        static QGuiApplication* App();
        static QQmlEngine* Engine();
        static QQuickWindow* Window();

        Utility(Utility const&) = delete;
        void operator=(Utility const&) = delete;

        template <class T>
        static T* Instantiate (const QUrl& url)
        {
            QQmlComponent comp(Utility::Engine(), url);
            if (comp.isError())
            {
                qDebug() << comp.errorString();
                return nullptr;
            }

            T* item = qobject_cast<T*>(comp.create());
            QQmlEngine::setObjectOwnership(item, QQmlEngine::CppOwnership);
            item->setParentItem(Utility::Window()->contentItem());
            item->setParent(Utility::Engine());

            return item;
        }
    };
}

