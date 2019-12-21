#include <iostream>
#include "headers/pencil.h"


Pencil::Pencil(QColor color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Pencil::~Pencil(){}

void Pencil::mouseClicked(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Pencil::mouseMoved(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton)
        paint(event->pos());
}

void Pencil::mouseReleased(QMouseEvent *event){

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}

void Pencil::paint(QPoint endPoint){

    QPainter painter(image);
    std::cout << "Paint" << std::endl;
    painter.setPen(QPen(myColor,
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

