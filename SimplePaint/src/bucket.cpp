#include <iostream>
#include "headers/bucket.h"


Bucket::Bucket(QColor* color, QImage* img)
    :Tool::Tool(color, img)
{}

Bucket::~Bucket() {}

void Bucket::mouseClicked(QMouseEvent *event) {event->ignore(); return; }

void Bucket::mouseMoved(QMouseEvent *event) {event->ignore(); return; }

void Bucket::mouseReleased(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}


void Bucket::setWidth(const int width) {Q_UNUSED(width) return; }

// TODO:
// Za sada samo boji pozadinu
void Bucket::paint(QPoint endPoint)
{
    Q_UNUSED(endPoint);

    QPainter painter(image);

    QBrush brush(*myColor, Qt::SolidPattern);

    painter.fillRect(0, 0, image->width(), image->height(), brush);

}

