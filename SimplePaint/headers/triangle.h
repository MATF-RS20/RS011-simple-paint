#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include "headers/tool.h"

class Triangle : public Tool
{
    Q_OBJECT
public:
    Triangle(QColor*, int, QImage*);

    ~Triangle() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    void setWidth(const int width) override;

private:
    QPoint lastPoint;
    QPoint Point1;
    QPoint Point2;
    QPoint Point3;
    QImage tmp;
    QImage localCopy;
    bool finallDrawing;
};


#endif // TRIANGLE_H
