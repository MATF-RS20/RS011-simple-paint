#ifndef PENCIL_H
#define PENCIL_H

#include "headers/tool.h"

class Pencil : public Tool
{
    Q_OBJECT
public:
    Pencil(QColor*, int, QImage*);

    ~Pencil() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    void setWidth(const int width) override;

private:
    QPoint lastPoint;
};

#endif // PENCIL_H
