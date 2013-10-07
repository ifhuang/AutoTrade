#ifndef ISWINGTRADEDIALOG_H
#define ISWINGTRADEDIALOG_H

class PriceItem;

class ISwingTradeDialog
{
public:
    virtual ~ISwingTradeDialog(){}
    virtual void displayPriceItem(PriceItem* priceItem) = 0;
    virtual void displayPosition(double position) = 0;
    virtual void displayProfit(double profit) = 0;
};

#endif // ISWINGTRADEDIALOG_H
