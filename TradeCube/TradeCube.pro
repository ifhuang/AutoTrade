#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T14:21:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TradeCube
TEMPLATE = app

DEFINES += NOMINMAX

INCLUDEPATH += $(BOOST_ROOT) \
    ../TC \
    $(QWT_ROOT)/src

LIBPATH += $(BOOST_ROOT)/stage/lib/

LIBS += $(QWT_ROOT)/lib/qwtd.lib

debug{
    contains(QMAKE_HOST.arch, x86_64) {
        LIBS += ../x64/Debug/TC.lib
    } else {
        LIBS += ../Debug/TC.lib
    }
}

SOURCES += main.cpp\
    mainwindow.cpp \
    swingtradedialog.cpp \
    combotradedialog.cpp \
    logindialog.cpp \
    addcontractdialog.cpp \
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
