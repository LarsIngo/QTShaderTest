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

    void Ping::Init(const QPoint& pos, const QColor& color, const QUrl& icon)
    {
        this->setProperty("x", pos.x() - this->property("width").toReal() * 0.5f);
        this->setProperty("y", pos.y() - this->property("height").toReal() * 0.5f);

        this->setProperty("r", color.red() / 255.0f);
        this->setProperty("g", color.green() / 255.0f);
        this->setProperty("b", color.blue() / 255.0f);

        this->setProperty("icon", icon);
    }
}

