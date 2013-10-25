#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imainwindow.h"
#include <QMainWindow>

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItemModel>
#include "../TC/Dispatcher.h"
#include "../TC/OrderItem.h"
#include "../TC/PlatformInfo.h"
#include "../TC/Position.h"
#include "../TC/TradeItem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public IMainWindow, public QMainWindow
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
    // --------------------test slots--------------------

private:
    Ui::MainWindow *ui_;

    QComboBox *selcon_;
    QComboBox *ordertype_;
    QLineEdit *qty_;
    QLineEdit *price_;
    QComboBox *valid_;
    QPushButton *buy_;
    QPushButton *sell_;
    QMenu *swingmdiright_;
    QMenu *combomdiright_;
    QAction *insertswing_;
    QAction *insertcombo_;
    // counter for swing/combo trade dialog
    int swing_counter_;
    int combo_counter_;
    // tree model for positions tab in swing trade tab
    QStandardItemModel *swingpositionsmodel_;
    // table model for working orders / order history tab in swing trade tab
    QStandardItemModel *swingworkingordersmodel_;
    QStandardItemModel *swingorderhistorymodel_;

    PlatformInfo platforminfo_;
    Dispatcher *disp_;

    void showMaximized();
    void setupToolbar();
    void setupSwingRightPopup();
    void setupComboRightPopup();
    void setupPositionsTab();
    void setupWorkingOrdersTab();
    void setupOrderHistoryTab();
    void setupConnect();
    // resize components when resize mainwindow
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
