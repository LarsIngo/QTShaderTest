#pragma once

#include <QtMultimedia>
#include <QtQuick>

namespace SpellScaper
{
    class Map : public QQuickItem
    {
        Q_OBJECT
    private:
        QSoundEffect soundEffect;
    public:
        Map();
        virtual ~Map();

        void mousePressEvent(QMouseEvent *event);
    };
}

