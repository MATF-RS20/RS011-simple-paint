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
                     &image::saveImage);

    QObject::connect(this,
                     &MainWindow::needToOpenImg,
                     scribbleArea,
                     &image::openImage);

    QObject::connect(this,
                     &MainWindow::signalSetWidth,
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
        //TODO sacuvati
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{   emit ui->actionClose->triggered();
    event->ignore();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Picture"),
            path,
            tr("Image Files (*.png *.jpg *.jpeg)")
           );

    if(!fileName.isEmpty() && !fileName.isNull())
    {
        auto index_of_slash = fileName.lastIndexOf("/");

        MainWindow::path = fileName.chopped(fileName.size() - index_of_slash);
        emit needToOpenImg(fileName);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QByteArray fileFormat = "png";

    QString initialPath = MainWindow::path + "/untitled." + fileFormat;

    QString filename = QFileDialog::getSaveFileName(this, tr("Save As"),
                                   initialPath,
                                   tr("%1 Files (*.%2);;All Files (*)")
                                   .arg(QString::fromLatin1(fileFormat.toUpper()))
                                   .arg(QString::fromLatin1(fileFormat)));

    if (filename.isEmpty())
            return;

    emit needToSave(filename, fileFormat.constData());
}

void MainWindow::on_actionColor_Pallete_triggered()
{
    emit colorChanged();
}

void MainWindow::on_actionColorPicker_triggered()
{
    emit toolChanged("colorpicker");
}

void MainWindow::on_actionPencil_triggered()
{
    emit toolChanged("pencil");
}

void MainWindow::on_actionErase_triggered()
{
    emit toolChanged("eraser");
}

void MainWindow::on_actionBrush_triggered()
{
    emit signalSetWidth();
    emit toolChanged("brush");
}

void MainWindow::on_actionLine_triggered()
{
    emit toolChanged("line");
}

void MainWindow::on_actionBucket_triggered()
{
    emit toolChanged("bucket");
}

void MainWindow::on_actionRectangle_triggered()
{
    emit toolChanged("rect");
}

void MainWindow::on_actionEllipse_triggered()
{
    emit toolChanged("ellipse");
}
