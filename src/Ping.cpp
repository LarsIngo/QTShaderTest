#include "Ping.hpp"

namespace SpellScaper
{
    Ping::Ping() : QQuickItem()
    {
        // Start playing sound when ping is created.
        this->soundEffect.setSource(QUrl("qrc:/sounds/Ping02.wav"));
        this->soundEffect.setVolume(0.25f);
        this->soundEffect.play();
    }

    Ping::~Ping()
    {
    }

    void Ping::Init(const QPoint& pos, const QColor& color, const QUrl& icon)
    {
        // Set instance center at pos.
        this->setProperty("x", pos.x() - this->property("width").toReal() * 0.5f);
        this->setProperty("y", pos.y() - this->property("height").toReal() * 0.5f);

        // Set color.
        this->setProperty("r", color.red() / 255.0f);
        this->setProperty("g", color.green() / 255.0f);
        this->setProperty("b", color.blue() / 255.0f);

        // Set icon.
        this->setProperty("icon", icon);
    }
}

