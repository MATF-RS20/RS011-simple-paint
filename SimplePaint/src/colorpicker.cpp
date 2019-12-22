#include <iostream>
#include "headers/colorpicker.h"

ColorPicker::ColorPicker(QImage* img)
    : Tool::Tool(img)
{}

ColorPicker::~ColorPicker(){}

void ColorPicker::mouseClicked(QMouseEvent *event) { return; }

void ColorPicker::mouseMoved(QMouseEvent *event) { return; }

void ColorPicker::mouseReleased(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        paint(event->pos());
    }
}

void ColorPicker::setColor(QColor color)
{
    myColor = color;
}
void ColorPicker::setWidth(const int width) { return; }

void ColorPicker::paint(QPoint endPoint){

    QPainter painter(image);
    QColor pickedColor = image->pixelColor(endPoint);

    myColor = image->pixelColor(endPoint);
    setColor(pickedColor);
}

