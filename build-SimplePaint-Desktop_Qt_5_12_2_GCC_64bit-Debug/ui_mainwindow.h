/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionResize;
    QAction *actionCrop;
    QAction *actionHelp;
    QAction *actionPencil;
    QAction *actionErase;
    QAction *actionBucket;
    QAction *actionBrush;
    QAction *actionColorPicker;
    QAction *actionLine;
    QAction *actionTriangle;
    QAction *actionRectangle;
    QAction *actionElipse;
    QAction *actionTheme;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionColor_Pallete;
    QWidget *centralwidget;
    QLabel *image_label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuImage;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 521);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QString::fromUtf8("actionResize"));
        actionCrop = new QAction(MainWindow);
        actionCrop->setObjectName(QString::fromUtf8("actionCrop"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionPencil = new QAction(MainWindow);
        actionPencil->setObjectName(QString::fromUtf8("actionPencil"));
        actionPencil->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPencil->setIcon(icon);
        actionErase = new QAction(MainWindow);
        actionErase->setObjectName(QString::fromUtf8("actionErase"));
        actionErase->setCheckable(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionErase->setIcon(icon1);
        actionBucket = new QAction(MainWindow);
        actionBucket->setObjectName(QString::fromUtf8("actionBucket"));
        actionBucket->setCheckable(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/bucket.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBucket->setIcon(icon2);
        actionBrush = new QAction(MainWindow);
        actionBrush->setObjectName(QString::fromUtf8("actionBrush"));
        actionBrush->setCheckable(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/brush.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBrush->setIcon(icon3);
        actionColorPicker = new QAction(MainWindow);
        actionColorPicker->setObjectName(QString::fromUtf8("actionColorPicker"));
        actionColorPicker->setCheckable(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/colorPicker.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColorPicker->setIcon(icon4);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionLine->setCheckable(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon5);
        actionTriangle = new QAction(MainWindow);
        actionTriangle->setObjectName(QString::fromUtf8("actionTriangle"));
        actionTriangle->setCheckable(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTriangle->setIcon(icon6);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionRectangle->setCheckable(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon7);
        actionElipse = new QAction(MainWindow);
        actionElipse->setObjectName(QString::fromUtf8("actionElipse"));
        actionElipse->setCheckable(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionElipse->setIcon(icon8);
        actionTheme = new QAction(MainWindow);
        actionTheme->setObjectName(QString::fromUtf8("actionTheme"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionColor_Pallete = new QAction(MainWindow);
        actionColor_Pallete->setObjectName(QString::fromUtf8("actionColor_Pallete"));
        actionColor_Pallete->setCheckable(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/pallete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColor_Pallete->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        image_label = new QLabel(centralwidget);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setGeometry(QRect(50, 26, 651, 401));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuImage = new QMenu(menubar);
        menuImage->setObjectName(QString::fromUtf8("menuImage"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setGeometry(QRect(307, 163, 148, 69));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        toolBar->setMaximumSize(QSize(16777215, 16777215));
        toolBar->setAutoFillBackground(false);
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::LeftToolBarArea);
        toolBar->setIconSize(QSize(30, 30));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuImage->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionTheme);
        menuEdit->addSeparator();
        menuEdit->addAction(actionZoom_In);
        menuEdit->addAction(actionZoom_Out);
        menuImage->addAction(actionResize);
        menuImage->addAction(actionCrop);
        menuHelp->addAction(actionHelp);
        toolBar->addAction(actionPencil);
        toolBar->addAction(actionErase);
        toolBar->addAction(actionBrush);
        toolBar->addAction(actionBucket);
        toolBar->addAction(actionColorPicker);
        toolBar->addAction(actionLine);
        toolBar->addAction(actionTriangle);
        toolBar->addAction(actionRectangle);
        toolBar->addAction(actionElipse);
        toolBar->addSeparator();
        toolBar->addAction(actionColor_Pallete);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SimplePaint", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionResize->setText(QApplication::translate("MainWindow", "Resize", nullptr));
        actionCrop->setText(QApplication::translate("MainWindow", "Crop", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", nullptr));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("MainWindow", "Help", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionPencil->setText(QApplication::translate("MainWindow", "Pencil", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPencil->setToolTip(QApplication::translate("MainWindow", "Pencil", nullptr));
#endif // QT_NO_TOOLTIP
        actionErase->setText(QApplication::translate("MainWindow", "Erase", nullptr));
#ifndef QT_NO_TOOLTIP
        actionErase->setToolTip(QApplication::translate("MainWindow", "Erase", nullptr));
#endif // QT_NO_TOOLTIP
        actionBucket->setText(QApplication::translate("MainWindow", "Bucket", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBucket->setToolTip(QApplication::translate("MainWindow", "Bucket", nullptr));
#endif // QT_NO_TOOLTIP
        actionBrush->setText(QApplication::translate("MainWindow", "Brush", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBrush->setToolTip(QApplication::translate("MainWindow", "Brush", nullptr));
#endif // QT_NO_TOOLTIP
        actionColorPicker->setText(QApplication::translate("MainWindow", "ColorPicker", nullptr));
#ifndef QT_NO_TOOLTIP
        actionColorPicker->setToolTip(QApplication::translate("MainWindow", "ColorPicker", nullptr));
#endif // QT_NO_TOOLTIP
        actionLine->setText(QApplication::translate("MainWindow", "Line", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLine->setToolTip(QApplication::translate("MainWindow", "Line", nullptr));
#endif // QT_NO_TOOLTIP
        actionTriangle->setText(QApplication::translate("MainWindow", "Triangle", nullptr));
#ifndef QT_NO_TOOLTIP
        actionTriangle->setToolTip(QApplication::translate("MainWindow", "Triangle", nullptr));
#endif // QT_NO_TOOLTIP
        actionRectangle->setText(QApplication::translate("MainWindow", "Rectangle", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRectangle->setToolTip(QApplication::translate("MainWindow", "Rectangle", nullptr));
#endif // QT_NO_TOOLTIP
        actionElipse->setText(QApplication::translate("MainWindow", "Elipse", nullptr));
#ifndef QT_NO_TOOLTIP
        actionElipse->setToolTip(QApplication::translate("MainWindow", "Elipse", nullptr));
#endif // QT_NO_TOOLTIP
        actionTheme->setText(QApplication::translate("MainWindow", "Theme", nullptr));
#ifndef QT_NO_TOOLTIP
        actionTheme->setToolTip(QApplication::translate("MainWindow", "Change theme", nullptr));
#endif // QT_NO_TOOLTIP
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In ", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl++", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        actionColor_Pallete->setText(QApplication::translate("MainWindow", "Color Pallete", nullptr));
#ifndef QT_NO_TOOLTIP
        actionColor_Pallete->setToolTip(QApplication::translate("MainWindow", "Choose Color", nullptr));
#endif // QT_NO_TOOLTIP
        image_label->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuImage->setTitle(QApplication::translate("MainWindow", "Image", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
