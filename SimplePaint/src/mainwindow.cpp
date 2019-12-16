#include <iostream>
#include <QtWidgets>
#include <QDebug>
#include "ui_mainwindow.h"
#include "headers/mainwindow.h"
#include "headers/image.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      color(Qt::black),
      path(QDir::home().path() + "/Pictures")
{
    ui->setupUi(this);
    QWidget::showMaximized();

    reserved_place = 50;

    // postavljanje centralnog widget-a
    scribbleArea = new image;
    setCentralWidget(scribbleArea);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionClose_triggered(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "The document has been modified.\nDo you want to save changes or discard them?",
                                  QMessageBox::Save  | QMessageBox::Discard | QMessageBox::Cancel );
    if (reply == QMessageBox::Discard) {
        QApplication::quit();
    }
    else if (reply == QMessageBox::Save){
        //TODO sacuvati
    }
}

void MainWindow::closeEvent(QCloseEvent* event){
    emit MainWindow::on_actionClose_triggered();
    event->ignore();
}

void MainWindow::on_actionOpen_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Picture"),
            path,
            tr("Image Files (*.png *.jpg *.jpeg)")
           );

    if(!fileName.isEmpty() && !fileName.isNull()){
        qDebug() << "File: " << fileName;
        auto index_of_slash = fileName.lastIndexOf("/");

        MainWindow::path = fileName.chopped(fileName.size() - index_of_slash);

        scribbleArea->openImage(fileName);
    }
}

void MainWindow::on_actionColor_Pallete_triggered() {
    color = QColorDialog::getColor(color);
    scribbleArea->setPenColor(color);
}

void MainWindow::on_actionColorPicker_triggered() {
    scribbleArea->setColorPicker();
}

/* Premesteno u klasu:
void MainWindow::openImage(QString filename){

    QImage img(filename);
    QPixmap pm = QPixmap::fromImage(img);

    QSize size = this->size(); // velicina naseg prozora (mainwindow)
    auto height = (size.height()-MainWindow::reserved_place)/(pm.height()*1.0);
    auto width  = (size.width()-MainWindow::reserved_place)/(pm.width()*1.0);

    auto factor = std::min(height, width);
    qDebug() << factor;

    pm.scaledToWidth(static_cast<int>(width*factor));

    ui->centralwidget->setGeometry(10, 10,
                                 static_cast<int>(pm.width()*factor),
                                 static_cast<int>(pm.height()*factor));
    centralWidget()->update();
}
*/

