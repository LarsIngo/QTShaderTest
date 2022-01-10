#include "Map.hpp"
#include "Ping.hpp"
#include "PingController.hpp"
#include "Radar.hpp"
#include "UIManager.hpp"

namespace SpellScaper
{
    Map::Map() : QQuickItem()
    {
        this->pingController = nullptr; // The current ping controller.
        this->setAcceptedMouseButtons(Qt::AllButtons); // Accept all mouse inputs.
    }

    Map::~Map()
    {
        this->Clear(); // Clear map when deleted.
    }

    void Map::Init()
    {
    }

    void Map::Clear()
    {
        // Clear ping controller if not null.
        if (this->pingController != nullptr)
        {
            this->pingController->deleteLater();
            this->pingController = nullptr;
        }
    }

     Map::PingType Map::EvaluatePing(const QVector2D& target)
     {
         // Chech whether ping controller exists.
         if (this->pingController != nullptr)
         {
             // Calculate relative size and position.
             QVector2D rootSize = QVector2D( this->pingController->property("width").toReal(), this->pingController->property("height").toReal());
             QVector2D rootCenter = QVector2D(this->pingController->property("x").toReal() + rootSize.x() * 0.5f, this->pingController->property("y").toReal() + rootSize.y() * 0.5f);

             QVector2D targetVec = (target - rootCenter);
             QVector2D targetDir = targetVec.normalized();

             const float pi = qDegreesToRadians(180);
             const float val = sin(pi * 0.25f);

             // Calculate sector of the ping controller which is actived based on angle between ping controller and target position (mouse position).
             if (targetVec.length() < rootSize.x() * 0.1f)
             {
                return PingType::center;
             }
             else if (QVector2D::dotProduct(targetDir, QVector2D(0,-1)) > val)
             {
                return PingType::up;
             }
             else if (QVector2D::dotProduct(targetDir, QVector2D(0, 1)) > val)
             {
                return PingType::down;
             }
             else if (QVector2D::dotProduct(targetDir, QVector2D(-1, 0)) > val)
             {
                return PingType::left;
             }
             else if (QVector2D::dotProduct(targetDir, QVector2D(1, 0)) > val)
             {
                return PingType::right;
             }
             else
             {
                return PingType::none;
             }
         }

         return PingType::none;
    }

    // Invokoed when mouse pressed the map.
    void Map::mousePressEvent(QMouseEvent* event)
    {
        // Check whether ping controller should be created.
        if ((event->buttons() & Qt::LeftButton) && this->pingController == nullptr)
        {
            this->pingController = SpellScaper::UIManager::InstantiateItem<PingController>(QUrl("qrc:/qmls/PingController.qml"));
            this->pingController->Init(event->pos());
        }

        // Check whether radar should be created.
        if (event->buttons() & Qt::RightButton)
        {
            this->Clear();
            Radar* radar = SpellScaper::UIManager::InstantiateItem<Radar>(QUrl("qrc:/qmls/Radar.qml"), 5.0f);
            radar->Init(event->pos());
        }
    }

    // Invoked when mouse releases the map.
    void Map::mouseReleaseEvent(QMouseEvent* event)
    {
        // If ping controller exists, replace ping controller with ping at its position.
        if (this->pingController != nullptr)
        {
            QPoint point = event->pos();
            PingType pingType = this->EvaluatePing(QVector2D(point.x(), point.y())); // Which section should be active.

            // Whether none or ping controller was canceled.
            if (pingType != PingType::none && pingType != PingType::center)
            {
                // Calucalte position.
                QVector2D rootSize = QVector2D( this->pingController->property("width").toReal(), this->pingController->property("height").toReal());
                QVector2D rootCenter = QVector2D(this->pingController->property("x").toReal() + rootSize.x() * 0.5f, this->pingController->property("y").toReal() + rootSize.y() * 0.5f);

                // Set color and icon based on ping type.
                QColor color;
                QUrl icon;
                switch(pingType) {
                    case PingType::up:
                        color = QColor(213, 32, 18);
                        icon =  QUrl("qrc:/images/PingIconUp.png");
                        break;
                    case PingType::down:
                        color = QColor(8, 143, 180);
                        icon =  QUrl("qrc:/images/PingIconDown.png");
                        break;
                    case PingType::left:
                        color = QColor(206, 172, 90);
                        icon =  QUrl("qrc:/images/PingIconLeft.png");
                        break;
                    case PingType::right:
                        color = QColor(43, 148, 129);
                        icon =  QUrl("qrc:/images/PingIconRight.png");
                        break;
                    default:
                        color = QColor(255, 255, 255,0);
                        icon =  QUrl();
                }

                // Create ping.
                Ping* ping = SpellScaper::UIManager::InstantiateItem<Ping>(QUrl("qrc:/qmls/Ping.qml"), 3.0f);
                ping->Init(QPoint(rootCenter.x(), rootCenter.y()), color, icon);
            }

            this->Clear();
        }
    }

    // Invoked when mouse is moved.
    void Map::mouseMoveEvent(QMouseEvent* event)
    {
        // If ping controller exists, updated ping controller section based on mouse position.
        if (this->pingController != nullptr)
        {
            QPoint point = event->pos();
            PingType pingType = this->EvaluatePing(QVector2D(point.x(), point.y()));
            this->pingController->setProperty("pingType", int(pingType));
        }
    }
}

