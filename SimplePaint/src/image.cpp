#include <QDebug>
#include "./headers/image.h"

// Zbog forward declaration, treba nam da kompajleru kazemo da se radi
// tamplate-u, osnosno da bi kompajler uspesno proverio sintaksu
template<>
image<>::image(QWidget *parent)
    : QWidget(parent)
{
    // Roots the widget to the top left even if resized
    setAttribute(Qt::WA_StaticContents);

    modified = false;
    drawing = false;
    myWidth = 2;
    myColor = Qt::black;
}

template<>
image<>::~image(){}

template<>
void image<>::resizeImage(QImage *img, const QSize &newSize)
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

// Used to load the image and place it in the widget
template<>
bool image<>::openImage(const QString &fileName)
{
    // Holds the image
    QImage loadedImage;

    // If the image wasn't loaded leave this function
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());

    //std::cerr << loadedImage.size().height() << "    " << loadedImage.size().width() << std::endl;
    //std::cerr << newSize.height() << "   "  << newSize.width() << std::endl;
    resizeImage(&loadedImage, newSize);
    img = loadedImage;

    modified = false;
    update();
    return true;
}

template<>
void image<>::setPenColor(const QColor &newColor)
{
    myColor = newColor;
}

// Color the image area with white
template<>
void image<>::clearImage()
{
    img.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

template<>
void image<>::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawing = true;
    }
}

template<>
void image<>::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&img);

    painter.setPen(QPen(myColor, myWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawLine(lastPoint, endPoint);

    modified = true;

    int rad = (myWidth / 2) + 2;

    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));

    lastPoint = endPoint;
}

template<>
void image<>::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
        drawLineTo(event->pos());
}

// If the button is released we set variables to stop drawing
template<>
void image<>::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing) {
        drawLineTo(event->pos());
        drawing = false;
    }
}

template<>
void image<>::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect dirtyRect = event->rect();

    painter.drawImage(dirtyRect, img, dirtyRect);
}

// TODO: ne radi bas kako treba jo uvek!!!!!!!!!!!!!!!!!!
template<>
void image<>::resizeEvent(QResizeEvent *event)
{
    if (width() > img.width() || height() > img.height()) {
        int newWidth = qMax(width() - 128, img.width());
        int newHeight = qMax(height() - 128, img.height());
        resizeImage(&img, QSize(newWidth, newHeight));
        update();
    }

    //QPixmap pm = QPixmap::fromImage(img);
    QWidget::resizeEvent(event);
}
