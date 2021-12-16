#include "Radar.hpp"

namespace SpellScaper
{
    Radar::Radar() : QQuickItem()
    {
    }

    Radar::~Radar()
    {
    }

    void Radar::Init(QPoint pos)
    {
        this->setProperty("x", pos.x() - this->property("width").toReal() * 0.5f);
        this->setProperty("y", pos.y() - this->property("height").toReal() * 0.5f);
    }
}

