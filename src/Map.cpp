#include "Map.hpp"
#include "Ping.hpp"
#include "Utility.hpp"

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

    void Map::mousePressEvent(QMouseEvent* event)
    {
        QQuickItem::mousePressEvent(event);
        qDebug() << event->pos();

        if (event->buttons() == Qt::RightButton)
        {
            this->soundEffect.play();
            Ping* ping = SpellScaper::Utility::Instantiate<Ping>(QUrl("qrc:/qmls/Ping.qml"));
            ping->setProperty("x", event->pos().x() - ping->property("width").toReal() * 0.5f);
            ping->setProperty("y", event->pos().y() - ping->property("height").toReal() * 0.5f);
        }
        else
        {
            QQuickItem* radar = SpellScaper::Utility::Instantiate<QQuickItem>(QUrl("qrc:/qmls/RadarFX.qml"));
        }
    }
}

