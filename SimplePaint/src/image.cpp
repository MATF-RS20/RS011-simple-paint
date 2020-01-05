#include <QDebug>
#include "headers/image.h"

image::image(QWidget *parent)
    : QWidget(parent)
    , modified(false)
    , whiteBackground(true)
    , myWidth(2)
    , primaryColor(Qt::black)
    , secondaryColor(Qt::white)
    , has_image(false)
    , crop(false)
{

    allTools.insert(std::pair<QString, Tool*>("pencil", new Pencil(&primaryColor, 2, &img)));
    allTools.insert(std::pair<QString, Tool*>("eraser", new Eraser(&secondaryColor, 6, &img)));
    allTools.insert(std::pair<QString, Tool*>("colorpicker", new ColorPicker(&primaryColor, &secondaryColor, &img)));
    allTools.insert(std::pair<QString, Tool*>("brush", new Brush(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("line", new Line(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("bucket", new Bucket(&primaryColor, &img)));
    allTools.insert(std::pair<QString, Tool*>("ellipse", new Ellipse(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("rect", new Rect(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("triangle", new Triangle(&primaryColor, myWidth, &img)));

    // initial tool
    tool = allTools.at("pencil");

    // Roots the widget to the top left even if resized
    setAttribute(Qt::WA_StaticContents);
}

image::~image() {}

void image::newSheet()
{
    int newWidth = 1234;
    int newHeight = 640;
    resizeImage(&img, QSize(newWidth, newHeight));
    clearImage();
    update();

    modified = false;
    has_image = false;
    imagesUndo = std::stack<QImage>{};
    imagesRedo = std::stack<QImage>{};
    whiteBackground = true;          // initial background
    myWidth = 2;
    primaryColor = Qt::black;
    secondaryColor = Qt::white;
    crop = false;
    tool = allTools.at("pencil");

    return;
}

bool image::openImage(const QString &fileName)
{
    QImage loadedImage;

    // If the image wasn't loaded leave this function
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size();

    resizeImage(&loadedImage, newSize);

    imagesUndo.push(img);
    img = loadedImage;

    modified = false;
    has_image = true;
    imagesRedo = std::stack<QImage>{};
    emit activatedUndo();
    update();
    return true;
}

bool image::saveAsImage(const QString &filename, const char *fileFormat)
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

void image::needToCrop()
{
    if(has_image)
        crop = true;
}

void image::cropImage()
{
    QRect rect(startPoint, finishPoint);
    QImage croppedImg = img.copy(rect);
    img = croppedImg;

    crop = false;
}

void image::scaleImageZoomIn()
{
    /*QSize size = img.size() * 0.5;
    QImage scaledImage = img.copy();
    resizeImage(&scaledImage, size);
    img = scaledImage;
    update();*/

  //  QPixmap scaledImage;
  //  scaledImage.convertFromImage(img);
    scaleFactor *= 1.25;
    QSize size = img.size() * scaleFactor;
    auto height = size.height();
    auto width = size.width();
    QPixmap scaledImage;
    scaledImage.convertFromImage(img);
    scaledImage.scaledToWidth(width);
    scaledImage.scaledToHeight(height);
    QImage image = scaledImage.toImage();
    resizeImage(&image, size);
    img = image;
    update();


}

void image::scaleImageZoomOut()
{
    scaleFactor *= 0.8;
    QSize size = img.size() * scaleFactor;
    auto height = size.height();
    auto width = size.width();
    QPixmap scaledImage;
    scaledImage.convertFromImage(img);
    scaledImage.scaledToWidth(width);
    scaledImage.scaledToHeight(height);
    QImage image = scaledImage.toImage();
    resizeImage(&image, size);
    img = image;
    update();
}

void image::setPenColor()
{
     auto answer =  QColorDialog::getColor(primaryColor);
     primaryColor = answer.isValid() ? answer : primaryColor;
}

void image::setBrushWidth()
{
    bool okay;

    int newWidth = QInputDialog::getInt(this, tr("Width"),
                                        tr("Select pen width:"),
                                        penWidth(),
                                        1, 50, 1, &okay);
    // Change the width
    if (okay) { tool->setWidth(newWidth); }
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
    modified = true;
    if(tool != allTools.at("colorpicker"))
    {
        imagesUndo.push(img);
        imagesRedo = std::stack<QImage>{};
        emit activatedUndo();
    }

    if(!crop) { tool->mouseClicked(event); }
    else if (crop && has_image && event->button() == Qt::LeftButton) { startPoint = event->pos(); }
    update();
}

void image::mouseMoveEvent(QMouseEvent *event)
{
    if(!crop) { tool->mouseMoved(event); }
    update();
}

void image::mouseReleaseEvent(QMouseEvent *event)
{
    if(!crop)
    {
        tool->mouseReleased(event);
    }
    else if (event->button() == Qt::LeftButton && has_image && crop)
    {
        finishPoint = event->pos();
        cropImage();
    }

    update();
}

void image::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();

    painter.drawImage(dirtyRect, img, dirtyRect);
}

void image::undoFunc()
{
    imagesRedo.push(img);
    img = imagesUndo.top();
    imagesUndo.pop();
    update();
}

void image::redoFunc()
{
    imagesUndo.push(img);
    img = imagesRedo.top();
    imagesRedo.pop();
    update();

}


void image::resizeEvent(QResizeEvent *event)
{

    if ((width() > img.width() || height() > img.height()) && whiteBackground)
    {
        int newWidth = qMax(width()-20, img.width());
        int newHeight = qMax(height() + 140, img.height());
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

void image::resizeCurrentImg()
{
    QString sizesStr = QInputDialog::getText(this, "Set new dimensions", tr("First enter one number for new width, then one for new height:"));
    QStringList sizesNums = sizesStr.split(" ");
    int newWidth = sizesNums.at(0).toInt();
    int newHeight = sizesNums.at(1).toInt();

    img = img.scaled(QSize(newWidth, newHeight));
    update();
}

void image::setTool(QString nameOfTool)
{
    tool = allTools.at(nameOfTool);
}
