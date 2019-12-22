#include <iostream>
#include "headers/eraser.h"

Eraser::Eraser(QColor* color, int width, QImage* img)
    : Tool::Tool(color, width,img)
{}

Eraser::~Eraser(){}

void Eraser::mouseClicked(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Eraser::mouseMoved(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton)
        paint(event->pos());
}

void Eraser::mouseReleased(QMouseEvent *event){

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}

void Eraser::setWidth(const int width) {
    myWidth = width;
}


void Eraser::paint(QPoint endPoint){

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

