#ifndef TOOL_H
#define TOOL_H

#include <QColor>
#include <QMouseEvent>
#include <QImage>
#include <QPoint>
#include <QPainter>
#include <QObject>

#include "qpainter.h"

class Tool : public QObject
{
    Q_OBJECT

public:
    //Tool(const QColor);

    virtual ~Tool();
    virtual void mouseClicked(QMouseEvent*) = 0;
    virtual void mouseMoved(QMouseEvent*) = 0;
    virtual void mouseReleased(QMouseEvent*) = 0;

    QColor getColor() const;

    void setColor(QColor color);
    void setWidth(const int width);
signals:
    virtual void updateRect(QRect);

protected:
    virtual void paint(QPoint) = 0;
    QColor myColor;
    int myWidth;
    QImage *image;
    bool modified = false;
    Tool(const QColor, const int, QImage*);

    Tool(QImage*);

private:
};

#endif // TOOL_H
