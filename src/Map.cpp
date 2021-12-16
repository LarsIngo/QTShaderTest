#include "Map.hpp"
#include "Ping.hpp"
#include "PingController.hpp"
#include "Radar.hpp"
#include "UIManager.hpp"

namespace SpellScaper
{
    Map::Map() : QQuickItem()
    {
        this->pingController = nullptr;
        this->setAcceptedMouseButtons(Qt::AllButtons);
    }

    Map::~Map()
    {
        if (this->pingController != nullptr)
        {
            this->pingController->deleteLater();
            this->pingController = nullptr;
        }
    }

    void Map::Init()
    {
    }

    void Map::mousePressEvent(QMouseEvent* event)
    {
        if (event->buttons() & Qt::LeftButton)
        {
            this->pingController = SpellScaper::UIManager::InstantiateItem<PingController>(QUrl("qrc:/qmls/PingController.qml"));
            this->pingController->Init(event->pos());
        }

        if (event->buttons() & Qt::RightButton)
        {
            Radar* radar = SpellScaper::UIManager::InstantiateItem<Radar>(QUrl("qrc:/qmls/Radar.qml"), 5.0f);
            radar->Init(event->pos());
        }
    }

    void Map::mouseReleaseEvent(QMouseEvent* event)
    {
        if (this->pingController != nullptr)
        {
            Ping* ping = SpellScaper::UIManager::InstantiateItem<Ping>(QUrl("qrc:/qmls/Ping.qml"), 3.0f);
            ping->Init(event->pos());

            this->pingController->deleteLater();
            this->pingController = nullptr;
        }
    }
}

