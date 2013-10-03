#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "swingtradedialog.h"
#include <QMdiSubWindow>
#include "combotradedialog.h"
#include <QResizeEvent>
#include <QSize>
#include <QMessageBox>
#include <list>
#include "TC/DispatcherFactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //int currentScreenWid = QApplication::desktop()->width();
    //int currentScreenHei = QApplication::desktop()->height();
    //setFixedSize(currentScreenWid, currentScreenHei);
    showMaximized();

    selCon = new QComboBox;
    selCon->insertItem(0, tr("Select Contract"));
    selCon->setEditable(true);
    ui->mainToolBar->addWidget(selCon);

    orderType = new QComboBox;
    orderType->insertItem(0, tr("Order Type"));
    orderType->insertItem(1, tr("Market"));
    orderType->insertItem(2, tr("Stop"));
    orderType->insertItem(3, tr("Limit"));
    orderType->insertItem(4, tr("Stop Limit"));
    ui->mainToolBar->addWidget(orderType);

    qty = new QLineEdit;
    qty->setText(tr("Quantity"));
    qty->setMaximumWidth(60);
    ui->mainToolBar->addWidget(qty);

    price = new QLineEdit;
    price->setText(tr("Price"));
    price->setMaximumWidth(40);
    ui->mainToolBar->addWidget(price);

    valid = new QComboBox;
    valid->insertItem(0, tr("Validity"));
    valid->insertItem(1, tr("DAY"));
    valid->insertItem(2, tr("GTC"));
    valid->insertItem(3, tr("GTD"));
    valid->insertItem(4, tr("IOC"));
    ui->mainToolBar->addWidget(valid);

    buy = new QPushButton;
    buy->setText(tr("Buy"));
    ui->mainToolBar->addWidget(buy);

    sell = new QPushButton;
    sell->setText(tr("Sell"));
    ui->mainToolBar->addWidget(sell);

    swing_counter = 0;
    combo_counter = 0;

    swingPositionsModel = new QStandardItemModel;
    swingPositionsModel->setColumnCount(6);
    swingPositionsModel->setHeaderData(0, Qt::Horizontal, QString("Instruments"));
    swingPositionsModel->setHeaderData(1, Qt::Horizontal, QString("Date"));
    swingPositionsModel->setHeaderData(2, Qt::Horizontal, QString("Order Type"));
    swingPositionsModel->setHeaderData(3, Qt::Horizontal, QString("Buy Sell"));
    swingPositionsModel->setHeaderData(4, Qt::Horizontal, QString("Price"));
    swingPositionsModel->setHeaderData(5, Qt::Horizontal, QString("Quantity"));
    ui->swingPositionsView->setModel(swingPositionsModel);

    swingWorkingOrdersModel = new QStandardItemModel;
    swingWorkingOrdersModel->setColumnCount(6);
    swingWorkingOrdersModel->setHeaderData(0, Qt::Horizontal, QString("Instruments"));
    swingWorkingOrdersModel->setHeaderData(1, Qt::Horizontal, QString("Date"));
    swingWorkingOrdersModel->setHeaderData(2, Qt::Horizontal, QString("Order Type"));
    swingWorkingOrdersModel->setHeaderData(3, Qt::Horizontal, QString("Buy Sell"));
    swingWorkingOrdersModel->setHeaderData(4, Qt::Horizontal, QString("Price"));
    swingWorkingOrdersModel->setHeaderData(5, Qt::Horizontal, QString("Quantity"));
    ui->swingWorkingOrdersView->setModel(swingWorkingOrdersModel);

    swingOrderHistoryModel = new QStandardItemModel;
    swingOrderHistoryModel->setColumnCount(6);
    swingOrderHistoryModel->setHeaderData(0, Qt::Horizontal, QString("Instruments"));
    swingOrderHistoryModel->setHeaderData(1, Qt::Horizontal, QString("Date"));
    swingOrderHistoryModel->setHeaderData(2, Qt::Horizontal, QString("Order Type"));
    swingOrderHistoryModel->setHeaderData(3, Qt::Horizontal, QString("Buy Sell"));
    swingOrderHistoryModel->setHeaderData(4, Qt::Horizontal, QString("Price"));
    swingOrderHistoryModel->setHeaderData(5, Qt::Horizontal, QString("Quantity"));
    ui->swingOrderHistoryView->setModel(swingOrderHistoryModel);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete selCon;
    delete orderType;
    delete qty;
    delete price;
    delete valid;
    delete buy;
    delete sell;
    delete swingPositionsModel;
    delete swingWorkingOrdersModel;
    delete swingOrderHistoryModel;
}

void MainWindow::new_swing_trade()
{
    QString contractName = QString("Exchange-Contract-%1").arg(swing_counter);
    SwingTradeDialog *swingTradeDialog = new SwingTradeDialog(contractName, swing_counter, disp);
    swingTradeDialog->setAttribute(Qt::WA_DeleteOnClose);

    connect(swingTradeDialog, SIGNAL(update_contract(QString)), this, SLOT(update_swing_contract(QString)));

    QMdiSubWindow *qMdiSubWindow = ui->mdiArea_swing->addSubWindow(swingTradeDialog);
    qMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    qMdiSubWindow->setFixedSize(265, 220);
    qMdiSubWindow->setWindowFlags(qMdiSubWindow->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    qMdiSubWindow->setWindowTitle(contractName);
    qMdiSubWindow->show();

    swing_counter++;
    selCon->setCurrentText(contractName);
}

void MainWindow::new_combo_trade()
{
    ComboTradeDialog *comboTradeDialog = new ComboTradeDialog;
    comboTradeDialog->setAttribute(Qt::WA_DeleteOnClose);

    QMdiSubWindow *qMdiSubWindow = ui->mdiArea_combo->addSubWindow(comboTradeDialog);
    qMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    qMdiSubWindow->setFixedSize(320, 240);
    qMdiSubWindow->setWindowFlags(qMdiSubWindow->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    qMdiSubWindow->show();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    QSize centralSize = ui->centralWidget->size();
    ui->tabWidget->resize(centralSize);
    ui->tab_swing->resize(centralSize);
    ui->tab_combo->resize(centralSize);

    double mdi_tab = 0.8;
    ui->mdiArea_swing->resize(centralSize.width(), centralSize.height() * mdi_tab);
    ui->tabWidget_swing->setGeometry(0, centralSize.height() * mdi_tab, centralSize.width(), centralSize.height());
    ui->swingPositionsView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui->swingWorkingOrdersView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui->swingOrderHistoryView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui->mdiArea_combo->resize(centralSize.width(), centralSize.height() * mdi_tab);
    ui->tabWidget_combo->setGeometry(0, centralSize.height() * mdi_tab, centralSize.width(), centralSize.height());
}

void MainWindow::about()
{
    QMessageBox::about(NULL, tr("About"), tr("Created By IIPL@FDU"));
}

void MainWindow::activate_swing()
{
    SwingTradeDialog *swingTradeDialog = NULL;
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea_swing->activeSubWindow())
        swingTradeDialog = qobject_cast<SwingTradeDialog *>(activeSubWindow->widget());
    if(swingTradeDialog != NULL)
    {
        selCon->setCurrentText(swingTradeDialog->getSwingContract());
    }
}

void MainWindow::activate_combo()
{
    ComboTradeDialog *comboTradeDialog = NULL;
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea_combo->activeSubWindow())
        comboTradeDialog = qobject_cast<ComboTradeDialog *>(activeSubWindow->widget());
}

void MainWindow::update_swing_contract(QString contract)
{
    selCon->setCurrentText(contract);
}

void MainWindow::displaySwingAddPositions(Position *position)
{
    QStandardItem *data = new QStandardItem(QString(position->getQuoteId().c_str()));
    list<TradeItem *> tradeList = position->getTradeList();
    for(list<TradeItem *>::const_iterator it = tradeList.begin(); it != tradeList.end(); ++it)
    {
        QStandardItem* item1 = new QStandardItem(QString((*it)->getQuoteId().c_str()));
        QStandardItem* item2 = new QStandardItem(QString("%1").arg((*it)->getTradeTime()));
        QStandardItem* item3 = new QStandardItem(QString("%1").arg((*it)->getOrderType()));
        QStandardItem* item4 = new QStandardItem(QString("%1").arg((*it)->getBuySell()));
        QStandardItem* item5 = new QStandardItem(QString("%1").arg((*it)->getTradePrice()));
        QStandardItem* item6 = new QStandardItem(QString("%1").arg((*it)->getQty()));
        QList<QStandardItem *> child;
        child<<item1<<item2<<item3<<item4<<item5<<item6;
        data->appendRow(child);
    }
    swingPositionsModel->insertRow(0, data);
}

void MainWindow::displaySwingUpdatePositions(Position *position)
{
    swingPositionsModel->removeRow(0);
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
        tradeItem->setTradeTime(20130920 + i);
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
        tradeItem->setTradeTime(20130922 + i);
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
    QStandardItem* item1 = new QStandardItem(QString(orderItem->getQuoteId().c_str()));
    QStandardItem* item2 = new QStandardItem(QString("20130925"));
    QStandardItem* item3 = new QStandardItem(QString("%1").arg(orderItem->getOrderType()));
    QStandardItem* item4 = new QStandardItem(QString("%1").arg(orderItem->getBuySell()));
    QStandardItem* item5 = new QStandardItem(QString("%1").arg(orderItem->getSubmitPrice()));
    QStandardItem* item6 = new QStandardItem(QString("%1").arg(orderItem->getQty()));
    QList<QStandardItem *> data;
    data<<item1<<item2<<item3<<item4<<item5<<item6;
    swingWorkingOrdersModel->insertRow(0, data);
}

void MainWindow::displaySwingUpdateWorkingOrders(OrderItem *orderItem)
{
    swingWorkingOrdersModel->removeRow(0);
    displaySwingAddWorkingOrders(orderItem);
}

void MainWindow::displaySwingRemoveWorkingOrders()
{
    swingWorkingOrdersModel->removeRow(0);
}

void MainWindow::add_swing_working_orders()
{
    OrderItem *orderItem = new OrderItem(0, "EUR/USD", (qrand() % 10000)/1000., qrand() % 100, 'B', 1, 0, 'O' );
    displaySwingAddWorkingOrders(orderItem);
}

void MainWindow::update_swing_working_orders()
{
    OrderItem *orderItem = new OrderItem(0, "DJIA", (qrand() % 10000)/1., qrand() % 1000, 'S', 0, 0, 'C' );
    displaySwingUpdateWorkingOrders(orderItem);
}

void MainWindow::remove_swing_working_orders()
{
    displaySwingRemoveWorkingOrders();
}

void MainWindow::displaySwingAddOrderHistory(TradeItem *tradeItem)
{
    QStandardItem* item1 = new QStandardItem(QString(tradeItem->getQuoteId().c_str()));
    QStandardItem* item2 = new QStandardItem(QString("%1").arg(tradeItem->getTradeTime()));
    QStandardItem* item3 = new QStandardItem(QString("%1").arg(tradeItem->getOrderType()));
    QStandardItem* item4 = new QStandardItem(QString("%1").arg(tradeItem->getBuySell()));
    QStandardItem* item5 = new QStandardItem(QString("%1").arg(tradeItem->getTradePrice()));
    QStandardItem* item6 = new QStandardItem(QString("%1").arg(tradeItem->getQty()));
    QList<QStandardItem *> data;
    data<<item1<<item2<<item3<<item4<<item5<<item6;
    swingOrderHistoryModel->insertRow(0, data);
}

void MainWindow::add_swing_order_history()
{
    TradeItem *tradeItem = new TradeItem;
    tradeItem->setQuoteId("DJIA");
    tradeItem->setTradeTime(20130920 + qrand() % 10);
    tradeItem->setOrderType('L');
    tradeItem->setBuySell('S');
    tradeItem->setTradePrice(qrand() % 10000);
    tradeItem->setQty(qrand() % 1000);
    displaySwingAddOrderHistory(tradeItem);
}

void MainWindow::connect_dispatcher()
{
    platformInfo.platformName = SPTRADER;
    platformInfo.server = "127.0.0.1";
    platformInfo.accountNo = "DEMO258";
    platformInfo.password = "12341234";
    platformInfo.orderPort = 8092;
    platformInfo.pricePort = 8089;
    platformInfo.tickPort = 8090;
    disp = DispatcherFactory::createDispatcher(platformInfo);
}
