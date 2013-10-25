#ifndef SWINGTRADEDIALOG_H
#define SWINGTRADEDIALOG_H

#include "iswingtradedialog.h"
#include <QDialog>

#include <QCloseEvent>
#include <QComboBox>
#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QToolBar>
#include <qwt_plot.h>
#include <qwt_plot_tradingcurve.h>
#include "../TC/Bar.h"
#include "../TC/Dispatcher.h"
#include "../TC/PriceItem.h"
#include "../TC/SwingTrader.h"

namespace Ui {
class SwingTradeDialog;
}

class SwingTrader;

class SwingTradeDialog : public ISwingTradeDialog, public QDialog
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
    virtual void displayBar(Bar *bar) override;

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
    Ui::SwingTradeDialog *ui_;

    QToolBar *toolbar_;
    QMenu *pb2_menu_;
    QMenu *swingright_;
    QPushButton *pb1_;
    QLabel *label_strategy_;
    QPushButton *pb2_;
    QComboBox *cb_;
    QPushButton *pb3_;
    QPushButton *pb4_;
    QAction *pb2_menu_open_;
    QAction *pb2_menu_attr_;
    QAction *pb2_menu_auto_;
    QAction *pb2_menu_warn_;
    QAction *swingright_setwin_;
    QAction *swingright_insstr_;
    QAction *swingright_setstr_;
    QAction *swingright_remstr_;
    QAction *swingright_addcon_;
    QAction *swingright_modcon_;
    QAction *swingright_remcon_;

    QString exchange_contract_;
    QString exchange_;
    QString contract_;

    SwingTrader *swingtrader_;
    DWORD tbtid_;
    Dispatcher *disp_;
    QuoteItem *quoteItem_;
    TradeUnit *tradeUnit_;

    QwtPlot *plot_;
    QwtPlotTradingCurve *curve_;
    QVector<QwtOHLCSample> samples_;

    void setupToolbar();
    void setupStrategyButton();
    void setupRightPopup();
    void setupPlot();
    void setupConnect();

    void closeEvent(QCloseEvent *event);
    void setPanelEnabled(bool enabled);
};

#endif // SWINGTRADEDIALOG_H
