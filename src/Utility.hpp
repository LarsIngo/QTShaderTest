#pragma once

#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>

#include "Window.hpp"

namespace SpellScaper
{
    class Utility
    {
    private:
        Utility();
        ~Utility();

        QGuiApplication* app;
        QQmlEngine* engine;
        SpellScaper::Window* window;

        static Utility& Instance();
    public:
        static QGuiApplication* Initialize(int argc, char *argv[]);
        static QGuiApplication* App();
        static QQmlEngine* Engine();
        static QQuickWindow* Window();

        template <class T>
        static T* InstantiateObject(const QUrl& url)
        {
            QQmlComponent component(Utility::Engine(), url);
            if (component.isError())
            {
                qDebug() << component.errorString();
                return nullptr;
            }

            QObject* object = component.create();
            T* t = qobject_cast<T*>(object);
            return t;
        }

        template <class T>
        static T* InstantiateItem(const QUrl& url, QQuickItem* parent = nullptr)
        {
            T* t = Utility::InstantiateObject<T>(url);
            t->setParentItem(parent != nullptr ? parent : Utility::Window()->contentItem());
            return t;
        }

        Utility(Utility const&) = delete;
        void operator=(Utility const&) = delete;
    };
}

