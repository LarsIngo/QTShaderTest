#pragma once

#include <QtQuick>

class Window : public QQuickItem
{
public:
    Window() {
        setAcceptedMouseButtons(Qt::AllButtons);
    }

    void mousePressEvent(QMouseEvent *event) {
        QQuickItem::mousePressEvent(event);
        qDebug() << event->pos();
    }
};
