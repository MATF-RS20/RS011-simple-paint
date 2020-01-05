#include <iostream>
#include <stack>
#include <memory>
#include "headers/bucket.h"

Bucket::Bucket(QColor* color, QImage* img)
    :Tool::Tool(color, img)
{}

Bucket::~Bucket() {}

/* mouse events */
void Bucket::mouseClicked(QMouseEvent *event) { event->ignore(); return; }

void Bucket::mouseMoved(QMouseEvent *event) { event->ignore(); return; }

void Bucket::mouseReleased(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        paint(event->pos());
}

void Bucket::setWidth(const int width) { Q_UNUSED(width) return; }

/* bucket's logic */
void Bucket::paint(QPoint endPoint) {

    auto color = image->pixelColor(endPoint);
    colorFill(endPoint, color);
}

/* Color pixels inside of some polygon */
void Bucket::colorFill(QPoint startPoint, QColor color) {
    auto presentColor = image->pixelColor(startPoint);

    if(presentColor == *myColor)
         return;

    std::shared_ptr<std::stack<QPoint>>
            pointStack = std::make_shared<std::stack<QPoint>>();

    pointStack->push(startPoint);

    while(!pointStack->empty()) {
        auto topPoint = pointStack->top();
        pointStack->pop();

        image->setPixelColor(topPoint, *myColor);

        auto x = topPoint.x();
        auto y = topPoint.y();

        if(x > 0 && image->pixelColor(x-1, y) == color) {
           pointStack->push(QPoint(x-1, y));
        }
        if(y > 0 && image->pixelColor(x, y-1) == color) {
            pointStack->push(QPoint(x, y-1));
        }
        if(x < image->size().width()-1 && image->pixelColor(x+1, y) == color) {
            pointStack->push(QPoint(x+1, y));
        }
        if(y < image->size().height()-1 && image->pixelColor(x, y+1) == color) {
            pointStack->push(QPoint(x, y+1));
        }
    }
}
