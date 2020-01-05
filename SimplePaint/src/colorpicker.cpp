#include <iostream>
#include <QDebug>
#include "headers/colorpicker.h"

ColorPicker::ColorPicker(QColor* primary, QColor* secondary, QImage* img)
    : Tool::Tool(img)
    , myPrimary(primary)
    , mySecondary(secondary)
{}

ColorPicker::~ColorPicker(){}

/* mouse events */
void ColorPicker::mouseClicked(QMouseEvent *event) { event->ignore(); return; }

void ColorPicker::mouseMoved(QMouseEvent *event) { event->ignore(); return; }

void ColorPicker::mouseReleased(QMouseEvent *event) {
    pickerButton = event->button();
    paint(event->pos());
}

void ColorPicker::setWidth(const int width) {Q_UNUSED(width) return; }

/* colorpicker's logic */
void ColorPicker::paint(QPoint endPoint) {
    QPainter painter(image);

    auto Color = image->pixelColor(endPoint);
    if(pickerButton == Qt::LeftButton)
        *myPrimary = Color;
    else
        *mySecondary = Color;

}

