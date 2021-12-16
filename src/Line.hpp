#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class Line : public QQuickItem // TODO: Shape or QQuickPaintedItem
    {
        Q_OBJECT
    private:
    public:
        Line();
        virtual ~Line();
        void Init();
    };
}

