#pragma once

#include <QGuiApplication>
#include <QQmlEngine>
#include <QtQuick>

namespace SpellScaper
{
    class Window;

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
        static QQmlEngine* Engine();
        static QQuickWindow* Window();
        static QGuiApplication* Initialize(int argc, char *argv[]);
        static QObject* InstantiateObject(const QUrl& url, float lifetime = -1.0f);

        template <class T>
        static T* InstantiateObject(const QUrl& url, float lifetime = -1.0f)
        {
            return qobject_cast<T*>(UIManager::InstantiateObject(url, lifetime));
        }

        template <class T>
        static T* InstantiateItem(const QUrl& url, float lifetime = -1.0f, QQuickItem* parent = nullptr)
        {
            T* item = UIManager::InstantiateObject<T>(url, lifetime);
            item->setParentItem(parent != nullptr ? parent : UIManager::Window()->contentItem());
            return item;
        }

        UIManager(UIManager const&) = delete;
        void operator=(UIManager const&) = delete;
    };
}

