#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T14:21:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TradeCube
TEMPLATE = app

INCLUDEPATH += C:/boost_1_54_0/
LIBS += "-LC:/boost_1_54_0/stage/lib/"

SOURCES += main.cpp\
        mainwindow.cpp \
    swingtradedialog.cpp \
    combotradedialog.cpp \
    logindialog.cpp \
    addcontractdialog.cpp \
    ../TC/ComboTrader.cpp \
    ../TC/Dispatcher.cpp \
    ../TC/SPTrader.cpp \
    ../TC/SwingTrader.cpp \
    ../TC/TradeUnit.cpp \
    ../TC/DispatcherFactory.cpp \
    ../TC/Strategy.cpp \
    ../TC/Bar.cpp \
    ../TC/ComboOrder.cpp \
    ../TC/LogHandler.cpp \
    ../TC/OrderItem.cpp \
    ../TC/PriceItem.cpp \
    ../TC/string_processor.cpp \
    C:\boost_1_54_0\libs\date_time\src\gregorian\greg_month.cpp

HEADERS  += mainwindow.h \
    swingtradedialog.h \
    combotradedialog.h \
    iswingtradedialog.h \
    imainwindow.h \
    logindialog.h \
    addcontractdialog.h \
    ../TC/Bar.h \
    ../TC/ComboOrder.h \
    ../TC/ComboTrader.h \
    ../TC/Dispatcher.h \
    ../TC/LogHandler.h \
    ../TC/OrderItem.h \
    ../TC/Position.h \
    ../TC/PriceItem.h \
    ../TC/QuoteItem.h \
    ../TC/SPTrader.h \
    ../TC/Strategy.h \
    ../TC/SwingTrader.h \
    ../TC/TradeCube.h \
    ../TC/TradeItem.h \
    ../TC/TradeUnit.h \
    ../TC/DispatcherFactory.h \
    ../TC/PlatformInfo.h \
    ../TC/constants.h \
    ../TC/string_processor.h

FORMS    += mainwindow.ui \
    swingtradedialog.ui \
    combotradedialog.ui \
    logindialog.ui \
    addcontractdialog.ui

RESOURCES += \
    tradecube.qrc
