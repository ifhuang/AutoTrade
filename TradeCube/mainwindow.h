#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItemModel>
#include "../TC/Position.h"
#include "../TC/OrderItem.h"
#include "../TC/TradeItem.h"
#include "../TC/Dispatcher.h"
#include "../TC/PlatformInfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // display interface for add/update positions tab in swing trade tab
    void displaySwingAddPositions(Position *position);
    void displaySwingUpdatePositions(Position *position);
    // display interface for add/update/remove working orders tab in swing trade tab
    virtual void displaySwingAddWorkingOrders(OrderItem *orderItem) override;
    virtual void displaySwingUpdateWorkingOrders(long orderRefId, OrderItem *orderItem) override;
    virtual void displaySwingRemoveWorkingOrders(long orderRefId) override;
    // display interface for add order history tab in swing trade tab
    virtual void displaySwingAddOrderHistory(TradeItem *tradeItem) override;

private slots:    
    // insert swing/combo trade dialog
    void new_swing_trade();
    void new_combo_trade();
    // about tradecube
    void about();
    // update toolbar using active swing trade dialog in mdi area
    void activate_swing();
    void activate_combo();
    // update toolbar add/modify/remove contract of swing trade dialog
    void update_swing_contract(QString contract);
    // log in and connect to dispatcher
    void connect_dispatcher();
    // right popup menu for swing/combo mdi area
    void click_swing_right();
    void click_combo_right();
    // --------------------test slots--------------------
    // test for display interface for add/update positions tab in swing trade tab
    void add_swing_positions();
    void update_swing_positions();
    // test for display interface for add/update/remove working orders tab in swing trade tab
    // test for display interface for add order history tab in swing trade tab
    void add_swing_order_history();
    // --------------------test slots--------------------

private:
    Ui::MainWindow *ui;    

    QComboBox *selcon;
    QComboBox *ordertype;
    QLineEdit *qty;
    QLineEdit *price;
    QComboBox *valid;
    QPushButton *buy;
    QPushButton *sell;
    QMenu *swingmdiright;
    QMenu *combomdiright;
    QAction *insertswing;
    QAction *insertcombo;
    // counter for swing/combo trade dialog
    int swing_counter;
    int combo_counter;
    // tree model for positions tab in swing trade tab
    QStandardItemModel *swingpositionsmodel;
    // table model for working orders / order history tab in swing trade tab
    QStandardItemModel *swingworkingordersmodel;
    QStandardItemModel *swingorderhistorymodel;

    PlatformInfo platforminfo;
    Dispatcher *disp;

    // resize components when resize mainwindow
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
