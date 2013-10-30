#include "addcontractdialog.h"
#include "ui_addcontractdialog.h"

const QStringList AddContractDialog::cbot_ = QString("YMZ3,ZCZ3,ZCH4,ZLV3,ZLZ3,ZMV3,ZMZ3,ZOZ3,ZRX3,ZSX3,ZSF4,ZSH4,ZWZ3,ZWH4").split(",");
const QStringList AddContractDialog::cme_ = QString("6AZ3,6CZ3,6SZ3,ESZ3,6EZ3,6BZ3,6JZ3,NKDZ3,NQZ3,6NZ3,RMBV3,RMBX3,RMBZ3").split(",");
const QStringList AddContractDialog::hkif_ = QString("HHI,HHIZ3,HHI6200L3,HHI6400L3,HHI6600L3,HHI6800L3,HHI7000L3,HHI7200L3,HHI7400L3,HHI7600L3,HHI7800L3,HHI8000L3,HHI8400L3,HHI8800L3,HHI9000L3,HHI9200L3,HHI9400L3,HHI9600L3,HHI10000L3,HHI10200L3,HHI10400L3,HHI10600L3,HHI10800L3,HHI11000L3,HHI11200L3,HHI11400L3,HHI11600L3,HHI11800L3,HHI12000L3,HHI12200L3,HHI12400L3,HHI12600L3,HHI12800L3,HHI13000L3,HHI13200L3,HHI13400L3,HHI13600L3,HHI13800L3,HHI14400L3,HHI15000L3,HHI15800L3,HHI16000L3,HHI16200L3,HHI16400L3,HHI16600L3,HHI16800L3,HHI17000L3,HHI6200X3,HHI6400X3,HHI6600X3,HHI6800X3,HHI7000X3,HHI7200X3,HHI7400X3,HHI7600X3,HHI7800X3,HHI8000X3,HHI8400X3,HHI8800X3,HHI9000X3,HHI9200X3,HHI9400X3,HHI9600X3,HHI10000X3,HHI10200X3,HHI10400X3,HHI10600X3,HHI10800X3,HHI11000X3,HHI11200X3,HHI11400X3,HHI11600X3,HHI11800X3,HHI12000X3,HHI12200X3,HHI12400X3,HHI12600X3,HHI12800X3,HHI13000X3,HHI13200X3,HHI13400X3,HHI13600X3,HHI13800X3,HHI14400X3,HHI15000X3,HHI15800X3,HHI16000X3,HHI16200X3,HHI16400X3,HHI16600X3,HHI16800X3,HHI17000X3,HSI,HSIZ3,HSI10000L3,HSI10200L3,HSI10400L3,HSI10600L3,HSI10800L3,HSI11000L3,HSI11200L3,HSI11400L3,HSI11600L3,HSI11800L3,HSI12000L3,HSI12200L3,HSI12400L3,HSI12600L3,HSI12800L3,HSI13000L3,HSI13200L3,HSI13800L3,HSI14400L3,HSI15000L3,HSI15800L3,HSI16600L3,HSI17400L3,HSI18200L3,HSI19000L3,HSI20000L3,HSI20200L3,HSI20400L3,HSI20600L3,HSI20800L3,HSI21000L3,HSI21200L3,HSI21400L3,HSI21600L3,HSI21800L3,HSI22000L3,HSI22200L3,HSI22400L3,HSI22600L3,HSI22800L3,HSI23000L3,HSI23200L3,HSI23400L3,HSI23600L3,HSI23800L3,HSI24000L3,HSI24200L3,HSI24400L3,HSI24600L3,HSI24800L3,HSI25000L3,HSI25200L3,HSI25400L3,HSI25600L3,HSI25800L3,HSI26000L3,HSI27000L3,HSI28000L3,HSI29000L3,HSI30000L3,HSI10000X3,HSI10200X3,HSI10400X3,HSI10600X3,HSI10800X3,HSI11000X3,HSI11200X3,HSI11400X3,HSI11600X3,HSI11800X3,HSI12000X3,HSI12200X3,HSI12400X3,HSI12600X3,HSI12800X3,HSI13000X3,HSI13200X3,HSI13800X3,HSI14400X3,HSI15000X3,HSI15800X3,HSI16600X3,HSI17400X3,HSI18200X3,HSI19000X3,HSI20000X3,HSI20200X3,HSI20400X3,HSI20600X3,HSI20800X3,HSI21000X3,HSI21200X3,HSI21400X3,HSI21600X3,HSI21800X3,HSI22000X3,HSI22200X3,HSI22400X3,HSI22600X3,HSI22800X3,HSI23000X3,HSI23200X3,HSI23400X3,HSI23600X3,HSI23800X3,HSI24000X3,HSI24200X3,HSI24400X3,HSI24600X3,HSI24800X3,HSI25000X3,HSI25200X3,HSI25400X3,HSI25600X3,HSI25800X3,HSI26000X3,HSI27000X3,HSI28000X3,HSI29000X3,HSI30000X3,MCH,MHI").split(",");
const QStringList AddContractDialog::lme_ = QString("LAH3M,LCA3M,LNI3M,LPB3M,LSN3M,LZS3M").split(",");
const QStringList AddContractDialog::nybot_ = QString("CTZ3,CTH4,DXZ3,SBH4,SBK4,SBN4,SBV4,SBH5,SBK5,SBN5").split(",");
const QStringList AddContractDialog::nymex_ = QString("CLX3,CLZ3,CLF4,GCV3,GCZ3,HGZ3,HOX3,HOZ3,HOF4,NGX3,NGZ3,NGF4,PAZ3,PLV3,QCX3,QCZ3,QCF4,QIZ3,QIF4,QMX3,QMZ3,QMF4,QOZ3,RBX3,RBZ3,RBF4,SIZ3,SIF4,SIH4,SIK4,SIN4,SIU4,SIZ4,SIN5,SIZ5").split(",");
const QStringList AddContractDialog::tocom_ = QString("").split(",");

AddContractDialog::AddContractDialog(QString *exchange, QString *contract, QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::AddContractDialog),
    exchange_(exchange),
    contract_(contract)
{
    ui_->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

AddContractDialog::~AddContractDialog()
{
    delete ui_;
}

void AddContractDialog::on_change_exchange(int index)
{
    switch(index)
    {
    case 0:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(cbot_);
        break;
    case 1:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(cme_);
        break;
    case 2:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(hkif_);
        break;
    case 3:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(lme_);
        break;
    case 4:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(nybot_);
        break;
    case 5:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(nymex_);
        break;
    case 6:
        ui_->comboBox_contract->clear();
        ui_->comboBox_contract->addItems(tocom_);
        break;
    default: break;
    }
}

void AddContractDialog::on_click_add()
{
    *exchange_ = ui_->comboBox_exchange->currentText();
    *contract_ = ui_->comboBox_contract->currentText();
    accept();
}
