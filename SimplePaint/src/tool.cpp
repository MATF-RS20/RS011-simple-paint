#include "headers/tool.h"

Tool::Tool(const QColor color, const int width, QImage* img)
    :QObject()
    , myColor(color)
    , myWidth(width)
    , image(img)
{}

Tool::~Tool()
{}
