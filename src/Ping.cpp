#include "Ping.hpp"

namespace SpellScaper
{
    Ping::Ping() : QQuickItem()
    {
        this->soundEffect.setSource(QUrl("qrc:/sounds/ping02.wav"));
        this->soundEffect.setVolume(0.25f);
        this->soundEffect.play();
    }

    Ping::~Ping()
    {
    }
}

