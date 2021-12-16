#include "Ping.hpp"

namespace SpellScaper
{
    Ping::Ping() : QQuickItem()
    {
        this->soundEffect.setSource(QUrl("qrc:/sounds/Ping02.wav"));
        this->soundEffect.setVolume(0.25f);
        this->soundEffect.play();
    }

    Ping::~Ping()
    {
    }

    void Ping::Init(QPoint pos)
    {
        this->setProperty("x", pos.x() - this->property("width").toReal() * 0.5f);
        this->setProperty("y", pos.y() - this->property("height").toReal() * 0.5f);
    }
}

