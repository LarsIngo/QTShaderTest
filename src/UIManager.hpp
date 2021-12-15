#pragma once

#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>

#include "Window.hpp"

namespace SpellScaper
{
    class UIManager
    {
    private:
        UIManager();
        ~UIManager();

        QGuiApplication* app;
        QQmlEngine* engine;
        SpellScaper::Window* window;

        static UIManager& Instance();
    public:
        static QGuiApplication* Initialize(int argc, char *argv[]);
        static QGuiApplication* App();
        static QQmlEngine* Engine();
        static QQuickWindow* Window();

        template <class T>
        static T* InstantiateObject(const QUrl& url)
        {
            QQmlComponent component(UIManager::Engine(), url);
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
            T* t = UIManager::InstantiateObject<T>(url);
            t->setParentItem(parent != nullptr ? parent : UIManager::Window()->contentItem());
            return t;
        }

        UIManager(UIManager const&) = delete;
        void operator=(UIManager const&) = delete;
    };
}

