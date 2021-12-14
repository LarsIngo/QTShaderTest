#include "Map.hpp"

namespace SpellScaper
{
    Map::Map() : QQuickItem()
    {
        setAcceptedMouseButtons(Qt::AllButtons);
    }

    Map::~Map()
    {
    }

    void Map::mousePressEvent(QMouseEvent *event)
    {
        QQuickItem::mousePressEvent(event);
        qDebug() << event->pos();
    }
}

