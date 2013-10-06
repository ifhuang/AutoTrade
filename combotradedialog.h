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
    QToolBar *toolbar;
    QMenu *pb2_menu;
    QMenu *comboright;
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
    QAction *comboright_setwin;
    QAction *comboright_insstr;
    QAction *comboright_setstr;
    QAction *comboright_remstr;
    QAction *comboright_addcon;
    QAction *comboright_modcon;
    QAction *comboright_remcon;
};

#endif // COMBOTRADEDIALOG_H
