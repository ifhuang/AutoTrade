#ifndef COMBOTRADEDIALOG_H
#define COMBOTRADEDIALOG_H

#include <QDialog>

#include <QComboBox>
#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QToolBar>

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
    Ui::ComboTradeDialog *ui_;

    QToolBar *toolbar_;
    QMenu *pb2_menu_;
    QMenu *comboright_;
    QPushButton *pb1_;
    QLabel *label_strategy_;
    QPushButton *pb2_;
    QLabel *label_blank_;
    QPushButton *pb3_;
    QPushButton *pb4_;
    QPushButton *pb5_;
    QAction *pb2_menu_open_;
    QAction *pb2_menu_attr_;
    QAction *pb2_menu_auto_;
    QAction *pb2_menu_warn_;
    QAction *comboright_setwin_;
    QAction *comboright_insstr_;
    QAction *comboright_setstr_;
    QAction *comboright_remstr_;
    QAction *comboright_addcon_;
    QAction *comboright_modcon_;
    QAction *comboright_remcon_;

    void setupToolbar();
    void setupStrategyButton();
    void setupRightPopup();
    void setupConnect();
};

#endif // COMBOTRADEDIALOG_H
