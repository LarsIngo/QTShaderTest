#pragma once

#include <QtQuick>

namespace SpellScaper
{
    class PingController;

    class Map : public QQuickItem
    {
        Q_OBJECT
    private:
        enum PingType
        {
            none = -1,
            center,
            up,
            down,
            left,
            right,
        };

        PingController* pingController;
        void Clear();
        PingType EvaluatePing(const QVector2D& target);
    public:
        Map();
        virtual ~Map();
        void Init();

        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override;
    };
}

