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

#include <QUndoCommand>
#include <QUndoStack>
#include <QUndoView>

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


private slots:
    void on_actionClose_triggered();
    void closeEvent(QCloseEvent*) override;

    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionSave_triggered();
    void on_actionHelp_triggered();

    void on_actionPencil_triggered();
    void on_actionErase_triggered();
    void on_actionColorPicker_triggered();
    void on_actionBrush_triggered();
    void on_actionLine_triggered();
    void on_actionBucket_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();

    void on_actionColor_Pallete_triggered();

private:
    Ui::MainWindow *ui;

    QString path;
    QString fileName = "";
    QByteArray fileFormat = "png";
    image *scribbleArea;
protected:

};
#endif // MAINWINDOW_H
