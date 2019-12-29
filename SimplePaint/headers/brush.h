#ifndef BRUSH_H
#define BRUSH_H

#include "headers/tool.h"
#include <QInputDialog>

class Brush : public Tool
{
    Q_OBJECT
public:
    Brush(QColor*, int, QImage*);

    ~Brush() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    int penWidth() const;
    void setWidth(const int width) override;


private:
    QPoint lastPoint;
};

#endif // BRUSH_H
