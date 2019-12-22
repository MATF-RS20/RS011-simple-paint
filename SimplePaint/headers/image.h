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
#include <QMouseEvent>
#include <QWidget>
#include <QColorDialog>
#include <QObject>

#include "headers/tool.h"
#include "headers/pencil.h"
#include "headers/eraser.h"


#include "qpainter.h"


class image: public QWidget {

//    Q_OBJECT

public:
    image(QWidget *parent = nullptr);
    ~image() override;

    //TODO:
    //predlazem da dodamo slider-e, pa i ako doda neko vecu sliku, videce se cela, samo ce
    //morati da pomera slider da gleda dalje

    void setColorPicker();    
    // the image was modified?
    bool isModified() const
    {
        return modified;
    }

    QColor penColor() const
    {
        return myColor;
    }
    QImage getImage() const
    {
        return img;
    }

public slots:
    void clearImage();
    void setPenColor();

    bool openImage(const QString &fileName);
    bool saveImage(const QString &filename, const char *fileFormat);


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *img, const QSize &newSize);

    bool modified;                 // saved after a change?
    bool drawing;                  // currently drawing?
    bool whiteBackground;         //initial background
    // TODO: uvesti mapi ili hijerarhiju klasa za alatke
    bool colorPicker;

    int myWidth;

    QColor myColor;
    QImage img;
    QPoint lastPoint;
    Eraser *tool;
};

#endif // IMAGE_H
