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
        this->Clear();
    }

    void Map::Init()
    {
    }

    void Map::Clear()
    {
        if (this->pingController != nullptr)
        {
            this->pingController->deleteLater();
            this->pingController = nullptr;
        }
    }

    void Map::mousePressEvent(QMouseEvent* event)
    {
        if ((event->buttons() & Qt::LeftButton) && this->pingController == nullptr)
        {
            this->pingController = SpellScaper::UIManager::InstantiateItem<PingController>(QUrl("qrc:/qmls/PingController.qml"));
            this->pingController->Init(event->pos());
        }

        if (event->buttons() & Qt::RightButton)
        {
            this->Clear();
            Radar* radar = SpellScaper::UIManager::InstantiateItem<Radar>(QUrl("qrc:/qmls/Radar.qml"), 5.0f);
            radar->Init(event->pos());
        }
    }

    void Map::mouseReleaseEvent(QMouseEvent* event)
    {
        if (this->pingController != nullptr)
        {
            Ping* ping = SpellScaper::UIManager::InstantiateItem<Ping>(QUrl("qrc:/qmls/Ping.qml"), 3.0f);
            float x = this->pingController->property("x").toReal();
            float y = this->pingController->property("y").toReal();
            float width = this->pingController->property("width").toReal();
            float height = this->pingController->property("height").toReal();
            ping->Init(QPoint(x + width * 0.5f, y + height * 0.5f));

            this->Clear();
        }
    }

    void Map::mouseMoveEvent(QMouseEvent* event)
    {
        if (this->pingController != nullptr)
        {
            this->pingController->setProperty("targetPos", event->pos());
        }
    }
}

