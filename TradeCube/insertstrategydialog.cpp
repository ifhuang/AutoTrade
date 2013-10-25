#include "insertstrategydialog.h"
#include "ui_insertstrategydialog.h"

InsertStrategyDialog::InsertStrategyDialog(QString *name, QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::InsertStrategyDialog)
{
    this->name_ = name;
    ui_->setupUi(this);
    setupStrategyModel();

    setAttribute(Qt::WA_DeleteOnClose);
}

void InsertStrategyDialog::setupStrategyModel()
{
    strategymodel_ = new QStandardItemModel;
    strategymodel_->setColumnCount(2);
    strategymodel_->setHeaderData(0, Qt::Horizontal, tr("Name"));
    strategymodel_->setHeaderData(1, Qt::Horizontal, tr("Ready Status"));
    strategymodel_->insertRow(0, new QStandardItem(QString("Breakeven Stop")));
    ui_->tableView->setModel(strategymodel_);
}

InsertStrategyDialog::~InsertStrategyDialog()
{
    delete ui_;
}

void InsertStrategyDialog::on_click_insert()
{
    int curRow = ui_->tableView->currentIndex().row();
    QModelIndex indextemp = strategymodel_->index(curRow,0);
    QVariant datatemp = strategymodel_->data(indextemp);
    *name_ = datatemp.toString();
    accept();
}
