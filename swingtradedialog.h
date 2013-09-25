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

namespace Ui {
class SwingTradeDialog;
}

class SwingTradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SwingTradeDialog(QString &contract, QWidget *parent = 0);
    ~SwingTradeDialog();
    QString getSwingContract();

    void displayPriceItem(PriceItem* priceItem);
    void displayPosition(double position);
    void displayProfit(double profit);

private:
    Ui::SwingTradeDialog *ui;
    QToolBar *toolBar;
    QMenu *cb1_menu;
    QMenu *swingRight;
    QPushButton *pb1;
    QLabel *label1;
    QPushButton *cb1;
    QComboBox *cb2;
    QPushButton *pb2;
    QPushButton *pb3;
    QAction *cb1_menu_open;
    QAction *cb1_menu_attr;
    QAction *cb1_menu_auto;
    QAction *cb1_menu_warn;
    QAction *swingRight_setwin;
    QAction *swingRight_insstr;
    QAction *swingRight_setstr;
    QAction *swingRight_remstr;
    QAction *swingRight_addcon;
    QAction *swingRight_modcon;
    QAction *swingRight_remcon;

    QString swing_contract;

signals:
    void update_contract(QString contract);

private slots:
    void on_tab_customContextMenuRequested();
    void on_trigger_cb1();
    void add_contract();
    void modify_contract();
    void remove_contract();
    void insert_strategy();
    void set_strategy();
    void remove_strategy();

    void set_window_test();
};

#endif // SWINGTRADEDIALOG_H
