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
    // update contract combobox with current exchange combobox index
    void on_change_exchange(int index);
    // set exchange and contract with current inputs
    void on_click_add();

private:
    Ui::AddContractDialog *ui;

    static const QStringList cbot;
    static const QStringList cme;
    static const QStringList hkif;
    static const QStringList lme;
    static const QStringList nybot;
    static const QStringList nymex;
    static const QStringList tocom;

    QString *exchange;
    QString *contract;
};

#endif // ADDCONTRACTDIALOG_H
