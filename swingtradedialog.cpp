#include "swingtradedialog.h"
#include "ui_swingtradedialog.h"

#include <QSize>
#include <QInputDialog>
#include <iostream>

SwingTradeDialog::SwingTradeDialog(QString &contract, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwingTradeDialog)
{
    swing_contract = contract;

    ui->setupUi(this);

    toolBar = new QToolBar(this);

    QSize pbSize(20, 20);

    pb1 = new QPushButton("1");
    pb1->setFixedSize(pbSize);
    toolBar->addWidget(pb1);

    label1 = new QLabel("Strategy Name");
    label1->setFixedWidth(90);
    toolBar->addWidget(label1);

    cb1 = new QPushButton("2");
    cb1->setFixedSize(pbSize);
    cb1_menu = new QMenu;
    cb1_menu_open = cb1_menu->addAction(tr("Open/Close Strategy"));
    cb1_menu->addSeparator();
    cb1_menu_attr = cb1_menu->addAction(tr("Attribute"));
    cb1_menu_auto = cb1_menu->addAction(tr("Auto Trade"));
    cb1_menu_warn = cb1_menu->addAction(tr("Warn"));
    toolBar->addWidget(cb1);

    cb2 = new QComboBox;
    cb2->insertItem(0, tr("Tick"));
    cb2->insertItem(1, tr("1 Min"));
    cb2->insertItem(2, tr("3 Min"));
    cb2->insertItem(3, tr("5 Min"));
    cb2->insertItem(4, tr("10 Min"));
    cb2->insertItem(5, tr("15 Min"));
    cb2->insertItem(6, tr("30 Min"));
    cb2->insertItem(7, tr("1 Hour"));
    cb2->insertItem(8, tr("1 Day"));
    cb2->insertItem(9, tr("1 Week"));
    cb2->insertItem(10, tr("1 Month"));
    cb2->insertItem(11, tr("Customize"));
    toolBar->addWidget(cb2);

    pb2 = new QPushButton("3");
    pb2->setFixedSize(pbSize);
    toolBar->addWidget(pb2);

    pb3 = new QPushButton("4");
    pb3->setFixedSize(pbSize);
    toolBar->addWidget(pb3);

    setContextMenuPolicy(Qt::CustomContextMenu);
    swingRight = new QMenu;
    swingRight_setwin = swingRight->addAction(tr("Set Window"));
    swingRight->addSeparator();
    swingRight_insstr = swingRight->addAction(tr("Insert Strategy"));
    swingRight_setstr = swingRight->addAction(tr("Set Strategy"));
    swingRight_setstr->setEnabled(false);
    swingRight_remstr = swingRight->addAction(tr("Remove Strategy"));
    swingRight_remstr->setEnabled(false);
    swingRight->addSeparator();
    swingRight_addcon = swingRight->addAction(tr("Add Contract"));
    swingRight_modcon = swingRight->addAction(tr("Modify Contract"));
    swingRight_modcon->setEnabled(false);
    swingRight_remcon = swingRight->addAction(tr("Remove Contract"));
    swingRight_remcon->setEnabled(false);

    connect(cb1, SIGNAL(clicked()), this, SLOT(on_trigger_cb1()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested()));
    connect(swingRight_addcon, SIGNAL(triggered()), this, SLOT(add_contract()));
    connect(swingRight_modcon, SIGNAL(triggered()), this, SLOT(modify_contract()));
    connect(swingRight_remcon, SIGNAL(triggered()), this, SLOT(remove_contract()));
    connect(swingRight_insstr, SIGNAL(triggered()), this, SLOT(insert_strategy()));
    connect(swingRight_setstr, SIGNAL(triggered()), this, SLOT(set_strategy()));
    connect(swingRight_remstr, SIGNAL(triggered()), this, SLOT(remove_strategy()));

    connect(swingRight_setwin, SIGNAL(triggered()), this, SLOT(set_window_test()));
}

SwingTradeDialog::~SwingTradeDialog()
{
    delete ui;
}

void SwingTradeDialog::on_trigger_cb1()
{
    cb1_menu->exec(QCursor::pos());
}

void SwingTradeDialog::on_tab_customContextMenuRequested()
{
    swingRight->exec(QCursor::pos());
}

void SwingTradeDialog::add_contract()
{
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Add Contract"), tr("Contract:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty())
    {
        swing_contract = text;
        setWindowTitle(swing_contract + "-K-Exchange");
        swingRight_addcon->setEnabled(false);
        swingRight_modcon->setEnabled(true);
        swingRight_remcon->setEnabled(true);
        emit update_contract(swing_contract);
    }
}

QString SwingTradeDialog::getSwingContract()
{
    return swing_contract;
}

void SwingTradeDialog::modify_contract()
{
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Modify Contract"), tr("Contract:"), QLineEdit::Normal, swing_contract, &ok);
    if (ok && !text.isEmpty())
    {
        swing_contract = text;
        setWindowTitle(swing_contract + "-K-Exchange");
        emit update_contract(swing_contract);
    }
}

void SwingTradeDialog::remove_contract()
{
    swing_contract = QString("Contract");
    setWindowTitle(swing_contract + "-K-Exchange");
    swingRight_addcon->setEnabled(true);
    swingRight_modcon->setEnabled(false);
    swingRight_remcon->setEnabled(false);
    emit update_contract(swing_contract);
}

void SwingTradeDialog::insert_strategy()
{
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Insert Strategy"), tr("Strategy:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty())
    {
        label1->setText(text);
        swingRight_insstr->setEnabled(false);
        swingRight_setstr->setEnabled(true);
        swingRight_remstr->setEnabled(true);
    }
}

void SwingTradeDialog::set_strategy()
{
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Set Strategy"), tr("Strategy:"), QLineEdit::Normal, label1->text(), &ok);
    if (ok && !text.isEmpty())
    {
        label1->setText(text);
    }
}

void SwingTradeDialog::remove_strategy()
{
    label1->setText("Strategy");
    swingRight_insstr->setEnabled(true);
    swingRight_setstr->setEnabled(false);
    swingRight_remstr->setEnabled(false);
}

void SwingTradeDialog::displayPriceItem(PriceItem* priceItem)
{
    ui->pushButton_ba->setText(QString("Buy Ask\n%1").arg(priceItem->askPrice1));
    ui->pushButton_bb->setText(QString("Buy Bid\n%1").arg(priceItem->bidPrice1));
    ui->pushButton_sb->setText(QString("Sell Bid\n%1").arg(priceItem->bidPrice1));
    ui->pushButton_sa->setText(QString("Sell Ask\n%1").arg(priceItem->askPrice1));
}

void SwingTradeDialog::displayPosition(double position)
{
    ui->label_position->setText(QString("%1").arg(position));
}

void SwingTradeDialog::displayProfit(double profit)
{
    ui->label_profit->setText(QString("%1").arg(profit));
}

void SwingTradeDialog::set_window_test()
{
    PriceItem p;
    p.askPrice1 = qrand() % 100000;
    p.bidPrice1 = qrand() % 100000;
    p.askQty1 = qrand() % 10;
    p.bidQty1 = qrand() % 10;
    displayPriceItem(&p);
    double position = qrand() % 100000;
    double profit = qrand() % 10;
    displayPosition(position);
    displayProfit(profit);
}
