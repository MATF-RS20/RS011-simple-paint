#ifndef RECT_H
#define RECT_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include "headers/tool.h"

class Rect : public Tool
{
    Q_OBJECT
public:
    Rect(QColor*, int, QImage*);

    ~Rect() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    void setWidth(const int width) override;

private:
    QPoint lastPoint;
    QImage tmp;
    QImage localCopy;
    bool finallDrawing;

};


#endif // RECT_H
