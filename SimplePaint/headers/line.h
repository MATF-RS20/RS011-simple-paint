#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include "headers/tool.h"

class Line : public Tool
{
    Q_OBJECT
public:
    Line(QColor*, int, QImage*);

    ~Line() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    void setWidth(const int width) override;

private:
    QPoint lastPoint;
    QImage localCopy;
    QImage tmp;
    bool finallDrawing;
};


#endif // LINE_H
