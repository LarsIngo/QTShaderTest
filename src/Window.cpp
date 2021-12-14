#include "Window.hpp"

SpellScaper::Window::Window() : QQuickView()
{
    //setAcceptedMouseButtons(Qt::AllButtons);
}

SpellScaper::Window::~Window()
{
}

void SpellScaper::Window::mousePressEvent(QMouseEvent *event)
{
    QQuickWindow::mousePressEvent(event);
    qDebug() << event->pos();
}
