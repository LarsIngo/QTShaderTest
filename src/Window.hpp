#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class Window : public QQuickWindow
    {
        Q_OBJECT
    private:
    public:
        Window();
        virtual ~Window();
        void Init();
    };
}

