#ifndef COLORPICKER_H
#define COLORPICKER_H

#include "headers/tool.h"

class ColorPicker : public Tool
{
    Q_OBJECT
public:
    ColorPicker(QImage* img);

    ~ColorPicker() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    void setColor(QColor color) override;
    void setWidth(const int width) override;

    QColor getColor() const override { return myColor; }

signals:
    void updateRect(QRect) override;

private:
    QPoint lastPoint;
};

#endif // ERASER_H
