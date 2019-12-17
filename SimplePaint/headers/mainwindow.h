#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QFormLayout>
#include <QDialog>
#include <QLineEdit>
#include <QList>
#include <QDialogButtonBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QResizeEvent>
#include <QTextStream>
#include <QColorDialog>
#include <QImage>
#include <QSize>
#include <QCloseEvent>

class image;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void setColor(QColor col);

private slots:
    void on_actionClose_triggered();
    void on_actionOpen_triggered();
    void on_actionColor_Pallete_triggered();
    void on_actionColorPicker_triggered();

    void closeEvent(QCloseEvent*) override;

private:
    Ui::MainWindow *ui;

    QColor color;
    QString path;
    image *scribbleArea;
    int reserved_place;
protected:

};
#endif // MAINWINDOW_H
