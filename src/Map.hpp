#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class Map : public QQuickItem
    {
    private:

    public:
        Map();
        virtual ~Map();

        void mousePressEvent(QMouseEvent *event);
    };
}

