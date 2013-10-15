#include "swingtradedialog.h"
#include "ui_swingtradedialog.h"
#include <QSize>
#include <QInputDialog>
#include "mainwindow.h"
#include "addcontractdialog.h"
#include <QMessageBox>

SwingTradeDialog::SwingTradeDialog(QString exchange_contract, int tradeId, Dispatcher *disp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwingTradeDialog)
{
    this->exchange_contract = exchange_contract;
    swingtrader = new SwingTrader(tradeId, this, qobject_cast<MainWindow *>(parent));
    swingtrader->setIntraBarTrading(true);
    swingtrader->setDispatcher(disp);
    tbtid = swingtrader->startTraderThread();
    this->disp = disp;
    quoteItem = NULL;
    tradeUnit = NULL;

    ui->setupUi(this);

    toolbar = new QToolBar(this);
    QSize pbSize(20, 20);
    pb1 = new QPushButton(tr("1"));
    pb1->setFixedSize(pbSize);
    toolbar->addWidget(pb1);
    label_strategy = new QLabel(tr("Strategy Name"));
    label_strategy->setFixedWidth(90);
    toolbar->addWidget(label_strategy);
    pb2 = new QPushButton(tr("2"));
    pb2->setFixedSize(pbSize);    
    toolbar->addWidget(pb2);
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
    toolbar->addWidget(cb);
    pb3 = new QPushButton(tr("3"));
    pb3->setFixedSize(pbSize);
    toolbar->addWidget(pb3);
    pb4 = new QPushButton(tr("4"));
    pb4->setFixedSize(pbSize);
    toolbar->addWidget(pb4);

    pb2_menu = new QMenu;
    pb2_menu_open = pb2_menu->addAction(tr("Open/Close Strategy"));
    pb2_menu->addSeparator();
    pb2_menu_attr = pb2_menu->addAction(tr("Attribute"));
    pb2_menu_auto = pb2_menu->addAction(tr("Auto Trade"));
    pb2_menu_warn = pb2_menu->addAction(tr("Warn"));

    setContextMenuPolicy(Qt::CustomContextMenu);
    swingright = new QMenu;
    swingright_setwin = swingright->addAction(tr("Set Window"));
    swingright->addSeparator();
    swingright_insstr = swingright->addAction(tr("Insert Strategy"));
    swingright_setstr = swingright->addAction(tr("Set Strategy"));
    swingright_setstr->setEnabled(false);
    swingright_remstr = swingright->addAction(tr("Remove Strategy"));
    swingright_remstr->setEnabled(false);
    swingright->addSeparator();
    swingright_addcon = swingright->addAction(tr("Add Contract"));
    swingright_modcon = swingright->addAction(tr("Modify Contract"));
    swingright_modcon->setEnabled(false);
    swingright_remcon = swingright->addAction(tr("Remove Contract"));
    swingright_remcon->setEnabled(false);

    connect(pb2, SIGNAL(clicked()), this, SLOT(on_trigger_pb2()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested()));
    connect(swingright_addcon, SIGNAL(triggered()), this, SLOT(add_contract()));
    connect(swingright_modcon, SIGNAL(triggered()), this, SLOT(modify_contract()));
    connect(swingright_remcon, SIGNAL(triggered()), this, SLOT(remove_contract()));
    connect(swingright_insstr, SIGNAL(triggered()), this, SLOT(insert_strategy()));
    connect(swingright_setstr, SIGNAL(triggered()), this, SLOT(set_strategy()));
    connect(swingright_remstr, SIGNAL(triggered()), this, SLOT(remove_strategy()));
    connect(pb2_menu_open, SIGNAL(triggered()), this, SLOT(open_close_strategy()));

    setAttribute(Qt::WA_DeleteOnClose);
}

SwingTradeDialog::~SwingTradeDialog()
{
    delete ui;   
    delete pb1;
    delete label_strategy;
    delete pb2;
    delete cb;
    delete pb3;
    delete pb4;
    delete toolbar;
    delete pb2_menu_open;
    delete pb2_menu_attr;
    delete pb2_menu_auto;
    delete pb2_menu_warn;
    delete pb2_menu;
    delete swingright_setwin;
    delete swingright_insstr;
    delete swingright_setstr;
    delete swingright_remstr;
    delete swingright_addcon;
    delete swingright_modcon;
    delete swingright_remcon;
    delete swingright;
//    if(quoteItem != NULL)
//    {
//        delete quoteItem;
//    }
//    if(tradeUnit != NULL)
//    {
//        delete tradeUnit;
//    }
//    delete swingtrader;
}

void SwingTradeDialog::on_trigger_pb2()
{
    pb2_menu->exec(QCursor::pos());
}

void SwingTradeDialog::on_tab_customContextMenuRequested()
{
    swingright->exec(QCursor::pos());
}

void SwingTradeDialog::add_contract()
{
    AddContractDialog *addcontractdialog = new AddContractDialog(&exchange, &contract);
    if(addcontractdialog->exec() == AddContractDialog::Accepted)
    {
        quoteItem = new QuoteItem;
        quoteItem->setTradePlatform(disp->getPlatformInfo().platformName);
        quoteItem->setQuoteId(contract.toStdString());
        quoteItem->setExchange(exchange.toStdString());
        quoteItem->setMinContractQty(1);
        quoteItem->setPriceScale(1);
        tradeUnit = new TradeUnit(quoteItem);
        swingtrader->setTradeUnit(tradeUnit);
        disp->addPriceThreadId(quoteItem->getTradePlatform(), quoteItem->getQuoteId(),tbtid);
        disp->addOrderThreadId(swingtrader->getTraderId(), tbtid);
        exchange_contract = exchange.append("-").append(contract);
        setWindowTitle(exchange_contract);
        swingright_addcon->setEnabled(false);
        swingright_modcon->setEnabled(true);
        swingright_remcon->setEnabled(true);
        emit update_contract(exchange_contract);
    }
}

void SwingTradeDialog::modify_contract()
{
    int selection = QMessageBox::question(this, tr("Confirm"), tr("Are you sure?\nAll positions in ").append(exchange_contract).append(tr(" will be closed!")), QMessageBox::Yes | QMessageBox::No);
    if(selection == QMessageBox::Yes)
    {
        swingtrader->closeAllPositions();
//        delete quoteItem;
//        delete tradeUnit;
        add_contract();
    }
    else if(selection == QMessageBox::No)
    {
    }
}

void SwingTradeDialog::remove_contract()
{
    int selection = QMessageBox::question(this, tr("Confirm"), tr("Are you sure?\nAll positions in ").append(exchange_contract).append(tr(" will be closed!")), QMessageBox::Yes | QMessageBox::No);
    if(selection == QMessageBox::Yes)
    {
        swingtrader->closeAllPositions();
//        delete quoteItem;
//        delete tradeUnit;
        exchange_contract = tr("Exchange-Contract");
        setWindowTitle(exchange_contract);
        swingright_addcon->setEnabled(true);
        swingright_modcon->setEnabled(false);
        swingright_remcon->setEnabled(false);
        emit update_contract(exchange_contract);
    }
    else if(selection == QMessageBox::No)
    {
    }
}

void SwingTradeDialog::insert_strategy()
{
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Insert Strategy"), tr("Strategy:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty())
    {
        label_strategy->setText(text);
        swingright_insstr->setEnabled(false);
        swingright_setstr->setEnabled(true);
        swingright_remstr->setEnabled(true);
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
    label_strategy->setText(tr("Strategy"));
    swingright_insstr->setEnabled(true);
    swingright_setstr->setEnabled(false);
    swingright_remstr->setEnabled(false);
}

void SwingTradeDialog::displayPriceItem(PriceItem *priceItem)
{
    ui->pushButton_ba->setText(tr("Buy Ask\n").append(QString("%1").arg(priceItem->askPrice1)));
    ui->pushButton_bb->setText(tr("Buy Bid\n").append(QString("%1").arg(priceItem->bidPrice1)));
    ui->pushButton_sb->setText(tr("Sell Bid\n").append(QString("%1").arg(priceItem->bidPrice1)));
    ui->pushButton_sa->setText(tr("Sell Ask\n").append(QString("%1").arg(priceItem->askPrice1)));
}

void SwingTradeDialog::displayPosition(double position)
{
    ui->label_position->setText(QString("%1").arg(position));
}

void SwingTradeDialog::displayProfit(double profit)
{
    ui->label_profit->setText(QString("%1").arg(profit));
}

void SwingTradeDialog::on_click_buyask()
{
    swingtrader->createOrder(BUY, OPEN, swingtrader->getTradeUnit()->getPrice()->askPrice1, ui->spinBox_qty->text().toInt(), MKT, DAY, SPTRADER);
}

void SwingTradeDialog::closeEvent(QCloseEvent *event)
{
    if(swingright_remcon->isEnabled())
    {
        int selection = QMessageBox::question(this, tr("Confirm"), tr("Are you sure?\nAll positions in ").append(exchange_contract).append(tr(" will be closed!")), QMessageBox::Yes | QMessageBox::No);
        if(selection == QMessageBox::Yes)
        {
            swingtrader->closeAllPositions();
            event->accept();
        }
        else if(selection == QMessageBox::No)
        {
            event->ignore();
        }
    }
}

QString SwingTradeDialog::getExchangeContract()
{
    return exchange_contract;
}

void SwingTradeDialog::open_close_strategy()
{
    if(swingtrader->getAutoTrading())
    {
        swingtrader->turnOffStrategy();
    }
    else
    {
        swingtrader->turnOnStrategy();
    }
}

void SwingTradeDialog::on_click_buybid()
{
    swingtrader->createOrder(BUY, OPEN, swingtrader->getTradeUnit()->getPrice()->bidPrice1, ui->spinBox_qty->text().toInt(), MKT, DAY, SPTRADER);
}

void SwingTradeDialog::on_click_sellbid()
{
    swingtrader->createOrder(SELL, OPEN, swingtrader->getTradeUnit()->getPrice()->bidPrice1, ui->spinBox_qty->text().toInt(), MKT, DAY, SPTRADER);
}

void SwingTradeDialog::on_click_sellask()
{
    swingtrader->createOrder(SELL, OPEN, swingtrader->getTradeUnit()->getPrice()->askPrice1, ui->spinBox_qty->text().toInt(), MKT, DAY, SPTRADER);
}
