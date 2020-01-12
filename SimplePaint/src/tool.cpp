#include "headers/tool.h"

Tool::Tool(QColor* color, const int width, QImage* img)
    : QObject()
    , myColor(color)
    , myWidth(width)
    , image(img)
{}

Tool::Tool(QColor* color, QImage* img)
    : QObject()
    , myColor(color)
    , image(img)
{}

Tool::Tool(QImage* img)
    : QObject()
    , myColor(nullptr)
    , myWidth(0)
    , image(img)
{}

Tool::~Tool() {}
