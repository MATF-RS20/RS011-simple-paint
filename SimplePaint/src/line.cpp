#include <iostream>
#include "headers/line.h"


Line::Line(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Line::~Line() {}

/* mouse events */
void Line::mouseClicked(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        finallDrawing = false;
        tmp = *image;
        localCopy = *image;
        lastPoint = event->pos();
    }
}

void Line::mouseMoved(QMouseEvent *event) {
    *image = tmp;
    tmp = localCopy;
    paint(event->pos());
}

void Line::mouseReleased(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        *image = localCopy;
        finallDrawing = true;
        paint(event->pos());
    }
}

void Line::setWidth(const int width) { myWidth = width; }

/* line's logic */
void Line::paint(QPoint endPoint) {
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
    painter.drawLine(lastPoint, endPoint);

    modified = true;
}

