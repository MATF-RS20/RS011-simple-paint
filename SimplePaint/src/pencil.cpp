#include <iostream>
#include "headers/pencil.h"


Pencil::Pencil(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Pencil::~Pencil() {}

/* mouse events */
void Pencil::mouseClicked(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        lastPoint = event->pos();
}

void Pencil::mouseMoved(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        paint(event->pos());
}

void Pencil::mouseReleased(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton)
        paint(event->pos());
}

void Pencil::setWidth(const int width) { Q_UNUSED(width); }

/* pencil's logic */
void Pencil::paint(QPoint endPoint) {
    QPainter painter(image);

    painter.setPen(QPen(*myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::SquareCap,
                        Qt::MiterJoin));

    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawLine(lastPoint, endPoint);

    modified = true;

    lastPoint = endPoint;
}

