#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class PingController;

    class Map : public QQuickItem
    {
        Q_OBJECT
    private:
        PingController* pingController;
        void Clear();
    public:
        Map();
        virtual ~Map();
        void Init();

        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override;
    };
}

