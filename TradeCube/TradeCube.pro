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
    combotradedialog.cpp \
    TC/ComboTrader.cpp \
    TC/Dispatcher.cpp \
    TC/SPTrader.cpp \
    TC/SwingTrader.cpp \
    TC/TradeUnit.cpp \
    TC/DispatcherFactory.cpp \
    TC/Strategy.cpp

HEADERS  += mainwindow.h \
    swingtradedialog.h \
    combotradedialog.h \
    TC/Bar.h \
    TC/ComboOrder.h \
    TC/ComboTrader.h \
    TC/Dispatcher.h \
    TC/LogHandler.h \
    TC/OrderItem.h \
    TC/Position.h \
    TC/PriceItem.h \
    TC/QuoteItem.h \
    TC/SPTrader.h \
    TC/Strategy.h \
    TC/SwingTrader.h \
    TC/TradeCube.h \
    TC/TradeItem.h \
    TC/TradeUnit.h \
    TC/DispatcherFactory.h \
    TC/PlatformInfo.h

FORMS    += mainwindow.ui \
    swingtradedialog.ui \
    combotradedialog.ui

RESOURCES += \
    tradecube.qrc
