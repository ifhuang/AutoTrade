#ifndef SWINGTRADEDIALOG_H
#define SWINGTRADEDIALOG_H

#include <QDialog>
#include "iswingtradedialog.h"
#include <QToolBar>
#include <QMenu>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCloseEvent>
#include "../TC/PriceItem.h"
#include "../TC/SwingTrader.h"
#include "../TC/Dispatcher.h"

namespace Ui {
class SwingTradeDialog;
}

class SwingTrader;

class SwingTradeDialog : public QDialog, public ISwingTradeDialog
{
    Q_OBJECT

public:
    explicit SwingTradeDialog(QString exchange_contract, int tradeId, Dispatcher *disp, QWidget *parent = 0);
    virtual ~SwingTradeDialog();
    QString getExchangeContract();
    // display interface for price/position/profit
    virtual void displayPriceItem(PriceItem *priceItem) override;
    virtual void displayPosition(double position) override;
    virtual void displayProfit(double profit) override;

signals:
    // emit by add/modify/remove contract to flush toolbar
    void update_contract(QString contract);

private slots:
    // right popup menu in swing trade dialog
    void on_tab_customContextMenuRequested();
    // popup menu for strategy
    void on_trigger_pb2();
    // add/modify/remove contract in right popup menu in swing trade dialog
    void add_contract();
    void modify_contract();
    void remove_contract();
    // insert/set/remove strategy in right popup menu in swing trade dialog
    void insert_strategy();
    void set_strategy();
    void remove_strategy();
    // turn on/off strategy
    void open_close_strategy();
    // create order for buyask/buybid/sellbid/sellask
    void on_click_buyask();
    void on_click_buybid();
    void on_click_sellbid();
    void on_click_sellask();

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

    QString exchange_contract;
    QString exchange;
    QString contract;

    SwingTrader *swingtrader;
    DWORD tbtid;
    Dispatcher *disp;
    QuoteItem *quoteItem;
    TradeUnit *tradeUnit;

    void closeEvent(QCloseEvent *event);
    void setPanelEnabled(bool enabled);
};

#endif // SWINGTRADEDIALOG_H
