#include <iostream>
#include <QDebug>
#include "headers/image.h"

image::image(QString img): m_img(img)
{
    std::cerr << "Konstruktor" << std::endl;
}

image::~image()
{
    std::cerr << "Destruktor" << std::endl;
}

QImage image::getImage() {
    return m_img;
}




