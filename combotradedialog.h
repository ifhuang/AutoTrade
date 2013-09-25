#ifndef COMBOTRADEDIALOG_H
#define COMBOTRADEDIALOG_H

#include <QDialog>
#include <QToolBar>
#include <QMenu>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

namespace Ui {
class ComboTradeDialog;
}

class ComboTradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComboTradeDialog(QWidget *parent = 0);
    ~ComboTradeDialog();

private slots:
    // right popup menu in combo trade dialog
    void on_tab_customContextMenuRequested_combo();

    // popup menu for strategy
    void on_trigger_pb2();

private:
    Ui::ComboTradeDialog *ui;
    QToolBar *toolBar;
    QMenu *pb2_menu;
    QMenu *comboRight;
    QPushButton *pb1;
    QLabel *label_strategy;
    QPushButton *pb2;
    QLabel *label_blank;
    QPushButton *pb3;
    QPushButton *pb4;
    QPushButton *pb5;
    QAction *pb2_menu_open;
    QAction *pb2_menu_attr;
    QAction *pb2_menu_auto;
    QAction *pb2_menu_warn;
    QAction *comboRight_setwin;
    QAction *comboRight_insstr;
    QAction *comboRight_setstr;
    QAction *comboRight_remstr;
    QAction *comboRight_addcon;
    QAction *comboRight_modcon;
    QAction *comboRight_remcon;
};

#endif // COMBOTRADEDIALOG_H
