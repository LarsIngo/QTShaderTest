#pragma once

#include <QtMultimedia>
#include <QtQuick>

namespace SpellScaper
{
    class Map : public QQuickItem
    {
    private:
        QSoundEffect soundEffect;
    public:
        Map();
        virtual ~Map();

        void mousePressEvent(QMouseEvent *event);
    };
}

