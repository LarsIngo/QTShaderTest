#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class Window : public QQuickView
    {
    private:

    public:
        Window();
        virtual ~Window();

        void mousePressEvent(QMouseEvent *event);
    };
}

