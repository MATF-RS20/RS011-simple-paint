#include <QDebug>
#include "./headers/image.h"

image::image(QWidget *parent)
    : QWidget(parent),
      modified(false),
      drawing(false),
      whiteBackground(true),
      myColor(Qt::black)
{
    // Roots the widget to the top left even if resized
    setAttribute(Qt::WA_StaticContents);

    // TODO: hijerarhija klasa
    colorPicker = false;
    myWidth = 2;
}

image::~image(){}

bool image::openImage(const QString &fileName)
{
    QImage loadedImage;

    // If the image wasn't loaded leave this function
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size();

    resizeImage(&loadedImage, newSize);
    img = loadedImage;

    modified = false;
    update();
    return true;
}

void image::setPenColor(const QColor &newColor)
{
    myColor = newColor;
}

void image::setColorPicker()
{
    colorPicker = true;
    drawing = false;
}

// Color the image area with white
void image::clearImage()
{
    img.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

void image::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !colorPicker)
    {
        lastPoint = event->pos();
        drawing = true;
    }
}

void image::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
        drawLineTo(event->pos());
}

void image::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing)
    {
        drawLineTo(event->pos());
        drawing = false;
    }
    else if (colorPicker)
    {
        QColor pickedColor = img.pixelColor(event->pos());
        setPenColor(pickedColor);

        colorPicker = false;
        drawing = true;
    }
}

void image::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();

    painter.drawImage(dirtyRect, img, dirtyRect);
}

// TODO: ne radi bas kako treba, i treba slider
void image::resizeEvent(QResizeEvent *event)
{
    if ((width() > img.width() || height() > img.height()) && whiteBackground)
    {
        int newWidth = qMax(width()-20, img.width());
        int newHeight = qMax(height() + 120, img.height());
        resizeImage(&img, QSize(newWidth, newHeight));
        whiteBackground = false;
        update();
    }
    QWidget::resizeEvent(event);
}


void image::resizeImage(QImage *img, const QSize &newSize)
{
    // Check if we need to redraw the image
    if (img->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *img);
    *img = newImage;
}

void image::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&img);

    painter.setPen(QPen(myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawLine(lastPoint, endPoint);

    modified = true;
    int rad = (myWidth / 2) + 2;

    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}



