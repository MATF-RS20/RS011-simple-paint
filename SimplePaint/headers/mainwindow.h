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
#include <QScrollArea>

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

signals:
    void colorChanged();
    void toolChanged(QString nameOfTool);
    void widthChanged();
    void needToSave(QString filename, const char* fileFormat);
    void needToOpenImg(const QString &filename);
    void needToCrop();
    void needToResize();
    void scaleIn();
    void scaleOut();
    void undo();
    void redo();
    void newSheet();


public slots:
    void activateUndo();

private slots:
    void on_actionClose_triggered();
    void closeEvent(QCloseEvent*) override;

    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionSave_triggered();
    void on_actionHelp_triggered();
    void on_actionCrop_triggered();
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionResize_triggered();

    void on_actionPencil_triggered();
    void on_actionErase_triggered();
    void on_actionColorPicker_triggered();
    void on_actionBrush_triggered();
    void on_actionLine_triggered();
    void on_actionBucket_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionTriangle_triggered();

    void on_actionColor_Pallete_triggered();

private:
    Ui::MainWindow *ui;

    QString path;
    QString fileName = "";
    QByteArray fileFormat = "png";
    image *scribbleArea;
    QScrollArea* scrollArea;
protected:

};
#endif // MAINWINDOW_H
