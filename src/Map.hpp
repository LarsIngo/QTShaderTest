#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class Map : public QQuickItem
    {
        Q_OBJECT
    private:
    public:
        Map();
        virtual ~Map();
        void Init();

        void mousePressEvent(QMouseEvent* event) override;
    };
}

