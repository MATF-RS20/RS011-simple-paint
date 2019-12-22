#include <iostream>
#include "headers/brush.h"


Brush::Brush(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Brush::~Brush(){}

void Brush::mouseClicked(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Brush::mouseMoved(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton)
        paint(event->pos());
}

void Brush::mouseReleased(QMouseEvent *event){

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}


void Brush::setWidth(const int width) {
    myWidth = width;
}

void Brush::paint(QPoint endPoint){

    QPainter painter(image);
    painter.setPen(QPen(*myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawLine(lastPoint, endPoint);

    modified = true;
    int rad = (myWidth / 2) + 2;

    emit updateRect(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));


    lastPoint = endPoint;
}

