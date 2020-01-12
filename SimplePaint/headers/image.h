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

    bool isModified() const { return modified; }
    QColor penColor() const { return primaryColor; }
    int penWidth() const { return myWidth; }
    QImage getImage() const { return img; }

    std::stack<QImage> imagesUndo;
    std::stack<QImage> imagesRedo;
signals:
    void activatedUndo();

public slots:
    void clearImage();
    void setToolColor();
    void setBrushWidth();
    void setTool(QString nameOfTool);

    bool openImage(const QString &fileName);
    bool saveAsImage(const QString &filename, const char *fileFormat);
    void needToCrop();
    void scaleImageZoomIn();
    void scaleImageZoomOut();
    void undoFunc();
    void redoFunc();
    void newSheet();
    void resizeCurrentImg();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

private:
    void resizeImage(QImage *img, const QSize &newSize);
    void cropImage();

    bool modified;
    bool whiteBackground;

    int myWidth;
    int scaleFactor;
    QColor primaryColor;
    QColor secondaryColor;
    bool has_image;
    bool crop;
    QPoint startPoint;
    QPoint finishPoint;
    QImage img;
    Tool *tool;
    std::map<QString, Tool*> allTools;
};

#endif // IMAGE_H
