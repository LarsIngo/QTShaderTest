#include "Map.hpp"

namespace SpellScaper
{
    Map::Map() : QQuickItem()
    {
        setAcceptedMouseButtons(Qt::AllButtons);

        this->soundEffect.setSource(QUrl("qrc:/sounds/ping02.wav"));
        this->soundEffect.setVolume(0.25f);
    }

    Map::~Map()
    {
    }

    void Map::mousePressEvent(QMouseEvent *event)
    {
        QQuickItem::mousePressEvent(event);
        qDebug() << event->pos();

        if (!this->soundEffect.isPlaying())
        {
             this->soundEffect.play();
        }
    }
}

