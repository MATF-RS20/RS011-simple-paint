QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple_paint
TEMPLATE = app

CONFIG += c++17 #eventualno da se stavi 14

QMAKE_CXXFLAGS += -std=c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#trenutno se ne koristi, ali ce biti korisceno kad krenemo sa radom, pa cemo otkomentarisati
#INCLUDEPATH += /usr/local/include/opencv4
#LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_dnn

SOURCES += \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    ./src/image.cpp \
    ./src/tool.cpp \
    ./src/pencil.cpp \
    ./src/eraser.cpp \
    ./src/colorpicker.cpp

HEADERS += \
    ./headers/mainwindow.h \
    ./headers/image.h \ \
    ./headers/tool.h \
    ./headers/pencil.h \
    ./headers/eraser.h \
    ./headers/colorpicker.h

FORMS += \
    ./forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resources/icons.qrc
