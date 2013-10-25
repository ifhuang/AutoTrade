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
    Ui::AddContractDialog *ui_;

    static const QStringList cbot_;
    static const QStringList cme_;
    static const QStringList hkif_;
    static const QStringList lme_;
    static const QStringList nybot_;
    static const QStringList nymex_;
    static const QStringList tocom_;

    QString *exchange_;
    QString *contract_;
};

#endif // ADDCONTRACTDIALOG_H
