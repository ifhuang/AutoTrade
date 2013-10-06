#include "swingtradedialog.h"
#include "ui_swingtradedialog.h"
#include <QSize>
#include <QInputDialog>

SwingTradeDialog::SwingTradeDialog(QString &contract, int tradeId, Dispatcher *disp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwingTradeDialog)
{
    ui->setupUi(this);

    swing_contract = contract;

    toolbar = new QToolBar(this);
    QSize pbSize(20, 20);
    pb1 = new QPushButton("1");
    pb1->setFixedSize(pbSize);
    toolbar->addWidget(pb1);

    label_strategy = new QLabel("Strategy Name");
    label_strategy->setFixedWidth(90);
    toolbar->addWidget(label_strategy);

    pb2 = new QPushButton("2");
    pb2->setFixedSize(pbSize);
    pb2_menu = new QMenu;
    pb2_menu_open = pb2_menu->addAction(tr("Open/Close Strategy"));
    pb2_menu->addSeparator();
    pb2_menu_attr = pb2_menu->addAction(tr("Attribute"));
    pb2_menu_auto = pb2_menu->addAction(tr("Auto Trade"));
    pb2_menu_warn = pb2_menu->addAction(tr("Warn"));
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

    pb3 = new QPushButton("3");
    pb3->setFixedSize(pbSize);
    toolbar->addWidget(pb3);

    pb4 = new QPushButton("4");
    pb4->setFixedSize(pbSize);
    toolbar->addWidget(pb4);

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

    swingtrader = new SwingTrader(tradeId, this);
    swingtrader->setIntraBarTrading(true);
    swingtrader->setDispatcher(disp);
    tbtid = swingtrader->startTraderThread();
    this->disp = disp;
}

SwingTradeDialog::~SwingTradeDialog()
{
    delete ui;
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
    bool ok;
    QString text = QInputDialog::getText(NULL, tr("Add Contract"), tr("Exchange-Contract:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty())
    {
        QStringList list = text.split("-");
        QuoteItem* quoteItem = new QuoteItem;
        quoteItem->setTradePlatform(SPTRADER);
        quoteItem->setQuoteId(list[1].toStdString());
        quoteItem->setExchange(list[0].toStdString());
        quoteItem->setMinContractQty(1);
        quoteItem->setPriceScale(1);
        TradeUnit* tradeUnit = new TradeUnit(quoteItem);
        swingtrader->setTradeUnit(tradeUnit);
        this->disp->addPriceThreadId(quoteItem->getTradePlatform(), quoteItem->getQuoteId(),tbtid);
        this->disp->addOrderThreadId(swingtrader->getTraderId(), tbtid);

        // simply turn on strategy when add contract
        swingtrader->turnOnStrategy();

        swing_contract = text;
        setWindowTitle(swing_contract);
        swingright_addcon->setEnabled(false);
        swingright_modcon->setEnabled(true);
        swingright_remcon->setEnabled(true);
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
        QStringList list = text.split("-");
        QuoteItem* quoteItem = new QuoteItem;
        quoteItem->setTradePlatform(SPTRADER);
        quoteItem->setQuoteId(list[1].toStdString());
        quoteItem->setExchange(list[0].toStdString());
        quoteItem->setMinContractQty(1);
        quoteItem->setPriceScale(1);
        TradeUnit* tradeUnit = new TradeUnit(quoteItem);
        swingtrader->setTradeUnit(tradeUnit);
        this->disp->addPriceThreadId(quoteItem->getTradePlatform(), quoteItem->getQuoteId(),tbtid);
        this->disp->addOrderThreadId(swingtrader->getTraderId(), tbtid);

        // simply turn on strategy when modify contract
        swingtrader->turnOnStrategy();

        swing_contract = text;
        setWindowTitle(swing_contract);
        emit update_contract(swing_contract);
    }
}

void SwingTradeDialog::remove_contract()
{
    swing_contract = QString("Exchange-Contract");
    setWindowTitle(swing_contract);
    swingright_addcon->setEnabled(true);
    swingright_modcon->setEnabled(false);
    swingright_remcon->setEnabled(false);
    emit update_contract(swing_contract);
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
    label_strategy->setText("Strategy");
    swingright_insstr->setEnabled(true);
    swingright_setstr->setEnabled(false);
    swingright_remstr->setEnabled(false);
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
