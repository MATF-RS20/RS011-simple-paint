#include <iostream>
#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::mousePressEvent(QMouseEvent *event) {}
// void MainWindow::mouseReleaseEvent(QMouseEvent *event) { event->pos();}
// void MainWindow::paintEvent(QPaintEvenet *event) {}

void MainWindow::on_actionClose_triggered()
{
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

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Picture"),
            QDir::currentPath(),
            tr("Image Files (*.png *.jpg *.jpeg)")
           );

    // TODO:             mozda ce biti napravljena klasa za sliku
    QImage img(fileName);
    QPixmap pm = QPixmap::fromImage(img);

    // velicina naseg prozora (mainwindow): QSize size = this->size();

    ui->image_label->setGeometry(10, 10, pm.width()/2, pm.height()/2);
    ui->image_label->setPixmap(pm);
    ui->image_label->setScaledContents(true);
}

void MainWindow::on_actionColor_Pallete_triggered() {
    color = QColorDialog::getColor(color);
}

