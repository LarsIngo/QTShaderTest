#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class Line : public QQuickItem // TODO: Shape
    {
        Q_OBJECT
    private:
    public:
        Line();
        virtual ~Line();
        void Init();
    };
}

