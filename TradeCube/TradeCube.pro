#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T14:21:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TradeCube
TEMPLATE = app

INCLUDEPATH += $(BOOST_ROOT) \
    ../TC
LIBS += $(BOOST_ROOT)/stage/lib/libboost_date_time-vc110-mt-gd-1_54.lib \
    ../build-TC-Desktop_Qt_5_1_1_MSVC2012_OpenGL_64bit-Debug/debug/TC.lib

SOURCES += main.cpp\
    mainwindow.cpp \
    swingtradedialog.cpp \
    combotradedialog.cpp \
    logindialog.cpp \
    addcontractdialog.cpp \
    $(BOOST_ROOT)/libs/date_time/src/gregorian/greg_month.cpp

HEADERS  += mainwindow.h \
    swingtradedialog.h \
    combotradedialog.h \
    iswingtradedialog.h \
    imainwindow.h \
    logindialog.h \
    addcontractdialog.h \

FORMS    += mainwindow.ui \
    swingtradedialog.ui \
    combotradedialog.ui \
    logindialog.ui \
    addcontractdialog.ui

RESOURCES += \
    tradecube.qrc
