#include "Map.hpp"
#include "Ping.hpp"
#include "PingController.hpp"
#include "Radar.hpp"
#include "UIManager.hpp"

namespace SpellScaper
{
    enum PingType
    {
        none = -1,
        center,
        up,
        down,
        left,
        right,
    };

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
            QVector2D rootSize = QVector2D( this->pingController->property("width").toReal(), this->pingController->property("height").toReal());
            QVector2D rootCenter = QVector2D(this->pingController->property("x").toReal() + rootSize.x() * 0.5f, this->pingController->property("y").toReal() + rootSize.y() * 0.5f);

            Ping* ping = SpellScaper::UIManager::InstantiateItem<Ping>(QUrl("qrc:/qmls/Ping.qml"), 3.0f);
            ping->Init(QPoint(rootCenter.x(), rootCenter.y()), QColor(0,0,1));

            this->Clear();
        }
    }

    void Map::mouseMoveEvent(QMouseEvent* event)
    {
        if (this->pingController != nullptr)
        {
            QVector2D rootSize = QVector2D( this->pingController->property("width").toReal(), this->pingController->property("height").toReal());
            QVector2D rootCenter = QVector2D(this->pingController->property("x").toReal() + rootSize.x() * 0.5f, this->pingController->property("y").toReal() + rootSize.y() * 0.5f);

            QVector2D targetCenter = QVector2D(event->pos());
            QVector2D targetVec = (targetCenter - rootCenter);
            QVector2D targetDir = targetVec.normalized();

            float pi = qDegreesToRadians(180);
            float val = sin(pi * 0.25f);

            PingType pingType;
            if (targetVec.length() < rootSize.x() * 0.1f)
            {
                pingType = PingType::center;
            }
            else if (QVector2D::dotProduct(targetDir, QVector2D(0,-1)) > val)
            {
                 pingType = PingType::up;
            }
            else if (QVector2D::dotProduct(targetDir, QVector2D(0, 1)) > val)
            {
                 pingType = PingType::down;
            }
            else if (QVector2D::dotProduct(targetDir, QVector2D(-1, 0)) > val)
            {
                 pingType = PingType::left;
            }
            else if (QVector2D::dotProduct(targetDir, QVector2D(1, 0)) > val)
            {
                 pingType = PingType::right;
            }
            else
            {
                pingType = PingType::none;
            }

            this->pingController->setProperty("pingType", int(pingType));
        }
    }
}

