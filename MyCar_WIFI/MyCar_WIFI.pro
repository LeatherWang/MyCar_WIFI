#-------------------------------------------------
#
# Project created by QtCreator 2017-03-28T08:57:14
#
#-------------------------------------------------

QT       += core gui network serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MyCar_WIFI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scope.cpp \
    qcustomplot/qcustomplot.cpp \
    tcpsocket.cpp \
    serialtalk.cpp \
    form.cpp \
    dialogdatabase.cpp \
    algorithm.cpp

HEADERS  += \
    mainwindow.h \
    scope.h \
    qcustomplot/qcustomplot.h \
    form.h \
    dialogdatabase.h \
    algorithm.h \
    apinfo.h

FORMS    += mainwindow.ui \
    scope.ui \
    form.ui \
    dialogdatabase.ui
include(./qextserialport-1.2beta2/src/qextserialport.pri)

DISTFILES +=

RESOURCES += \
    image.qrc
