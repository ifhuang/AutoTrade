#include "logindialog.h"
#include "ui_logindialog.h"

#include "../TC/TradeCube.h"

LogInDialog::LogInDialog(PlatformInfo *platforminfo, QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::LogInDialog),
    platforminfo_(platforminfo)
{
    ui_->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

LogInDialog::~LogInDialog()
{
    delete ui_;
}

void LogInDialog::on_click_login()
{
    switch(ui_->comboBox->currentIndex())
    {
    case 0:
        platforminfo_->platformName = SPTRADER;
        platforminfo_->server = "127.0.0.1";
        platforminfo_->orderPort = 8092;
        platforminfo_->pricePort = 8089;
        platforminfo_->tickPort = 8090;
        break;
    default: break;
    }
    platforminfo_->accountNo = ui_->lineEdit_userid->text().toStdString();
    platforminfo_->password = ui_->lineEdit_pwd->text().toStdString();
    accept();
}
