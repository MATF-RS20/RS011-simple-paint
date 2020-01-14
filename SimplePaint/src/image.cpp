#include <QDebug>
#include <iterator>
#include "headers/image.h"

image::image(QWidget *parent)
    : QWidget(parent)
    , modified(false)
    , whiteBackground(true)
    , myWidth(2)
    , scaleFactor(1)
    , primaryColor(Qt::black)
    , secondaryColor(Qt::white)    
    , has_image(false)
    , crop(false)
    , img(QImage(1240, 680, QImage::Format_RGB32))
{

    img.fill(QColor(255,255,255));

    allTools.insert(std::pair<QString, Tool*>("pencil",
                                              new Pencil(&primaryColor, 2, &img)));
    allTools.insert(std::pair<QString, Tool*>("eraser",
                                              new Eraser(&secondaryColor, 6, &img)));
    allTools.insert(std::pair<QString, Tool*>("colorpicker",
                                              new ColorPicker(&primaryColor, &secondaryColor, &img)));
    allTools.insert(std::pair<QString, Tool*>("brush",
                                              new Brush(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("line",
                                              new Line(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("bucket",
                                              new Bucket(&primaryColor, &img)));
    allTools.insert(std::pair<QString, Tool*>("ellipse",
                                              new Ellipse(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("rect",
                                              new Rect(&primaryColor, myWidth, &img)));
    allTools.insert(std::pair<QString, Tool*>("triangle",
                                              new Triangle(&primaryColor, myWidth, &img)));

    /* initial tool set */
    tool = allTools.at("pencil");

    /* Roots the widget to the top left even if resized */
    setAttribute(Qt::WA_StaticContents);
}

image::~image() {
    for (auto i = std::cbegin(allTools); i != std::cend(allTools); i++) {
        delete allTools.at(i->first);
    }
}

/* new functionality's logic */
void image::newSheet() {
    img = QImage(1240, 680, QImage::Format_RGB32);
    //resizeImage(&img, QSize(newWidth, newHeight));
    clearImage();
    update();

    /* initial values */
    modified = false;
    has_image = false;
    imagesUndo = std::stack<QImage>{};
    imagesRedo = std::stack<QImage>{};
    whiteBackground = true;
    myWidth = 2;
    primaryColor = Qt::black;
    secondaryColor = Qt::white;
    crop = false;
    tool = allTools.at("pencil");
    setMinimumSize(img.size());

    return;
}

/* open functionality's logic */
bool image::openImage(const QString &fileName) {

    QImage loadedImage;

    /* If the image wasn't loaded leave this function */
    if (!loadedImage.load(fileName))
        return false;

    /* resize scribble area */
    QSize newSize = loadedImage.size();
    resizeImage(&loadedImage, newSize);

    imagesUndo.push(img);
    img = loadedImage;

    modified = false;
    has_image = true;

    imagesRedo = std::stack<QImage>{};
    emit activatedUndo();

    /* For scroll */
    setMinimumSize(newSize);
    /* show loaded image */
    update();
    return true;
}

/* save (as) functionality's logic */
bool image::saveAsImage(const QString &filename, const char *fileFormat) {

    if (img.save(filename, fileFormat)) {
        imagesUndo = std::stack<QImage>{};
        imagesRedo = std::stack<QImage>{};
        modified = false;
        return true;
    } else {
        return false;
    }
}

/* crop functionality's logic */
void image::cropImage() {
    QRect rect;
    if (startPoint.x() < finishPoint.x() && startPoint.y() < finishPoint.y()) {
        rect = QRect(startPoint, finishPoint);
    } else if (startPoint.x() > finishPoint.x() && startPoint.y() > finishPoint.y()){
        rect = QRect(finishPoint, startPoint);
    } else if (startPoint.x() < finishPoint.x()) {
        QPoint start(startPoint.x(), finishPoint.y());
        QPoint finish(finishPoint.x(), startPoint.y());
        rect = QRect(start, finish);
    } else {
        QPoint start(startPoint.x(), finishPoint.y());
        QPoint finish(finishPoint.x(), startPoint.y());
        rect = QRect(finish, start);
    }
    QImage croppedImg = img.copy(rect);
    img = croppedImg;

    setMinimumSize(img.size());
    crop = false;
}

void image::needToCrop() {
    if(has_image)
        crop = true;
}

/* TODO */
void image::scaleImageZoomIn() {
    scaleFactor += 1;
    scaleFactor = scaleFactor > 3 ? 3 : scaleFactor;
    setMinimumSize(QSize(img.size().rwidth()*scaleFactor, img.size().rheight()*scaleFactor));
    update();
}

void image::scaleImageZoomOut() {
    scaleFactor -= 1;
    scaleFactor = scaleFactor < 1 ? 1 : scaleFactor;
    setMinimumSize(QSize(img.size().rwidth()*scaleFactor, img.size().rheight()*scaleFactor));
    update();
}

/* set tools' color */
void image::setToolColor() {

    if(tool == allTools.at("eraser")) {
        auto answer =  QColorDialog::getColor(secondaryColor);
        secondaryColor = answer.isValid() ? answer : secondaryColor;
        return;
    }

     auto answer =  QColorDialog::getColor(primaryColor);
     primaryColor = answer.isValid() ? answer : primaryColor;
}

/* set brush's width */
void image::setBrushWidth() {
    bool okay;

    int newWidth = QInputDialog::getInt(this, tr("Width"),
                                        tr("Select pen width:"),
                                        penWidth(),
                                        1, 50, 1, &okay);
    /* Change the width */
    if (okay) { tool->setWidth(newWidth); }
}


/* Color the image area with white */
void image::clearImage() {
    img.fill(qRgb(255, 255, 255));
    modified = true;

    update();
}

/* mouse events */
void image::mousePressEvent(QMouseEvent *event) {

    event->setLocalPos(QPoint(event->pos().rx()/scaleFactor, event->pos().y()/scaleFactor));
    modified = true;

    if(tool != allTools.at("colorpicker")) {
        imagesUndo.push(img);
        imagesRedo = std::stack<QImage>{};
        emit activatedUndo();
    }

    if(!crop) {
        tool->mouseClicked(event);
    } else if (crop && has_image && event->button() == Qt::LeftButton) {
        startPoint = event->pos();
    }
    update();
}

void image::mouseMoveEvent(QMouseEvent *event) {

    event->setLocalPos(QPoint(event->pos().rx()/scaleFactor, event->pos().y()/scaleFactor));
    if(!crop) { tool->mouseMoved(event); }
    update();
}

void image::mouseReleaseEvent(QMouseEvent *event) {
    event->setLocalPos(QPoint(event->pos().rx()/scaleFactor, event->pos().y()/scaleFactor));
    if(!crop)
        tool->mouseReleased(event);
    else if (event->button() == Qt::LeftButton && has_image && crop) {
        finishPoint = event->pos();
        cropImage();
    }

    update();
} /* end of mouse events */

/* paint event */
void image::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();

    painter.drawImage(dirtyRect, img.scaled(img.size().rwidth()*scaleFactor,
                                            img.size().rheight()*scaleFactor), dirtyRect);
}

/* undo functionality's logic */
void image::undoFunc() {
    imagesRedo.push(img);
    img = imagesUndo.top();
    imagesUndo.pop();
    setMinimumSize(QSize(img.size().rwidth()*scaleFactor,
                         img.size().rheight()*scaleFactor));

    update();
}

/* redo functionality's's logic */
void image::redoFunc() {
    imagesUndo.push(img);
    img = imagesRedo.top();
    imagesRedo.pop();
    setMinimumSize(QSize(img.size().rwidth()*scaleFactor,
                         img.size().rheight()*scaleFactor));

    update();
}



/* resize image or scribble area */
void image::resizeImage(QImage *img, const QSize &newSize) {

    /* Check if we need to redraw the image */
    if (img->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    /* For scroll */
    //setMinimumSize(newSize);

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *img);
    *img = newImage;
}

/* resize current loaded img. Resize functionality's logic */
void image::resizeCurrentImg() {
    /*QString sizesStr = QInputDialog::getText(this,
                                             "Set new dimensions",
                                             tr("First enter one number for new width, then one for new height:")
                                             );
    */
    bool okayW;
    int newWidth = QInputDialog::getInt(this, tr("Width"),
                                        tr("Select width:"),
                                        200,
                                        1, 2000, 1, &okayW);
    bool okayH;
    int newHeight = QInputDialog::getInt(this, tr("Height"),
                                        tr("Select height:"),
                                        200,
                                        1, 2000, 1, &okayH);

    /* Change size */
    if (okayW && okayH) {
        imagesUndo.push(img);
        img = img.scaled(QSize(newWidth, newHeight));

        /* For scroll */
        setMinimumSize(QSize(newWidth, newHeight));

        imagesRedo = std::stack<QImage>{};
        emit activatedUndo();
    }


    update();
}

/* change current tool */
void image::setTool(QString nameOfTool) {
    tool = allTools.at(nameOfTool);
}
