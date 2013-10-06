#ifndef SWINGTRADEDIALOG_H
#define SWINGTRADEDIALOG_H

#include <QDialog>
#include <QToolBar>
#include <QMenu>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCloseEvent>
#include "TC/PriceItem.h"
#include "TC/SwingTrader.h"
#include "TC/Dispatcher.h"

namespace Ui {
class SwingTradeDialog;
}

class SwingTrader;

class SwingTradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SwingTradeDialog(QString &contract, int tradeId, Dispatcher *disp, QWidget *parent = 0);
    ~SwingTradeDialog();
    QString getSwingContract();

    // display interface for price/position/profit
    void displayPriceItem(PriceItem* priceItem);
    void displayPosition(double position);
    void displayProfit(double profit);

signals:
    // emit by add/modify/remove contract
    void update_contract(QString contract);

private slots:
    // right popup menu in swing trade dialog
    void on_tab_customContextMenuRequested();

    // popup menu for strategy
    void on_trigger_pb2();

    void add_contract();
    void modify_contract();
    void remove_contract();

    void insert_strategy();
    void set_strategy();
    void remove_strategy();

private:
    Ui::SwingTradeDialog *ui;
    QToolBar *toolbar;
    QMenu *pb2_menu;
    QMenu *swingright;
    QPushButton *pb1;
    QLabel *label_strategy;
    QPushButton *pb2;
    QComboBox *cb;
    QPushButton *pb3;
    QPushButton *pb4;
    QAction *pb2_menu_open;
    QAction *pb2_menu_attr;
    QAction *pb2_menu_auto;
    QAction *pb2_menu_warn;
    QAction *swingright_setwin;
    QAction *swingright_insstr;
    QAction *swingright_setstr;
    QAction *swingright_remstr;
    QAction *swingright_addcon;
    QAction *swingright_modcon;
    QAction *swingright_remcon;

    QString swing_contract;

    SwingTrader *swingtrader;
    DWORD tbtid;
    Dispatcher *disp;
};

#endif // SWINGTRADEDIALOG_H
