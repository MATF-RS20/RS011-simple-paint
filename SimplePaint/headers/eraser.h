#ifndef ERASER_H
#define ERASER_H

#include "headers/tool.h"

class Eraser : public Tool
{
    Q_OBJECT
public:
    Eraser(QColor*, int, QImage*);

    ~Eraser() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    void setWidth(const int width) override;

private:
    QPoint lastPoint;
};

#endif // ERASER_H
