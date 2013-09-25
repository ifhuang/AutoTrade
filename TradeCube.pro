#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T14:21:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TradeCube
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    swingtradedialog.cpp \
    combotradedialog.cpp

HEADERS  += mainwindow.h \
    swingtradedialog.h \
    combotradedialog.h

FORMS    += mainwindow.ui \
    swingtradedialog.ui \
    combotradedialog.ui

RESOURCES += \
    tradecube.qrc
