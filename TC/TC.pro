QT -= gui

TARGET = TC
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += $(BOOST_ROOT)

SOURCES += ComboTrader.cpp \
    Dispatcher.cpp \
    SPTrader.cpp \
    SwingTrader.cpp \
    TradeUnit.cpp \
    DispatcherFactory.cpp \
    Strategy.cpp \
    Bar.cpp \
    ComboOrder.cpp \
    LogHandler.cpp \
    OrderItem.cpp \
    PriceItem.cpp \
    string_processor.cpp 

HEADERS += Bar.h \
    ComboOrder.h \
    ComboTrader.h \
    Dispatcher.h \
    LogHandler.h \
    OrderItem.h \
    Position.h \
    PriceItem.h \
    QuoteItem.h \
    SPTrader.h \
    Strategy.h \
    SwingTrader.h \
    TradeCube.h \
    TradeItem.h \
    TradeUnit.h \
    DispatcherFactory.h \
    PlatformInfo.h \
    constants.h \
    string_processor.h
