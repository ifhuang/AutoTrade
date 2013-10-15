#ifndef INSERTSTRATEGYDIALOG_H
#define INSERTSTRATEGYDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class InsertStrategyDialog;
}

class InsertStrategyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertStrategyDialog(QString *name, QWidget *parent = 0);
    ~InsertStrategyDialog();

private slots:
    // set strategy with current row
    void on_click_insert();

private:
    Ui::InsertStrategyDialog *ui;
    // Name and Ready Status
    QStandardItemModel *strategymodel;
    QString *name;
};

#endif // INSERTSTRATEGYDIALOG_H
