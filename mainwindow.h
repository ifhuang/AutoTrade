#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItemModel>

#include "TC/Position.h"
#include "TC/OrderItem.h"
#include "TC/TradeItem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void displaySwingAddPositions(Position *position);
    void displaySwingUpdatePositions(Position *position);
    void displaySwingAddWorkingOrders(OrderItem *orderItem);
    void displaySwingUpdateWorkingOrders(OrderItem *orderItem);
    void displaySwingRemoveWorkingOrders();
    void displaySwingAddOrderHistory(TradeItem *orderItem);

private slots:    
    void new_swing_trade();    
    void new_combo_trade();
    void about();
    void activate_swing();
    void activate_combo();
    void update_swing_contract(QString contract);

    void add_swing_positions();
    void update_swing_positions();
    void add_swing_working_orders();
    void update_swing_working_orders();
    void remove_swing_working_orders();
    void add_swing_order_history();

private:
    Ui::MainWindow *ui;    
    QComboBox *selCon;
    QComboBox *orderType;
    QLineEdit *qty;
    QLineEdit *price;
    QComboBox *valid;
    QPushButton *buy;
    QPushButton *sell;

    int swing_counter;
    int combo_counter;

    QStandardItemModel *swingPositionsModel;
    QStandardItemModel *swingWorkingOrdersModel;
    QStandardItemModel *swingOrderHistoryModel;

    void resizeEvent(QResizeEvent* event);

};

#endif // MAINWINDOW_H
