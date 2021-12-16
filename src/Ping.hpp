#pragma once

#include <QtQuick>
#include <QtMultimedia>

namespace SpellScaper
{
    class Ping : public QQuickItem
    {
        Q_OBJECT
    private:
        QSoundEffect soundEffect;
    public:
        Ping();
        virtual ~Ping();
    };
}

