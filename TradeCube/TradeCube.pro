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

LIBS += $(BOOST_ROOT)/stage/lib/libboost_date_time-vc110-mt-gd-1_54.lib

debug{
LIBS += ../x64/Debug/TC.lib
}

SOURCES += main.cpp\
    mainwindow.cpp \
    swingtradedialog.cpp \
    combotradedialog.cpp \
    logindialog.cpp \
    addcontractdialog.cpp \
    $(BOOST_ROOT)/libs/date_time/src/gregorian/greg_month.cpp \
    insertstrategydialog.cpp

HEADERS  += mainwindow.h \
    swingtradedialog.h \
    combotradedialog.h \
    iswingtradedialog.h \
    imainwindow.h \
    logindialog.h \
    addcontractdialog.h \
    insertstrategydialog.h

FORMS    += mainwindow.ui \
    swingtradedialog.ui \
    combotradedialog.ui \
    logindialog.ui \
    addcontractdialog.ui \
    insertstrategydialog.ui

RESOURCES += \
    tradecube.qrc
