#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QSize>
#include <QDebug>
#include <QColor>
#include <QPoint>
#include <QWidget>
#include "headers/mainwindow.h"


class image: public QWidget {
public:

    image(QWidget *parent = 0);
    ~image();

    //TODO:
    //predlazem da dodamo slider-e, pa i ako doda neko vecu sliku, videce se cela, samo ce
    //morati da pomera slider da gleda dalje
    //reserved_places dodat jer racuna velicinu celog prostora, a mi ga spustamo zatim i pomeramo udesno,
    //pa cisto da budemo da za sada sigurno staje u ceo prozor slika

    bool openImage(const QString &fileName);
    void setPenColor(const QColor &newColor);
    // bool saveImage(const QString &fileName, const char *fileFormat);

    // the image was modified
    bool isModified() const {
        return modified;
    }

    QColor penColor() const {
        return myColor;
    }
    QImage getImage() const {
        return img;
    }

public slots:
    void clearImage();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *img, const QSize &newSize);

    // saved after a change?
    bool modified;
    bool drawing;

    int myWidth;
    QColor myColor;

    QImage img;
    QPoint lastPoint;
};

#endif // IMAGE_H
