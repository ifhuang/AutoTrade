#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

class OrderItem;

class IMainWindow
{
public:
    virtual ~IMainWindow(){}
    virtual void displaySwingAddWorkingOrders(OrderItem *orderItem) = 0;
};

#endif // IMAINWINDOW_H
