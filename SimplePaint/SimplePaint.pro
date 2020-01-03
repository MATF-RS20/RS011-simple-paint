QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple_paint
TEMPLATE = app

CONFIG += c++17 #eventualno da se stavi 14

QMAKE_CXXFLAGS += -std=c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    ./src/image.cpp \
    ./src/tool.cpp \
    ./src/pencil.cpp \
    ./src/eraser.cpp \
    ./src/colorpicker.cpp \
    ./src/brush.cpp \
    ./src/line.cpp \
    ./src/bucket.cpp \
    ./src/ellipse.cpp \
    ./src/rect.cpp \
    ./src/triangle.cpp

HEADERS += \
    ./headers/mainwindow.h \
    ./headers/image.h \ \
    ./headers/tool.h \
    ./headers/pencil.h \
    ./headers/eraser.h \
    ./headers/colorpicker.h \
    ./headers/brush.h \
    ./headers/line.h \
    ./headers/bucket.h \
    ./headers/ellipse.h \
    ./headers/rect.h \
    ./headers/triangle.h

FORMS += \
    ./forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resources/icons.qrc
