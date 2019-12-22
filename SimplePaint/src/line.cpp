#include <iostream>
#include "headers/line.h"


Line::Line(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Line::~Line(){}

void Line::mouseClicked(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Line::mouseMoved(QMouseEvent *event){
    //if (event->buttons() & Qt::LeftButton)
    //    paint(event->pos());
    event->ignore();
}

void Line::mouseReleased(QMouseEvent *event){

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}

void Line::setWidth(const int width) {
    myWidth = width;
}

void Line::paint(QPoint endPoint){

    QPainter painter(image);
    painter.setPen(QPen(*myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setRenderHint( QPainter::Antialiasing );
    painter.drawLine(lastPoint, endPoint);

    modified = true;
    int rad = (myWidth / 2) + 2;

    emit updateRect(QRect(lastPoint, endPoint).normalized()
                    .adjusted(-rad, -rad, +rad, +rad));


    //lastPoint = endPoint;
}

