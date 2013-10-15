#include "insertstrategydialog.h"
#include "ui_insertstrategydialog.h"

InsertStrategyDialog::InsertStrategyDialog(QString *name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertStrategyDialog)
{
    this->name = name;
    ui->setupUi(this);

    strategymodel = new QStandardItemModel;
    strategymodel->setColumnCount(2);
    strategymodel->setHeaderData(0, Qt::Horizontal, tr("Name"));
    strategymodel->setHeaderData(1, Qt::Horizontal, tr("Ready Status"));
    strategymodel->insertRow(0, new QStandardItem(QString("Breakeven Stop")));
    ui->tableView->setModel(strategymodel);

    setAttribute(Qt::WA_DeleteOnClose);
}

InsertStrategyDialog::~InsertStrategyDialog()
{
    delete ui;
}

void InsertStrategyDialog::on_click_insert()
{
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex indextemp = strategymodel->index(curRow,0);
    QVariant datatemp = strategymodel->data(indextemp);
    *name = datatemp.toString();
    accept();
}
