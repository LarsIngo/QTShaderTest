#pragma once

#include <QtQuick>

class MyItem : public QQuickItem
{
private:

public:
    MyItem();
    ~MyItem();

    void mousePressEvent(QMouseEvent *event) {
        QQuickItem::mousePressEvent(event);
        qDebug() << event->pos();
    }
};
