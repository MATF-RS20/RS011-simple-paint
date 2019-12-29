#include <iostream>
#include "headers/ellipse.h"


Ellipse::Ellipse(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Ellipse::~Ellipse(){}

void Ellipse::mouseClicked(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Ellipse::mouseMoved(QMouseEvent *event) { event->ignore(); }

void Ellipse::mouseReleased(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}

void Ellipse::setWidth(const int width) { myWidth = width; }

void Ellipse::paint(QPoint endPoint)
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
    painter.drawEllipse(QPoint(lastPoint.x()+rx/2, lastPoint.y()+ry/2),
                        abs(rx/2), abs(ry/2));


    modified = true;

    painter.endNativePainting();
}

