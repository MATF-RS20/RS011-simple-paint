#include "headers/tool.h"

Tool::Tool(const QColor color, const int width, QImage* img)
    :QObject()
    , myColor(color)
    , myWidth(width)
    , image(img)
{}

Tool::Tool(QImage* img): QObject(), image(img)
{
    myColor = Qt::black;
    myWidth = 0;
}

Tool::~Tool()
{}
