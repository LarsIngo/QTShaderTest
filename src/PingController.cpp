#include "PingController.hpp"
#include "UIManager.hpp"

namespace SpellScaper
{
    PingController::PingController() : QQuickItem()
    {
    }

    PingController::~PingController()
    {
    }

    void PingController::Init(QPoint pos)
    {
        this->setProperty("x", pos.x() - this->property("width").toReal() * 0.5f);
        this->setProperty("y", pos.y() - this->property("height").toReal() * 0.5f);
    }
}

