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

void Bucket::paint(QPoint endPoint)
{
    auto color = image->pixelColor(endPoint);

    colorFill(endPoint.x(), endPoint.y(), color);

}


//TODO
//prepraviti da ne puca program,
//u pojedinim momentima puca zbog broja stek okvira
//ili prebaciti na iterativni nacin ili nekako voditi racuna
void Bucket::colorFill(int x, int y, QColor color){
    auto presentColor = image->pixelColor(x, y);
    if(presentColor != color)
        return;

    image->setPixelColor(x, y, *myColor);

    if(x > 0 && image->pixelColor(x-1, y) == color)
        colorFill(x-1, y, color);
    if(y > 0 && image->pixelColor(x, y-1) == color)
        colorFill(x, y-1, color);
    if(x < image->size().width()-1 && image->pixelColor(x+1, y) == color)
        colorFill(x+1, y, color);
    if(y < image->size().height()-1 && image->pixelColor(x, y+1) == color)
        colorFill(x, y+1, color);

}
