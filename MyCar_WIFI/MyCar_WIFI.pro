#-------------------------------------------------
#
# Project created by QtCreator 2017-03-28T08:57:14
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MyCar_WIFI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scope.cpp \
    qcustomplot/qcustomplot.cpp

HEADERS  += \
    mainwindow.h \
    scope.h \
    qcustomplot/qcustomplot.h

FORMS    += mainwindow.ui \
    scope.ui
include(./qextserialport-1.2beta2/src/qextserialport.pri)

DISTFILES +=
