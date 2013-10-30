#include "swingtradedialog.h"
#include "ui_swingtradedialog.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QSize>
#include "addcontractdialog.h"
#include "insertstrategydialog.h"
#include "mainwindow.h"

SwingTradeDialog::SwingTradeDialog(QString exchange_contract, int tradeId, Dispatcher *disp, QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::SwingTradeDialog),
    exchange_contract_(exchange_contract),
    swingtrader_(new SwingTrader(tradeId, disp, this, qobject_cast<MainWindow *>(parent))),
    disp_(disp),
    quoteItem_(nullptr),
    tradeUnit_(nullptr)
{
    swingtrader_->setIntraBarTrading(true);
    tbtid_ = swingtrader_->startTraderThread();
    ui_->setupUi(this);
    setupToolbar();
    setupStrategyButton();
    setupRightPopup();
    setupPlot();
    setupConnect();
//    setAttribute(Qt::WA_DeleteOnClose);
}

void SwingTradeDialog::setupToolbar()
{
    toolbar_ = new QToolBar(this);
    QSize pbSize(20, 20);
    pb1_ = new QPushButton(tr("1"));
    pb1_->setFixedSize(pbSize);
    toolbar_->addWidget(pb1_);
    label_strategy_ = new QLabel(tr("Strategy Name"));
    label_strategy_->setFixedWidth(90);
    toolbar_->addWidget(label_strategy_);
    pb2_ = new QPushButton(tr("2"));
    pb2_->setFixedSize(pbSize);
    toolbar_->addWidget(pb2_);
    cb_ = new QComboBox;
    cb_->insertItem(0, tr("Tick"));
    cb_->insertItem(1, tr("1 Min"));
    cb_->insertItem(2, tr("3 Min"));
    cb_->insertItem(3, tr("5 Min"));
    cb_->insertItem(4, tr("10 Min"));
    cb_->insertItem(5, tr("15 Min"));
    cb_->insertItem(6, tr("30 Min"));
    cb_->insertItem(7, tr("1 Hour"));
    cb_->insertItem(8, tr("1 Day"));
    cb_->insertItem(9, tr("1 Week"));
    cb_->insertItem(10, tr("1 Month"));
    cb_->insertItem(11, tr("Customize"));
    toolbar_->addWidget(cb_);
    pb3_ = new QPushButton(tr("3"));
    pb3_->setFixedSize(pbSize);
    toolbar_->addWidget(pb3_);
    pb4_ = new QPushButton(tr("4"));
    pb4_->setFixedSize(pbSize);
    toolbar_->addWidget(pb4_);
}

void SwingTradeDialog::setupStrategyButton()
{
    pb2_menu_ = new QMenu;
    pb2_menu_open_ = pb2_menu_->addAction(tr("Open/Close Strategy"));
    pb2_menu_->addSeparator();
    pb2_menu_attr_ = pb2_menu_->addAction(tr("Attribute"));
    pb2_menu_auto_ = pb2_menu_->addAction(tr("Auto Trade"));
    pb2_menu_warn_ = pb2_menu_->addAction(tr("Warn"));
}

void SwingTradeDialog::setupRightPopup()
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    swingright_ = new QMenu;
    swingright_setwin_ = swingright_->addAction(tr("Set Window"));
    swingright_->addSeparator();
    swingright_insstr_ = swingright_->addAction(tr("Insert Strategy"));
    swingright_setstr_ = swingright_->addAction(tr("Set Strategy"));
    swingright_setstr_->setEnabled(false);
    swingright_remstr_ = swingright_->addAction(tr("Remove Strategy"));
    swingright_remstr_->setEnabled(false);
    swingright_->addSeparator();
    swingright_addcon_ = swingright_->addAction(tr("Add Contract"));
    swingright_modcon_ = swingright_->addAction(tr("Modify Contract"));
    swingright_modcon_->setEnabled(false);
    swingright_remcon_ = swingright_->addAction(tr("Remove Contract"));
    swingright_remcon_->setEnabled(false);
    setPanelEnabled(false);
}

void SwingTradeDialog::setupPlot()
{
    plot_ = new QwtPlot(this);
    plot_->setGeometry(0, 190, 240, 200);
    curve_ = new QwtPlotTradingCurve;
    curve_->setOrientation(Qt::Vertical);
    curve_->attach(plot_);
    curve_->setVisible(true);
}

void SwingTradeDialog::setupConnect()
{
    connect(pb2_, SIGNAL(clicked()), this, SLOT(on_trigger_pb2()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested()));
    connect(swingright_addcon_, SIGNAL(triggered()), this, SLOT(add_contract()));
    connect(swingright_modcon_, SIGNAL(triggered()), this, SLOT(modify_contract()));
    connect(swingright_remcon_, SIGNAL(triggered()), this, SLOT(remove_contract()));
    connect(swingright_insstr_, SIGNAL(triggered()), this, SLOT(insert_strategy()));
    connect(swingright_setstr_, SIGNAL(triggered()), this, SLOT(set_strategy()));
    connect(swingright_remstr_, SIGNAL(triggered()), this, SLOT(remove_strategy()));
    connect(pb2_menu_open_, SIGNAL(triggered()), this, SLOT(open_close_strategy()));
}

SwingTradeDialog::~SwingTradeDialog()
{
    delete ui_;
    delete pb1_;
    delete label_strategy_;
    delete pb2_;
    delete cb_;
    delete pb3_;
    delete pb4_;
    delete toolbar_;
    delete pb2_menu_open_;
    delete pb2_menu_attr_;
    delete pb2_menu_auto_;
    delete pb2_menu_warn_;
    delete pb2_menu_;
    delete swingright_setwin_;
    delete swingright_insstr_;
    delete swingright_setstr_;
    delete swingright_remstr_;
    delete swingright_addcon_;
    delete swingright_modcon_;
    delete swingright_remcon_;
    delete swingright_;
//    std::cout<<"~SwingTradeDialog"<<std::endl;
//    if(quoteItem_ != NULL)
//    {
//        delete quoteItem_;
//    }
//    if(tradeUnit_ != NULL)
//    {
//        delete tradeUnit_;
//    }
//    delete swingtrader_;
}

void SwingTradeDialog::on_trigger_pb2()
{
    pb2_menu_->exec(QCursor::pos());
}

void SwingTradeDialog::on_tab_customContextMenuRequested()
{
    swingright_->exec(QCursor::pos());
}

void SwingTradeDialog::add_contract()
{
    AddContractDialog *addcontractdialog = new AddContractDialog(&exchange_, &contract_);
    if(addcontractdialog->exec() == AddContractDialog::Accepted)
    {
        quoteItem_ = new QuoteItem;
        quoteItem_->setQuoteId(contract_.toStdString());
        quoteItem_->setExchange(exchange_.toStdString());
        quoteItem_->setMinContractQty(1);
        quoteItem_->setPriceScale(1);
        tradeUnit_ = new TradeUnit(quoteItem_);
        swingtrader_->setTradeUnit(tradeUnit_);
        exchange_contract_ = exchange_.append("-").append(contract_);
        setWindowTitle(exchange_contract_);
        swingright_addcon_->setEnabled(false);
        swingright_modcon_->setEnabled(true);
        swingright_remcon_->setEnabled(true);
        setPanelEnabled(true);
        emit update_contract(exchange_contract_);
    }
}

void SwingTradeDialog::modify_contract()
{
    int selection = QMessageBox::question(this, tr("Confirm"), tr("Are you sure?\nAll positions in ").append(exchange_contract_).append(tr(" will be closed!")), QMessageBox::Yes | QMessageBox::No);
    if(selection == QMessageBox::Yes)
    {
        swingtrader_->closeAllPositions();
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
    int selection = QMessageBox::question(this, tr("Confirm"), tr("Are you sure?\nAll positions in ").append(exchange_contract_).append(tr(" will be closed!")), QMessageBox::Yes | QMessageBox::No);
    if(selection == QMessageBox::Yes)
    {
        swingtrader_->closeAllPositions();
//        delete quoteItem;
//        delete tradeUnit;
        exchange_contract_ = tr("Exchange-Contract");
        setWindowTitle(exchange_contract_);
        swingright_addcon_->setEnabled(true);
        swingright_modcon_->setEnabled(false);
        swingright_remcon_->setEnabled(false);
        setPanelEnabled(false);
        emit update_contract(exchange_contract_);
    }
    else if(selection == QMessageBox::No)
    {
    }
}

void SwingTradeDialog::insert_strategy()
{
    QString name;
    InsertStrategyDialog *insertstrategydialog = new InsertStrategyDialog(&name);
    if(insertstrategydialog->exec() == InsertStrategyDialog::Accepted)
    {
        label_strategy_->setText(name);
        swingright_insstr_->setEnabled(false);
        swingright_setstr_->setEnabled(true);
        swingright_remstr_->setEnabled(true);
    }
}

void SwingTradeDialog::set_strategy()
{
    QString name;
    InsertStrategyDialog *insertstrategydialog = new InsertStrategyDialog(&name);
    if(insertstrategydialog->exec() == InsertStrategyDialog::Accepted)
    {
        label_strategy_->setText(name);
        swingright_insstr_->setEnabled(false);
        swingright_setstr_->setEnabled(true);
        swingright_remstr_->setEnabled(true);
    }
}

void SwingTradeDialog::remove_strategy()
{
    label_strategy_->setText(tr("Strategy"));
    swingright_insstr_->setEnabled(true);
    swingright_setstr_->setEnabled(false);
    swingright_remstr_->setEnabled(false);
}

void SwingTradeDialog::displayPriceItem(PriceItem *priceItem)
{
    ui_->pushButton_ba->setText(tr("Buy Ask\n").append(QString("%1").arg(priceItem->askPrice1)));
    ui_->pushButton_bb->setText(tr("Buy Bid\n").append(QString("%1").arg(priceItem->bidPrice1)));
    ui_->pushButton_sb->setText(tr("Sell Bid\n").append(QString("%1").arg(priceItem->bidPrice1)));
    ui_->pushButton_sa->setText(tr("Sell Ask\n").append(QString("%1").arg(priceItem->askPrice1)));
}

void SwingTradeDialog::displayPosition(double position)
{
    ui_->label_position->setText(QString("%1").arg(position));
}

void SwingTradeDialog::displayProfit(double profit)
{
    ui_->label_profit->setText(QString("%1").arg(profit));
}

void SwingTradeDialog::on_click_buyask()
{
    swingtrader_->getStrategyInterface()->buy(swingtrader_->getTradeUnit()->getPrice()->askPrice1, ui_->spinBox_qty->text().toInt(), MKT, DAY);
}

void SwingTradeDialog::closeEvent(QCloseEvent *event)
{
    if(swingright_remcon_->isEnabled())
    {
        int selection = QMessageBox::question(this, tr("Confirm"), tr("Are you sure?\nAll positions in ").append(exchange_contract_).append(tr(" will be closed!")), QMessageBox::Yes | QMessageBox::No);
        if(selection == QMessageBox::Yes)
        {
            swingtrader_->closeAllPositions();
            event->accept();
        }
        else if(selection == QMessageBox::No)
        {
            event->ignore();
        }
    }
//    std::cout<<"closeEvent"<<std::endl;
}

QString SwingTradeDialog::getExchangeContract()
{
    return exchange_contract_;
}

void SwingTradeDialog::open_close_strategy()
{
    if(swingtrader_->getAutoTrading())
    {
        swingtrader_->turnOffStrategy();
    }
    else
    {
        swingtrader_->turnOnStrategy();
    }
}

void SwingTradeDialog::on_click_buybid()
{
    //swingtrader->updateOrder(1, SELL, CLOSE, swingtrader->getTradeUnit()->getPrice()->bidPrice1, ui->spinBox_qty->text().toInt() + 1, DAY);
    //swingtrader->deleteOrder(1);
    swingtrader_->getStrategyInterface()->buytocover(swingtrader_->getTradeUnit()->getPrice()->bidPrice1, ui_->spinBox_qty->text().toInt(), MKT, DAY);
}

void SwingTradeDialog::on_click_sellbid()
{
    swingtrader_->getStrategyInterface()->sell(swingtrader_->getTradeUnit()->getPrice()->bidPrice1, ui_->spinBox_qty->text().toInt(), MKT, DAY);
}

void SwingTradeDialog::on_click_sellask()
{
    swingtrader_->getStrategyInterface()->sellshort(swingtrader_->getTradeUnit()->getPrice()->askPrice1, ui_->spinBox_qty->text().toInt(), MKT, DAY);
}

void SwingTradeDialog::setPanelEnabled(bool enabled)
{
    pb1_->setEnabled(enabled);
    pb2_->setEnabled(enabled);
    cb_->setEnabled(enabled);
    pb3_->setEnabled(enabled);
    pb4_->setEnabled(enabled);
    ui_->pushButton_ba->setEnabled(enabled);
    ui_->pushButton_bb->setEnabled(enabled);
    ui_->pushButton_sa->setEnabled(enabled);
    ui_->pushButton_sb->setEnabled(enabled);
    ui_->spinBox_qty->setEnabled(enabled);
    ui_->checkBox_pt->setEnabled(enabled);
    ui_->checkBox_sl->setEnabled(enabled);
    ui_->doubleSpinBox_pt->setEnabled(enabled);
    ui_->doubleSpinBox_sl->setEnabled(enabled);
}

void SwingTradeDialog::displayBar(Bar *bar)
{
    samples_ += QwtOHLCSample(samples_.size() ,bar->getOpen(), bar->getHigh(), bar->getLow(), bar->getClose());
    curve_->setSamples(samples_);
    plot_->replot();
}
