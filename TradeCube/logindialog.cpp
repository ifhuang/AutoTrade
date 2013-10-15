#include "logindialog.h"
#include "ui_logindialog.h"
#include "../TC/TradeCube.h"

LogInDialog::LogInDialog(PlatformInfo *platforminfo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    this->platforminfo = platforminfo;
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::on_click_login()
{
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        platforminfo->platformName = SPTRADER;
        platforminfo->server = "127.0.0.1";
        platforminfo->orderPort = 8092;
        platforminfo->pricePort = 8089;
        platforminfo->tickPort = 8090;
        break;
    default: break;
    }
    platforminfo->accountNo = ui->lineEdit_userid->text().toStdString();
    platforminfo->password = ui->lineEdit_pwd->text().toStdString();
    accept();
}
