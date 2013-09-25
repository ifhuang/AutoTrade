#include "swingtradedialog.h"
#include "ui_swingtradedialog.h"
#include <QSize>
#include <QInputDialog>

SwingTradeDialog::SwingTradeDialog(QString &contract, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwingTradeDialog)
{
    ui->setupUi(this);

    swing_contract = contract;

    toolBar = new QToolBar(this);
    QSize pbSize(20, 20);
    pb1 = new QPushButton("1");
    pb1->setFixedSize(pbSize);
    toolBar->addWidget(pb1);

    label_strategy = new QLabel("Strategy Name");
    label_strategy->setFixedWidth(90);
    toolBar->addWidget(label_strategy);

    pb2 = new QPushButton("2");
    pb2->setFixedSize(pbSize);
    pb2_menu = new QMenu;
    pb2_menu_open = pb2_menu->addAction(tr("Open/Close Strategy"));
    pb2_menu->addSeparator();
    pb2_menu_attr = pb2_menu->addAction(tr("Attribute"));
    pb2_menu_auto = pb2_menu->addAction(tr("Auto Trade"));
    pb2_menu_warn = pb2_menu->addAction(tr("Warn"));
    toolBar->addWidget(pb2);

    cb = new QComboBox;
    cb->insertItem(0, tr("Tick"));
    cb->insertItem(1, tr("1 Min"));
    cb->insertItem(2, tr("3 Min"));
    cb->insertItem(3, tr("5 Min"));
    cb->insertItem(4, tr("10 Min"));
    cb->insertItem(5, tr("15 Min"));
    cb->insertItem(6, tr("30 Min"));
    cb->insertItem(7, tr("1 Hour"));
    cb->insertItem(8, tr("1 Day"));
    cb->insertItem(9, tr("1 Week"));
    cb->insertItem(10, tr("1 Month"));
    cb->insertItem(11, tr("Customize"));
    toolBar->addWidget(cb);

    pb3 = new QPushButton("3");
    pb3->setFixedSize(pbSize);
    toolBar->addWidget(pb3);

    pb4 = new QPushButton("4");
    pb4->setFixedSize(pbSize);
    toolBar->addWidget(pb4);

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

    connect(pb2, SIGNAL(clicked()), this, SLOT(on_trigger_pb2()));
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
    delete toolBar;
    delete pb2_menu;
    delete swingRight;
    delete pb1;
    delete label_strategy;
    delete pb2;
    delete cb;
    delete pb3;
    delete pb4;
    delete pb2_menu_open;
    delete pb2_menu_attr;
    delete pb2_menu_auto;
    delete pb2_menu_warn;
    delete swingRight_setwin;
    delete swingRight_insstr;
    delete swingRight_setstr;
    delete swingRight_remstr;
    delete swingRight_addcon;
    delete swingRight_modcon;
    delete swingRight_remcon;
}

void SwingTradeDialog::on_trigger_pb2()
{
    pb2_menu->exec(QCursor::pos());
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
        label_strategy->setText(text);
        swingRight_insstr->setEnabled(false);
        swingRight_setstr->setEnabled(true);
        swingRight_remstr->setEnabled(true);
    }
}

void SwingTradeDialog::set_strategy()
{
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Set Strategy"), tr("Strategy:"), QLineEdit::Normal, label_strategy->text(), &ok);
    if (ok && !text.isEmpty())
    {
        label_strategy->setText(text);
    }
}

void SwingTradeDialog::remove_strategy()
{
    label_strategy->setText("Strategy");
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
    PriceItem *p = new PriceItem;
    p->askPrice1 = qrand() % 100000;
    p->bidPrice1 = qrand() % 100000;
    p->askQty1 = qrand() % 10;
    p->bidQty1 = qrand() % 10;
    displayPriceItem(p);
    double position = qrand() % 100000;
    double profit = qrand() % 10;
    displayPosition(position);
    displayProfit(profit);
}
