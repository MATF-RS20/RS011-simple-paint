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
    if (okay)
    {
        tool->setWidth(newWidth);
    }
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
    imagesUndo.push(img);
    imagesRedo = std::stack<QImage>{};
    emit activatedUndo();

    if(!crop)
    {
        tool->mouseClicked(event);
    }
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
    /*std::cout << "\nPRE OPERACIJA: " << std::endl;
    std::cout << "UNDO   undo: " << imagesUndo.size() << std::endl;
    std::cout << "UNDO   redo: " << imagesRedo.size() << std::endl;*/

 //   if(imagesUndo.empty())
   // {
     //   return;
   // }
    //else
    //{
      //  imagesRedo.push(imagesUndo.top());
       // imagesUndo.pop();

//        if(imagesUndo.empty())
  //      {
    //        clearImage();
      //      update();
            /*std::cout << "POSLE OPERACIJA\nUNDO   undo: " << imagesUndo.size() << std::endl;
            std::cout << "UNDO   redo: " << imagesRedo.size() << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;*/
        //    return;
       // }

        //QImage old = imagesUndo.top();
        //img = old;
        //update();

        /*std::cout << "POSLE OPERACIJA\nUNDO   undo: " << imagesUndo.size() << std::endl;
        std::cout << "UNDO   redo: " << imagesRedo.size() << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;*/

        //return;
   // }


    //if(imagesUndo.empty())
      //  return;


    imagesRedo.push(img);
    img = imagesUndo.top();
    imagesUndo.pop();
    update();
}

void image::redoFunc()
{
    /*
    std::cout << "\nPRE OPERACIJA: " << std::endl;
    std::cout << "REDO   undo: " << imagesUndo.size() << std::endl;
    std::cout << "REDO   redo: " << imagesRedo.size() << std::endl;
    */
    //if (imagesRedo.empty())
    //{
      //  return;
    //}
   // else
    //{
        //QImage old = imagesRedo.top();
        //imagesRedo.pop();
        //imagesUndo.push(old);

        //img = old;
        //update();
        /*
        std::cout << "POSLE\nREDO   undo: " << imagesUndo.size() << std::endl;
        std::cout << "REDO   redo: " << imagesRedo.size() << std::endl;*/
      //  return;
    //}

    //if(imagesRedo.empty())
      //  return;

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

void image::setTool(QString nameOfTool)
{
    tool = allTools.at(nameOfTool);
}
