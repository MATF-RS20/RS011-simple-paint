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
void Bucket::colorFill(int x, int y, QColor color){
    auto presentColor = image->pixelColor(x, y);
    int originl_x = x;
    int originl_y = y;

    while (x > 0 && image->pixelColor(x-1, y) == color) {
        if(presentColor != color)
            continue;
        image->setPixelColor(x, y, *myColor);
        int o_y = y;

        while (y > 0 && image->pixelColor(x, y-1) == color) {
            if(presentColor != color)
                continue;
            image->setPixelColor(x, y, *myColor);
            y--;
        }
        y = o_y;
        while (y < image->size().height()-1 && image->pixelColor(x, y+1) == color) {
            if(presentColor != color)
                continue;
            image->setPixelColor(x, y, *myColor);
            y++;
        }
        y = o_y;

        x--;
    }
    x = originl_x;

    while (y > 0 && image->pixelColor(x, y-1) == color) {
        if(presentColor != color)
            continue;
        image->setPixelColor(x, y, *myColor);
        int o_x = x;
        while (x > 0 && image->pixelColor(x-1, y) == color) {
            if(presentColor != color)
                continue;
            image->setPixelColor(x, y, *myColor);
            x--;
        }
        x = o_x;

        while (x < image->size().width()-1 && image->pixelColor(x+1, y) == color) {
            if(presentColor != color)
               continue;
            image->setPixelColor(x, y, *myColor);
               x++;
        }
        x = o_x;
        y--;
    }
    y = originl_y;

    while (x < image->size().width()-1 && image->pixelColor(x+1, y) == color) {
        if(presentColor != color)
            continue;
        image->setPixelColor(x, y, *myColor);

        int o_y = y;

        while (y > 0 && image->pixelColor(x, y-1) == color) {
            if(presentColor != color)
                continue;
            image->setPixelColor(x, y, *myColor);
            y--;
        }
        y = o_y;
        while (y < image->size().height()-1 && image->pixelColor(x, y+1) == color) {
            if(presentColor != color)
                continue;
            image->setPixelColor(x, y, *myColor);
            y++;
        }
        y = o_y;
        x++;
    }
    x = originl_x;
    while (y < image->size().height()-1 && image->pixelColor(x, y+1) == color) {
        if(presentColor != color)
            continue;
        image->setPixelColor(x, y, *myColor);
        int o_x = x;
        while (x > 0 && image->pixelColor(x-1, y) == color) {
            if(presentColor != color)
                 continue;
            image->setPixelColor(x, y, *myColor);
            x--;
        }
        x = o_x;

        while (x < image->size().width()-1 && image->pixelColor(x+1, y) == color) {
            if(presentColor != color)
                continue;
            image->setPixelColor(x, y, *myColor);
            x++;
        }
        x = o_x;
        y++;
    }
    y = originl_y;
}
