#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <list>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <QDateTime>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QResizeEvent>
#include <QSize>
#include "combotradedialog.h"
#include "logindialog.h"
#include "swingtradedialog.h"
#include "../TC/DispatcherFactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    swing_counter_ = 0;
    combo_counter_ = 0;

    ui_->setupUi(this);
    //int currentScreenWid = QApplication::desktop()->width();
    //int currentScreenHei = QApplication::desktop()->height();
    //setFixedSize(currentScreenWid, currentScreenHei);
    showMaximized();
    setupToolbar();
    setupSwingRightPopup();
    setupComboRightPopup();
    setupPositionsTab();
    setupWorkingOrdersTab();
    setupOrderHistoryTab();
    setupConnect();

//    setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::setupToolbar()
{
    selcon_ = new QComboBox;
    selcon_->insertItem(0, tr("Select Contract"));
    selcon_->setEditable(true);
    ui_->mainToolBar->addWidget(selcon_);
    ordertype_ = new QComboBox;
    ordertype_->insertItem(0, tr("Order Type"));
    ordertype_->insertItem(1, tr("Market"));
    ordertype_->insertItem(2, tr("Stop"));
    ordertype_->insertItem(3, tr("Limit"));
    ordertype_->insertItem(4, tr("Stop Limit"));
    ui_->mainToolBar->addWidget(ordertype_);
    qty_ = new QLineEdit;
    qty_->setText(tr("Quantity"));
    qty_->setMaximumWidth(60);
    ui_->mainToolBar->addWidget(qty_);
    price_ = new QLineEdit;
    price_->setText(tr("Price"));
    price_->setMaximumWidth(40);
    ui_->mainToolBar->addWidget(price_);
    valid_ = new QComboBox;
    valid_->insertItem(0, tr("Validity"));
    valid_->insertItem(1, tr("DAY"));
    valid_->insertItem(2, tr("GTC"));
    valid_->insertItem(3, tr("GTD"));
    valid_->insertItem(4, tr("IOC"));
    ui_->mainToolBar->addWidget(valid_);
    buy_ = new QPushButton;
    buy_->setText(tr("Buy"));
    ui_->mainToolBar->addWidget(buy_);
    sell_ = new QPushButton;
    sell_->setText(tr("Sell"));
    ui_->mainToolBar->addWidget(sell_);
}

void MainWindow::setupSwingRightPopup()
{
    swingmdiright_ = new QMenu;
    insertswing_ = swingmdiright_->addAction(tr("Insert Swing Trader"));
    insertswing_->setEnabled(false);
}

void MainWindow::setupComboRightPopup()
{
    combomdiright_ = new QMenu;
    insertcombo_ = combomdiright_->addAction(tr("Insert Combo Trader"));
    insertcombo_->setEnabled(false);
}

void MainWindow::setupPositionsTab()
{
    swingpositionsmodel_ = new QStandardItemModel;
    swingpositionsmodel_->setColumnCount(7);
    swingpositionsmodel_->setHeaderData(0, Qt::Horizontal, tr("Id"));
    swingpositionsmodel_->setHeaderData(1, Qt::Horizontal, tr("Instrument"));
    swingpositionsmodel_->setHeaderData(2, Qt::Horizontal, tr("Date"));
    swingpositionsmodel_->setHeaderData(3, Qt::Horizontal, tr("Buy Sell"));
    swingpositionsmodel_->setHeaderData(4, Qt::Horizontal, tr("Price"));
    swingpositionsmodel_->setHeaderData(5, Qt::Horizontal, tr("Quantity"));
    swingpositionsmodel_->setHeaderData(6, Qt::Horizontal, tr("Status"));
    ui_->swingPositionsView->setModel(swingpositionsmodel_);
}

void MainWindow::setupWorkingOrdersTab()
{
    swingworkingordersmodel_ = new QStandardItemModel;
    swingworkingordersmodel_->setColumnCount(8);
    swingworkingordersmodel_->setHeaderData(0, Qt::Horizontal, tr("Id"));
    swingworkingordersmodel_->setHeaderData(1, Qt::Horizontal, tr("Instrument"));
    swingworkingordersmodel_->setHeaderData(2, Qt::Horizontal, tr("Date"));
    swingworkingordersmodel_->setHeaderData(3, Qt::Horizontal, tr("Order Type"));
    swingworkingordersmodel_->setHeaderData(4, Qt::Horizontal, tr("Buy Sell"));
    swingworkingordersmodel_->setHeaderData(5, Qt::Horizontal, tr("Price"));
    swingworkingordersmodel_->setHeaderData(6, Qt::Horizontal, tr("Quantity"));
    swingworkingordersmodel_->setHeaderData(7, Qt::Horizontal, tr("Status"));
    ui_->swingWorkingOrdersView->setModel(swingworkingordersmodel_);
}

void MainWindow::setupOrderHistoryTab()
{
    swingorderhistorymodel_ = new QStandardItemModel;
    swingorderhistorymodel_->setColumnCount(7);
    swingorderhistorymodel_->setHeaderData(0, Qt::Horizontal, tr("Id"));
    swingorderhistorymodel_->setHeaderData(1, Qt::Horizontal, tr("Instrument"));
    swingorderhistorymodel_->setHeaderData(2, Qt::Horizontal, tr("Date"));
    swingorderhistorymodel_->setHeaderData(3, Qt::Horizontal, tr("Buy Sell"));
    swingorderhistorymodel_->setHeaderData(4, Qt::Horizontal, tr("Price"));
    swingorderhistorymodel_->setHeaderData(5, Qt::Horizontal, tr("Quantity"));
    swingorderhistorymodel_->setHeaderData(6, Qt::Horizontal, tr("Status"));
    ui_->swingOrderHistoryView->setModel(swingorderhistorymodel_);
}

void MainWindow::setupConnect()
{
    connect(insertswing_, SIGNAL(triggered()), this, SLOT(new_swing_trade()));
    connect(insertcombo_, SIGNAL(triggered()), this, SLOT(new_combo_trade()));
}

MainWindow::~MainWindow()
{
    delete selcon_;
    delete ordertype_;
    delete qty_;
    delete price_;
    delete valid_;
    delete buy_;
    delete sell_;
    delete swingpositionsmodel_;
    delete swingworkingordersmodel_;
    delete swingorderhistorymodel_;
    delete ui_;
    delete insertswing_;
    delete swingmdiright_;
    delete insertcombo_;
    delete combomdiright_;
//    delete disp;
}

void MainWindow::new_swing_trade()
{
    QString contractName = tr("Exchange-Contract-").append(QString("%1").arg(swing_counter_));
    SwingTradeDialog *swingTradeDialog = new SwingTradeDialog(contractName, swing_counter_, disp_, this);

    connect(swingTradeDialog, SIGNAL(update_contract(QString)), this, SLOT(update_swing_contract(QString)));

    QMdiSubWindow *qMdiSubWindow = ui_->mdiArea_swing->addSubWindow(swingTradeDialog);
    qMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    qMdiSubWindow->setFixedSize(265, 440);
    qMdiSubWindow->setWindowFlags(qMdiSubWindow->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    qMdiSubWindow->setWindowTitle(contractName);
    qMdiSubWindow->show();

    swing_counter_++;
    selcon_->setCurrentText(contractName);
}

void MainWindow::new_combo_trade()
{
    ComboTradeDialog *comboTradeDialog = new ComboTradeDialog;
    QMdiSubWindow *qMdiSubWindow = ui_->mdiArea_combo->addSubWindow(comboTradeDialog);
    qMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    qMdiSubWindow->setFixedSize(320, 240);
    qMdiSubWindow->setWindowFlags(qMdiSubWindow->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    qMdiSubWindow->show();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    QSize centralSize = ui_->centralWidget->size();
    ui_->tabWidget->resize(centralSize);
    ui_->tab_swing->resize(centralSize);
    ui_->tab_combo->resize(centralSize);

    double mdi_tab = 0.8;
    ui_->mdiArea_swing->resize(centralSize.width(), centralSize.height() * mdi_tab);
    ui_->tabWidget_swing->setGeometry(0, centralSize.height() * mdi_tab, centralSize.width(), centralSize.height());
    ui_->swingPositionsView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui_->swingWorkingOrdersView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui_->swingOrderHistoryView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui_->mdiArea_combo->resize(centralSize.width(), centralSize.height() * mdi_tab);
    ui_->tabWidget_combo->setGeometry(0, centralSize.height() * mdi_tab, centralSize.width(), centralSize.height());
}

void MainWindow::about()
{
    QMessageBox::about(NULL, tr("About"), tr("Created By IIPL@FDU"));
}

void MainWindow::activate_swing()
{
    SwingTradeDialog *swingTradeDialog = NULL;
    if (QMdiSubWindow *activeSubWindow = ui_->mdiArea_swing->activeSubWindow())
        swingTradeDialog = qobject_cast<SwingTradeDialog *>(activeSubWindow->widget());
    if(swingTradeDialog != NULL)
    {
        selcon_->setCurrentText(swingTradeDialog->getExchangeContract());
    }
}

void MainWindow::activate_combo()
{
    ComboTradeDialog *comboTradeDialog = NULL;
    if (QMdiSubWindow *activeSubWindow = ui_->mdiArea_combo->activeSubWindow())
        comboTradeDialog = qobject_cast<ComboTradeDialog *>(activeSubWindow->widget());
}

void MainWindow::update_swing_contract(QString contract)
{
    selcon_->setCurrentText(contract);
}

void MainWindow::displaySwingAddPositions(Position *position)
{
    QStandardItem *data = new QStandardItem(QString(position->getQuoteId().c_str()));
    list<TradeItem *> tradeList = position->getTradeList();
    for(list<TradeItem *>::const_iterator it = tradeList.begin(); it != tradeList.end(); ++it)
    {
        QStandardItem* item1 = new QStandardItem(QString("%0").arg((*it)->getOrderRefId()));
        QStandardItem* item2 = new QStandardItem(QString((*it)->getQuoteId().c_str()));
        QStandardItem* item3 = new QStandardItem(QString(to_simple_string((*it)->getTradeTime()).c_str()));
        QStandardItem* item4 = new QStandardItem(QString("%0").arg((*it)->getBuySell()));
        QStandardItem* item5 = new QStandardItem(QString("%0").arg((*it)->getTradePrice()));
        QStandardItem* item6 = new QStandardItem(QString("%0").arg((*it)->getQty()));
        QStandardItem* item7 = new QStandardItem(QString("%0").arg((*it)->getStatus()));
        QList<QStandardItem *> child;
        child << item1 << item2 << item3 << item4 << item5 << item6 << item7;
        data->appendRow(child);
    }
    swingpositionsmodel_->insertRow(0, data);
}

void MainWindow::displaySwingUpdatePositions(Position *position)
{
    swingpositionsmodel_->removeRow(0);
    displaySwingAddPositions(position);
}

void MainWindow::add_swing_positions()
{
    Position *position = new Position;
    position->setQuoteId("EUR/USD");
    for(int i=0; i<5; i++)
    {
        TradeItem *tradeItem = new TradeItem;
        tradeItem->setQuoteId("EUR/USD");
        //tradeItem->setTradeTime(20130920 + i);
        tradeItem->setOrderType('M');
        tradeItem->setBuySell('B');
        tradeItem->setTradePrice(1.31415 + i * 0.00001);
        tradeItem->setQty(i + 1);
        position->getTradeList().push_front(tradeItem);
    }
    displaySwingAddPositions(position);
}

void MainWindow::update_swing_positions()
{
    Position *position = new Position;
    position->setQuoteId("DJIA");
    for(int i=0; i<3; i++)
    {
        TradeItem *tradeItem = new TradeItem;
        tradeItem->setQuoteId("DJIA");
        //tradeItem->setTradeTime(20130922 + i);
        tradeItem->setOrderType('L');
        tradeItem->setBuySell('S');
        tradeItem->setTradePrice(18888.1415 + i);
        tradeItem->setQty((i+1) * 100);
        position->getTradeList().push_front(tradeItem);
    }
    displaySwingUpdatePositions(position);
}

void MainWindow::displaySwingAddWorkingOrders(OrderItem *orderItem)
{
    QStandardItem* item1 = new QStandardItem(QString("%0").arg(orderItem->getOrderRefId()));
    QStandardItem* item2 = new QStandardItem(QString(orderItem->getQuoteId().c_str()));
    QStandardItem* item3 = new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    QStandardItem* item4 = new QStandardItem(QString("%0").arg(orderItem->getOrderType()));
    QStandardItem* item5 = new QStandardItem(QString("%0").arg(orderItem->getBuySell()));
    QStandardItem* item6 = new QStandardItem(QString("%0").arg(orderItem->getSubmitPrice()));
    QStandardItem* item7 = new QStandardItem(QString("%0").arg(orderItem->getQty()));
    QStandardItem* item8 = new QStandardItem(QString("%0").arg(orderItem->getStatus()));
    QList<QStandardItem *> data;
    data << item1 << item2 << item3 << item4 << item5 << item6 << item7 << item8;
    swingworkingordersmodel_->insertRow(0, data);
}

void MainWindow::displaySwingUpdateWorkingOrders(long orderRefId, OrderItem *orderItem)
{
    for(int i=0; i<swingworkingordersmodel_->rowCount(); i++)
    {
        if(swingworkingordersmodel_->item(i)->text().compare(QString("%0").arg(orderRefId)) == 0)
        {
            swingworkingordersmodel_->setItem(i, 0, new QStandardItem(QString("%0").arg(orderItem->getOrderRefId())));
            swingworkingordersmodel_->setItem(i, 1, new QStandardItem(QString(orderItem->getQuoteId().c_str())));
            swingworkingordersmodel_->setItem(i, 2, new QStandardItem(QDateTime::currentDateTime().toString("YYYY-mmm-DD HH:MM:SS.fffffffff")));
            swingworkingordersmodel_->setItem(i, 3, new QStandardItem(QString("%0").arg(orderItem->getOrderType())));
            swingworkingordersmodel_->setItem(i, 4, new QStandardItem(QString("%0").arg(orderItem->getBuySell())));
            swingworkingordersmodel_->setItem(i, 5, new QStandardItem(QString("%0").arg(orderItem->getSubmitPrice())));
            swingworkingordersmodel_->setItem(i, 6, new QStandardItem(QString("%0").arg(orderItem->getQty())));
            swingworkingordersmodel_->setItem(i, 7, new QStandardItem(QString("%0").arg(orderItem->getStatus())));
            break;
        }
    }
}

void MainWindow::displaySwingRemoveWorkingOrders(long orderRefId)
{
    for(int i=0; i<swingworkingordersmodel_->rowCount(); i++)
    {
        if(swingworkingordersmodel_->item(i)->text().compare(QString("%0").arg(orderRefId)) == 0)
        {
            swingworkingordersmodel_->removeRow(i);
            break;
        }
    }
}

void MainWindow::displaySwingAddOrderHistory(TradeItem *tradeItem)
{
    QStandardItem* item1 = new QStandardItem(QString("%0").arg(tradeItem->getOrderRefId()));
    QStandardItem* item2 = new QStandardItem(QString(tradeItem->getQuoteId().c_str()));
    QStandardItem* item3 = new QStandardItem(QString(to_simple_string(tradeItem->getTradeTime()).c_str()));
    QStandardItem* item4 = new QStandardItem(QString("%0").arg(tradeItem->getBuySell()));
    QStandardItem* item5 = new QStandardItem(QString("%0").arg(tradeItem->getTradePrice()));
    QStandardItem* item6 = new QStandardItem(QString("%0").arg(tradeItem->getQty()));
    QStandardItem* item7 = new QStandardItem(QString("%0").arg(tradeItem->getStatus()));
    QList<QStandardItem *> data;
    data << item1 << item2 << item3 << item4 << item5 << item6 << item7;
    swingorderhistorymodel_->insertRow(0, data);
}

void MainWindow::connect_dispatcher()
{
    LogInDialog *logindialog = new LogInDialog(&platforminfo_);
    if(logindialog->exec() == LogInDialog::Accepted)
    {
        disp_ = DispatcherFactory::createDispatcher(platforminfo_);
        ui_->action_Connect->setEnabled(false);
        insertswing_->setEnabled(true);
        insertcombo_->setEnabled(true);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui_->mdiArea_swing->closeAllSubWindows();
    if (ui_->mdiArea_swing->currentSubWindow()) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::click_swing_right()
{
    swingmdiright_->exec(QCursor::pos());
}

void MainWindow::click_combo_right()
{
    combomdiright_->exec(QCursor::pos());
}
