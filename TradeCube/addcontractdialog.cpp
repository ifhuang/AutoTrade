#include "addcontractdialog.h"
#include "ui_addcontractdialog.h"

AddContractDialog::AddContractDialog(QString *exchange, QString *contract, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContractDialog)
{
    this->exchange = exchange;
    this->contract = contract;

    ui->setupUi(this);

    cbot<<QString("YMZ3")<<QString("ZCZ3")<<QString("ZCH4")<<QString("ZLV3")<<QString("ZLZ3")<<QString("ZMV3")<<QString("ZMZ3")<<QString("ZOZ3")<<QString("ZRX3")<<QString("ZSX3")<<QString("ZSF4")<<QString("ZSH4")<<QString("ZWZ3")<<QString("ZWH4");
    cme<<QString("6AZ3")<<QString("6CZ3")<<QString("6SZ3")<<QString("ESZ3")<<QString("6EZ3")<<QString("6BZ3")<<QString("6JZ3")<<QString("NKDZ3")<<QString("NQZ3")<<QString("6NZ3")<<QString("RMBV3")<<QString("RMBX3")<<QString("RMBZ3");
}

AddContractDialog::~AddContractDialog()
{
    delete ui;
}

void AddContractDialog::on_change_exchange(int index)
{
    switch(index)
    {
    case 0:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(cbot);
        break;
    case 1:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(cme);
        break;
    case 2:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(hkif);
        break;
    case 3:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(lme);
        break;
    case 4:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(nybot);
        break;
    case 5:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(nymex);
        break;
    case 6:
        ui->comboBox_contract->clear();
        ui->comboBox_contract->addItems(tocom);
        break;
    default: break;
    }
}

void AddContractDialog::on_click_add()
{
    *exchange = ui->comboBox_exchange->currentText();
    *contract = ui->comboBox_contract->currentText();
    this->accept();
}
