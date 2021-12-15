#include "Ping.hpp"

namespace SpellScaper
{
    Ping::Ping() : QQuickItem()
    {
        qDebug() << "Ping.Constructor";
    }

    Ping::~Ping()
    {
        qDebug() << "Ping.Destructor";
    }
}

