#include <iostream>
#include "headers/brush.h"


Brush::Brush(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Brush::~Brush(){}

/* mouse events */
void Brush::mouseClicked(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        lastPoint = event->pos();
}

void Brush::mouseMoved(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        paint(event->pos());
}

void Brush::mouseReleased(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        paint(event->pos());
    }
}

int Brush::penWidth() const { return myWidth; }
void Brush::setWidth(const int width) { myWidth = width; }

/* brush's logic */
void Brush::paint(QPoint endPoint) {

    QPainter painter(image);
    painter.setPen(QPen(*myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));

    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawLine(lastPoint, endPoint);

    modified = true;

    lastPoint = endPoint;
}

