#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

class OrderItem;
class TradeItem;

class IMainWindow
{
public:
    virtual ~IMainWindow(){}
    virtual void displaySwingAddWorkingOrders(OrderItem *orderItem) = 0;
    virtual void displaySwingUpdateWorkingOrders(long orderRefId, OrderItem *orderItem) = 0;
    virtual void displaySwingRemoveWorkingOrders(long orderRefId) = 0;
    virtual void displaySwingAddOrderHistory(TradeItem *tradeItem) = 0;
};

#endif // IMAINWINDOW_H
