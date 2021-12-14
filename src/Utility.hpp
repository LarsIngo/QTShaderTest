#pragma once

#include <QQmlEngine>

namespace SpellScaper
{
    class Utility
    {
    private:
        Utility();
        ~Utility();

        QQmlEngine engine;

        static Utility& Instance();
    public:
        static QQmlEngine& Engine();

        Utility(Utility const&) = delete;
        void operator=(Utility const&) = delete;
    };
}

