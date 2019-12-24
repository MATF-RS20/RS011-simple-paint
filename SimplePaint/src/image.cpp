#include <QDebug>
#include "headers/image.h"

image::image(QWidget *parent)
    : QWidget(parent)
    , modified(false)
    , whiteBackground(true)
    , myWidth(2)
    , primaryColor(Qt::black)
    , secondaryColor(Qt::white)
{

    allTools.insert(std::pair<QString, Tool*>("pencil", new Pencil(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("eraser", new Eraser(&secondaryColor, 6, &img)));
    allTools.insert(std::pair<QString, Tool*>("colorpicker", new ColorPicker(&primaryColor, &secondaryColor, &img)));
    allTools.insert(std::pair<QString, Tool*>("brush", new Brush(&primaryColor, 5, &img)));
    allTools.insert(std::pair<QString, Tool*>("line", new Line(&primaryColor, myWidth, &img)));

    // initial tool
    tool = allTools.at("pencil");

    // Roots the widget to the top left even if resized
    setAttribute(Qt::WA_StaticContents);


}

image::~image() {}

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

bool image::saveImage(const QString &filename, const char *fileFormat)
{
    QImage imageToSave = img;
        resizeImage(&imageToSave, img.size());

    if (imageToSave.save(filename, fileFormat))
    {
        modified = false;
        return true;
    } else {
        return false;
    }
}

void image::setPenColor()
{
     auto answer =  QColorDialog::getColor(primaryColor);
     primaryColor = answer.isValid() ? answer : primaryColor;
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
    tool->mouseClicked(event);
    update();
}

void image::mouseMoveEvent(QMouseEvent *event)
{
    tool->mouseMoved(event);
    update();
}

void image::mouseReleaseEvent(QMouseEvent *event)
{
    tool->mouseReleased(event);
    update();
}

void image::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();

    painter.drawImage(dirtyRect, img, dirtyRect);
}

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

void image::setTool(QString nameOfTool)
{
    tool = allTools.at(nameOfTool);
}
