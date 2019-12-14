#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QSize>
#include "headers/mainwindow.h"


class image {
public:
    image(QString img);
    ~image();

    QImage getImage();

    //QPixmap openImage(double height, double width);
private:
    QImage m_img;
};

#endif // IMAGE_H
