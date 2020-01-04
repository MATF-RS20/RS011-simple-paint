#ifndef Ellipse_H
#define Ellipse_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include "headers/tool.h"

class Ellipse : public Tool
{
    Q_OBJECT
public:
    Ellipse(QColor*, int, QImage*);

    ~Ellipse() override;

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


#endif // Ellipse_H
