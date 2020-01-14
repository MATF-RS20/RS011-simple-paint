#include <iostream>
#include <QtWidgets>
#include <QDebug>
#include "ui_mainwindow.h"
#include "headers/mainwindow.h"
#include "headers/image.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , path(QDir::home().path() + "/Pictures")
{
    ui->setupUi(this);
    QWidget::showMaximized();

    scribbleArea = new image(this);
    scribbleArea->setMinimumSize(scribbleArea->getImage().size());

    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scribbleArea);
    setCentralWidget(scrollArea);

    QObject::connect(this,
                     &MainWindow::colorChanged,
                     scribbleArea,
                     &image::setToolColor);

    QObject::connect(this,
                     &MainWindow::needToSave,
                     scribbleArea,
                     &image::saveAsImage);

    QObject::connect(this,
                     &MainWindow::needToOpenImg,
                     scribbleArea,
                     &image::openImage);

    QObject::connect(this,
                     &MainWindow::scaleIn,
                     scribbleArea,
                     &image::scaleImageZoomIn);


    QObject::connect(this,
                     &MainWindow::scaleOut,
                     scribbleArea,
                     &image::scaleImageZoomOut);

    QObject::connect(this,
                     &MainWindow::undo,
                     scribbleArea,
                     &image::undoFunc);

    QObject::connect(this,
                     &MainWindow::redo,
                     scribbleArea,
                     &image::redoFunc);

    QObject::connect(this,
                     &MainWindow::widthChanged,
                     scribbleArea,
                     &image::setBrushWidth);

    QObject::connect(this,
                     &MainWindow::toolChanged,
                     scribbleArea,
                     &image::setTool);

    QObject::connect(this,
                     &MainWindow::needToCrop,
                     scribbleArea,
                     &image::needToCrop);

    QObject::connect(scribbleArea,
                     &image::activatedUndo,
                     this,
                     &MainWindow::activateUndo);

    QObject::connect(this,
                     &MainWindow::newSheet,
                     scribbleArea,
                     &image::newSheet);

    QObject::connect(this,
                     &MainWindow::needToResize,
                     scribbleArea,
                     &image::resizeCurrentImg);

    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete scribbleArea;
    delete ui;
}

/* close event */
void MainWindow::on_actionClose_triggered() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "The document has been modified.\nDo you want to save changes or discard them?",
                                  QMessageBox::Save  | QMessageBox::Discard | QMessageBox::Cancel );

    if (reply == QMessageBox::Discard)
        QApplication::quit();
    else if (reply == QMessageBox::Save) {
        on_actionSave_triggered();
        QApplication::quit();
    }
}

void MainWindow::closeEvent(QCloseEvent* event) {
    emit ui->actionClose->triggered();
    event->ignore();
}

/* new */
void MainWindow::on_actionNew_triggered() {
    on_actionSave_triggered();
    fileName = "";

    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    emit newSheet();
}

/* open */
void MainWindow::on_actionOpen_triggered() {

    QString filename = QFileDialog::getOpenFileName(this,
            tr("Open Picture"),
            path,
            tr("Image Files (*.png *.jpg *.jpeg)")
           );

    if(!filename.isEmpty() && !filename.isNull()) {
        auto index_of_slash = filename.lastIndexOf("/");

        MainWindow::path = filename.chopped(filename.size() - index_of_slash);
        emit needToOpenImg(filename);
    }
}

/* save as */
void MainWindow::on_actionSave_as_triggered() {
    QString initialPath = MainWindow::path + "/untitled." + fileFormat;

    fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                   initialPath,
                                   tr("%1 Files (*.%2);;All Files (*)")
                                   .arg(QString::fromLatin1(fileFormat.toUpper()))
                                   .arg(QString::fromLatin1(fileFormat)));

    if (fileName.isEmpty())
        return;

    emit needToSave(fileName, fileFormat.constData());
}

/* save */
void MainWindow::on_actionSave_triggered() {

    if(fileName == "") {
        on_actionSave_as_triggered();
        return;
    }
    emit needToSave(fileName, fileFormat.constData());
}

/* help */
void MainWindow::on_actionHelp_triggered() {

    QMessageBox::information(
        this,
        tr("Help"),
        tr("Welcome to Simple Paint!\n\n"
           "Simple Paint is a program for drawing and simple image manipulation, similar to the existing Paint program."
           "\nUsage:\nOn the left is a toolbar with painting tools. Selecting the desired tool is done by clicking on the right icon."
           " In the upper left corner there is a menu with additional functionalities:\n"
           "1. New - Starts new work.\n"
           "2. Open - Opens an image.\n"
           "3. Save/Save As - Saves the current image. Format: PNG.\n"
           "4. Close - Closes current work and Simple Paint app.\n"
           "5. Undo/Redo - Undoes last change / returns last change.\n"
           "6. Theme - Changes the appereance of Simple Paint app.\n"
           "7. Zoom in/Zoom out - takes closer/wider look at the current work.\n"
           "8. Resize - Resizes current image.\n"
           "9. Crop - Crops selected area of the current image.\n") );
}

void MainWindow::on_actionZoom_In_triggered() { emit scaleIn(); }

void MainWindow::on_actionZoom_Out_triggered() { emit scaleOut(); }

/* undo */
void MainWindow::on_actionUndo_triggered() {
    ui->actionRedo->setEnabled(true);

    emit undo();

    if(scribbleArea->imagesUndo.empty())
        ui->actionUndo->setEnabled(false);
}

void MainWindow::activateUndo() {
    ui->actionUndo->setEnabled(true);
    ui->actionRedo->setEnabled(false);
}

/* redo */
void MainWindow::on_actionRedo_triggered() {

    ui->actionUndo->setEnabled(true);

    emit redo();

    if(scribbleArea->imagesRedo.empty())
        ui->actionRedo->setEnabled(false);
}

/* tools */
void MainWindow::on_actionPencil_triggered() { emit toolChanged("pencil"); }
void MainWindow::on_actionErase_triggered() { emit toolChanged("eraser"); }
void MainWindow::on_actionColorPicker_triggered() { emit toolChanged("colorpicker"); }

void MainWindow::on_actionBrush_triggered() {
    emit toolChanged("brush");
    emit widthChanged();
}

void MainWindow::on_actionLine_triggered() {
    emit toolChanged("line");
    emit widthChanged();
}

void MainWindow::on_actionBucket_triggered() { emit toolChanged("bucket"); }

void MainWindow::on_actionRectangle_triggered() {
    emit toolChanged("rect");
    emit widthChanged();
}

void MainWindow::on_actionEllipse_triggered() {
    emit toolChanged("ellipse");
    emit widthChanged();
}

void MainWindow::on_actionTriangle_triggered() {
    emit toolChanged("triangle");
    emit widthChanged();
}

/* color dialog */
void MainWindow::on_actionColor_Pallete_triggered() {
    emit colorChanged();
}

void MainWindow::on_actionCrop_triggered() { emit needToCrop(); }
void MainWindow::on_actionResize_triggered() { emit needToResize(); }
