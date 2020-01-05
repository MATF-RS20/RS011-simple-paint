#include <iostream>
#include "headers/ellipse.h"


Ellipse::Ellipse(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Ellipse::~Ellipse(){}

/* mouse events */
void Ellipse::mouseClicked(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        finallDrawing = false;
        tmp = *image;
        localCopy = *image;
        lastPoint = event->pos();
    }
}

void Ellipse::mouseMoved(QMouseEvent *event) {
    *image = tmp;
    tmp = localCopy;
    paint(event->pos());
}

void Ellipse::mouseReleased(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        *image = localCopy;
        finallDrawing = true;
        paint(event->pos());
    }
}

void Ellipse::setWidth(const int width) { myWidth = width; }

/* ellipse's logic */
void Ellipse::paint(QPoint endPoint) {
    QPainter painter(image);

    /* mouse release hasn't happend yet */
    if(!finallDrawing) {
        painter.setPen(QPen(*myColor,
                            myWidth,
                            Qt::DashDotLine,
                            Qt::RoundCap,
                            Qt::RoundJoin));
    } else {
        painter.setPen(QPen(*myColor,
                            myWidth,
                            Qt::SolidLine,
                            Qt::RoundCap,
                            Qt::RoundJoin));
    }

    painter.setRenderHint(QPainter::Antialiasing);
    int rx = endPoint.x() - lastPoint.x();
    int ry = endPoint.y() - lastPoint.y();
    painter.drawEllipse(QPoint(lastPoint.x()+rx/2, lastPoint.y()+ry/2),
                        abs(rx/2), abs(ry/2));

    modified = true;
}

