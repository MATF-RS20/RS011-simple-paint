#include <iostream>
#include "headers/rect.h"

Rect::Rect(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Rect::~Rect(){}

/* mouse events */
void Rect::mouseClicked(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        finallDrawing = false;
        tmp = *image;
        localCopy = *image;
        lastPoint = event->pos();
    }
}

void Rect::mouseMoved(QMouseEvent *event) {
    *image = tmp;
    tmp = localCopy;
    paint(event->pos());
}

void Rect::mouseReleased(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        *image = localCopy;
        finallDrawing = true;
        paint(event->pos());
    }
}

void Rect::setWidth(const int width) { myWidth = width; }

/* rect's logic */
void Rect::paint(QPoint endPoint) {
    QPainter painter(image);

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

    painter.drawRect(lastPoint.x(), lastPoint.y(), rx, ry);
    modified = true;
}

