#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "../TC/PlatformInfo.h"

namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(PlatformInfo *platforminfo, QWidget *parent = 0);
    ~LogInDialog();

private slots:
    void on_click_login();

private:
    Ui::LogInDialog *ui;

    PlatformInfo *platforminfo;
};

#endif // LOGINDIALOG_H
