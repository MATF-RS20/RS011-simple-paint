#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <stack>
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
#include <QLabel>

#include "qpainter.h"

#include "headers/tool.h"
#include "headers/pencil.h"
#include "headers/eraser.h"
#include "headers/colorpicker.h"
#include "headers/brush.h"
#include "headers/line.h"
#include "headers/bucket.h"
#include "headers/ellipse.h"
#include "headers/rect.h"
#include "headers/triangle.h"

class image: public QWidget {

    Q_OBJECT

public:
    image(QWidget *parent = nullptr);
    ~image() override;

    // the image was modified?
    bool isModified() const { return modified; }
    QColor penColor() const { return primaryColor; }
    int penWidth() const { return myWidth; }
    QImage getImage() const { return img; }

    // Za undo
    std::stack<QImage> imagesUndo;
    std::stack<QImage> imagesRedo;

signals:
    void activatedUndo();

public slots:
    void clearImage();
    void setPenColor();
    void setBrushWidth();
    void setTool(QString nameOfTool);

    bool openImage(const QString &fileName);
    bool saveAsImage(const QString &filename, const char *fileFormat);
    void needToCrop();
    void scaleImageZoomIn();
    void scaleImageZoomOut();
    void undoFunc();
    void redoFunc();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void resizeImage(QImage *img, const QSize &newSize);
    void cropImage();

    bool modified;                 // saved after a change?
    bool whiteBackground;          // initial background

    int myWidth;
    QColor primaryColor;
    QColor secondaryColor;
    bool has_image;
    bool crop;
    QPoint startPoint;
    QPoint finishPoint;
    QImage img;
    Tool *tool;
    std::map<QString, Tool*> allTools;

    // Za zoom
    QLabel *imageLabel;
    double scaleFactor = 1;


};

#endif // IMAGE_H
