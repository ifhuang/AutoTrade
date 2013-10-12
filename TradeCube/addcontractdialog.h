#ifndef ADDCONTRACTDIALOG_H
#define ADDCONTRACTDIALOG_H

#include <QDialog>

namespace Ui {
class AddContractDialog;
}

class AddContractDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddContractDialog(QString *exchange, QString *contract, QWidget *parent = 0);
    ~AddContractDialog();

private slots:
    void on_change_exchange(int index);
    void on_click_add();

private:
    Ui::AddContractDialog *ui;

    QStringList cbot;
    QStringList cme;
    QStringList hkif;
    QStringList lme;
    QStringList nybot;
    QStringList nymex;
    QStringList tocom;

    QString *exchange;
    QString *contract;
};

#endif // ADDCONTRACTDIALOG_H
