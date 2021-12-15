#include "Map.hpp"
#include "Ping.hpp"
#include "Radar.hpp"
#include "Utility.hpp"

namespace SpellScaper
{
    Map::Map() : QQuickItem()
    {
        this->setAcceptedMouseButtons(Qt::AllButtons);

        this->soundEffect.setSource(QUrl("qrc:/sounds/ping02.wav"));
        this->soundEffect.setVolume(0.25f);
    }

    Map::~Map()
    {
    }

    void Map::mousePressEvent(QMouseEvent* event)
    {
        QQuickItem::mousePressEvent(event);
        if (event->buttons() & Qt::LeftButton)
        {
            Ping* ping = SpellScaper::Utility::Instantiate<Ping>(QUrl("qrc:/qmls/Ping.qml"));
            ping->setProperty("x", event->pos().x() - ping->property("width").toReal() * 0.5f);
            ping->setProperty("y", event->pos().y() - ping->property("height").toReal() * 0.5f);
            this->soundEffect.play();
        }

        if (event->buttons() & Qt::RightButton)
        {
            QQuickItem* radar = SpellScaper::Utility::Instantiate<QQuickItem>(QUrl("qrc:/qmls/Radar.qml"));
            radar->setProperty("x", event->pos().x() - radar->property("width").toReal() * 0.5f);
            radar->setProperty("y", event->pos().y() - radar->property("height").toReal() * 0.5f);
        }
    }
}

