#include <iostream>
#include "headers/rect.h"

Rect::Rect(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Rect::~Rect(){}

void Rect::mouseClicked(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Rect::mouseMoved(QMouseEvent *event) { event->ignore(); }

void Rect::mouseReleased(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}

void Rect::setWidth(const int width) { myWidth = width; }

void Rect::paint(QPoint endPoint)
{
    QPainter painter(image);
    painter.beginNativePainting();

    painter.setPen(QPen(*myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));

    painter.setRenderHint(QPainter::Antialiasing);
    int rx = endPoint.x() - lastPoint.x();
    int ry = endPoint.y() - lastPoint.y();

    painter.drawRect(lastPoint.x(), lastPoint.y(), rx, ry);

    modified = true;

    painter.endNativePainting();
}

