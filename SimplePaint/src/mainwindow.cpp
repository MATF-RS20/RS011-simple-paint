#include <iostream>
#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();

}

MainWindow::~MainWindow(){
    delete ui;
}

// void MainWindow::mousePressEvent(QMouseEvent *event) {}
// void MainWindow::mouseReleaseEvent(QMouseEvent *event) { event->pos();}
// void MainWindow::paintEvent(QPaintEvenet *event) {}

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


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Picture"),
            path,
            tr("Image Files (*.png *.jpg *.jpeg)")
           );

    if(!fileName.isEmpty() && !fileName.isNull()){
        auto index_of_slash = fileName.lastIndexOf("/");

        MainWindow::path = fileName.chopped(fileName.size() - index_of_slash);

        // TODO:   mozda ce biti napravljena klasa za sliku
        QImage img(fileName);
        QPixmap pm = QPixmap::fromImage(img);


        //predlazem da dodamo slider-e, pa i ako doda neko vecu sliku, videce se cela, samo ce
        //morati da pomera slider da gleda dalje
        //reserved_places dodat jer racuna velicinu celog prostora, a mi ga spustamo zatim i pomeramo udesno,
        //pa cisto da budemo da za sada sigurno staje u ceo prozor slika
        // velicina naseg prozora (mainwindow):
        QSize size = this->size();
        auto height = (size.height()-MainWindow::reserved_place)/(pm.height()*1.0);
        auto width  = (size.width()-MainWindow::reserved_place)/(pm.width()*1.0);

        auto factor = std::min(height, width);

        qDebug() << factor;
        qDebug() << "File: " << fileName;

        ui->image_label->setGeometry(10, 10,
                                     static_cast<int>(pm.width()*factor),
                                     static_cast<int>(pm.height()*factor));

        ui->image_label->setPixmap(pm);
        ui->image_label->setScaledContents(true);
    }
}

void MainWindow::on_actionColor_Pallete_triggered() {
    color = QColorDialog::getColor(color);
}

