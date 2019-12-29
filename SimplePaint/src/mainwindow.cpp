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
    , scribbleArea(new image)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    setCentralWidget(scribbleArea);

    QObject::connect(this,
                     &MainWindow::colorChanged,
                     scribbleArea,
                     &image::setPenColor);

    QObject::connect(this,
                     &MainWindow::needToSave,
                     scribbleArea,
                     &image::saveAsImage);

    QObject::connect(this,
                     &MainWindow::needToOpenImg,
                     scribbleArea,
                     &image::openImage);

    QObject::connect(this,
                     &MainWindow::widthChanged,
                     scribbleArea,
                     &image::setBrushWidth);

    QObject::connect(this,
                     &MainWindow::toolChanged,
                     scribbleArea,
                     &image::setTool);

    qApp->setStyleSheet("QMainWindow { background: rgb(235, 180, 255); }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "The document has been modified.\nDo you want to save changes or discard them?",
                                  QMessageBox::Save  | QMessageBox::Discard | QMessageBox::Cancel );
    if (reply == QMessageBox::Discard)
        QApplication::quit();
    else if (reply == QMessageBox::Save){
        on_actionSave_triggered();
        QApplication::quit();
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{   emit ui->actionClose->triggered();
    event->ignore();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
            tr("Open Picture"),
            path,
            tr("Image Files (*.png *.jpg *.jpeg)")
           );

    if(!filename.isEmpty() && !filename.isNull())
    {
        auto index_of_slash = filename.lastIndexOf("/");

        MainWindow::path = filename.chopped(filename.size() - index_of_slash);
        emit needToOpenImg(filename);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
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

void MainWindow::on_actionSave_triggered()
{
    if(fileName == "")
    {
        on_actionSave_as_triggered();
        return;
    }
    emit needToSave(fileName, fileFormat.constData());
}

void MainWindow::on_actionPencil_triggered()
{
    emit toolChanged("pencil");
}

void MainWindow::on_actionErase_triggered()
{
    emit toolChanged("eraser");
}

void MainWindow::on_actionColorPicker_triggered()
{
    emit toolChanged("colorpicker");
}

void MainWindow::on_actionBrush_triggered()
{
    emit toolChanged("brush");
    emit widthChanged();
}

void MainWindow::on_actionLine_triggered()
{
    emit toolChanged("line");
    emit widthChanged();
}

void MainWindow::on_actionBucket_triggered()
{
    emit toolChanged("bucket");
}

void MainWindow::on_actionRectangle_triggered()
{
    emit toolChanged("rect");
    emit widthChanged();
}

void MainWindow::on_actionEllipse_triggered()
{
    emit toolChanged("ellipse");
    emit widthChanged();
}

void MainWindow::on_actionColor_Pallete_triggered()
{
    emit colorChanged();
}
