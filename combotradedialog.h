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
    void on_tab_customContextMenuRequested_combo();
    void on_trigger_cb1();

private:
    Ui::ComboTradeDialog *ui;
    QToolBar *toolBar;
    QMenu *cb1_menu;
    QMenu *comboRight;
    QPushButton *pb1;
    QLabel *label1;
    QPushButton *cb1;
    QLabel *label2;
    QPushButton *pb2;
    QPushButton *pb3;
    QPushButton *pb4;
    QAction *cb1_menu_open;
    QAction *cb1_menu_attr;
    QAction *cb1_menu_auto;
    QAction *cb1_menu_warn;
    QAction *comboRight_setwin;
    QAction *comboRight_insstr;
    QAction *comboRight_setstr;
    QAction *comboRight_remstr;
    QAction *comboRight_addcon;
    QAction *comboRight_modcon;
    QAction *comboRight_remcon;
};

#endif // COMBOTRADEDIALOG_H
