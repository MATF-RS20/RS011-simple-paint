#include <iostream>
#include <QDebug>
#include "headers/colorpicker.h"

ColorPicker::ColorPicker(QImage* img)
    : Tool::Tool(img)
{}

ColorPicker::~ColorPicker(){}

void ColorPicker::mouseClicked(QMouseEvent *event) { event->ignore(); return; }

void ColorPicker::mouseMoved(QMouseEvent *event) { event->ignore(); return; }

void ColorPicker::mouseReleased(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        paint(event->pos());
    }
}

void ColorPicker::setColor(QColor color)
{
    myColor = color;
}
void ColorPicker::setWidth(const int width) {Q_UNUSED(width) return; }

void ColorPicker::paint(QPoint endPoint){

    //QPainter painter(image);

    myColor = image->pixelColor(endPoint);
    qDebug() << myColor;
    setColor(myColor);
}

