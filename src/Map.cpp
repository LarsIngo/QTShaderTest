#include "Map.hpp"
#include "Ping.hpp"
#include "Radar.hpp"
#include "UIManager.hpp"

namespace SpellScaper
{
    Map::Map() : QQuickItem()
    {
        this->setAcceptedMouseButtons(Qt::AllButtons);
    }

    Map::~Map()
    {
    }

    void Map::Init()
    {
    }

    void Map::mousePressEvent(QMouseEvent* event)
    {
        QQuickItem::mousePressEvent(event);
        if (event->buttons() & Qt::LeftButton)
        {
            Ping* ping = SpellScaper::UIManager::InstantiateItem<Ping>(QUrl("qrc:/qmls/Ping.qml"), 3.0f);
            ping->Init(event->pos());
        }

        if (event->buttons() & Qt::RightButton)
        {
            Radar* radar = SpellScaper::UIManager::InstantiateItem<Radar>(QUrl("qrc:/qmls/Radar.qml"), 5.0f);
            radar->Init(event->pos());
        }
    }
}

