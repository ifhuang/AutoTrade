#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include "swingtradedialog.h"
#include <QMdiSubWindow>
#include "combotradedialog.h"
#include <QDesktopWidget>
#include <QResizeEvent>
#include <QSize>
#include <QMessageBox>

#include <iostream>
#include <list>

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
    ui->treeView->setModel(swingPositionsModel);

    swingWorkingOrdersModel = new QStandardItemModel;
    swingWorkingOrdersModel->setColumnCount(6);
    swingWorkingOrdersModel->setHeaderData(0, Qt::Horizontal, QString("Instruments"));
    swingWorkingOrdersModel->setHeaderData(1, Qt::Horizontal, QString("Date"));
    swingWorkingOrdersModel->setHeaderData(2, Qt::Horizontal, QString("Order Type"));
    swingWorkingOrdersModel->setHeaderData(3, Qt::Horizontal, QString("Buy Sell"));
    swingWorkingOrdersModel->setHeaderData(4, Qt::Horizontal, QString("Price"));
    swingWorkingOrdersModel->setHeaderData(5, Qt::Horizontal, QString("Quantity"));
    ui->tableView->setModel(swingWorkingOrdersModel);

    swingOrderHistoryModel = new QStandardItemModel;
    swingOrderHistoryModel->setColumnCount(6);
    swingOrderHistoryModel->setHeaderData(0, Qt::Horizontal, QString("Instruments"));
    swingOrderHistoryModel->setHeaderData(1, Qt::Horizontal, QString("Date"));
    swingOrderHistoryModel->setHeaderData(2, Qt::Horizontal, QString("Order Type"));
    swingOrderHistoryModel->setHeaderData(3, Qt::Horizontal, QString("Buy Sell"));
    swingOrderHistoryModel->setHeaderData(4, Qt::Horizontal, QString("Price"));
    swingOrderHistoryModel->setHeaderData(5, Qt::Horizontal, QString("Quantity"));
    ui->tableView_2->setModel(swingOrderHistoryModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_swing_trade()
{
    QString contractName;
    contractName = QString("Contract%1").arg(swing_counter);

    SwingTradeDialog *std = new SwingTradeDialog(contractName);
    std->setAttribute(Qt::WA_DeleteOnClose);    

    connect(std, SIGNAL(update_contract(QString)), this, SLOT(update_swing_contract(QString)));

    QMdiSubWindow *msw = ui->mdiArea->addSubWindow(std);
    msw->setAttribute(Qt::WA_DeleteOnClose);
    msw->setFixedSize(265, 220);
    msw->setWindowFlags(msw->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);

    QString swingTitle;
    swingTitle = QString("Contract%1-K-Exchange").arg(swing_counter);
    msw->setWindowTitle(swingTitle);
    msw->show();

    swing_counter++;
    selCon->setCurrentText(contractName);
}

void MainWindow::new_combo_trade()
{
    ComboTradeDialog *ctd = new ComboTradeDialog;
    ctd->setAttribute(Qt::WA_DeleteOnClose);
    QMdiSubWindow *msw = ui->mdiArea_2->addSubWindow(ctd);
    msw->setAttribute(Qt::WA_DeleteOnClose);
    msw->setFixedSize(320, 240);
    msw->setWindowFlags(msw->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);

    msw->show();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    QSize centralSize = ui->centralWidget->size();
    ui->tabWidget->resize(centralSize);
    ui->tab->resize(centralSize);
    ui->tab_2->resize(centralSize);

    double mdi_tab = 0.8;
    ui->mdiArea->resize(centralSize.width(), centralSize.height() * mdi_tab);
    ui->tabWidget_2->setGeometry(0, centralSize.height() * mdi_tab, centralSize.width(), centralSize.height());
    ui->treeView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui->tableView->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui->tableView_2->setGeometry(0, 0, centralSize.width() - 30, centralSize.height() * (1 - mdi_tab) - 30);
    ui->mdiArea_2->resize(centralSize.width(), centralSize.height() * mdi_tab);
    ui->tabWidget_3->setGeometry(0, centralSize.height() * mdi_tab, centralSize.width(), centralSize.height());
}

void MainWindow::about()
{
    QMessageBox::about(NULL, tr("About"), tr("Created By IIPL@FDU"));
}

void MainWindow::activate_swing()
{
    SwingTradeDialog *std = NULL;
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        std = qobject_cast<SwingTradeDialog *>(activeSubWindow->widget());
    if(std != NULL)
    {
        selCon->setCurrentText(std->getSwingContract());
    }
}

void MainWindow::activate_combo()
{
    ComboTradeDialog *ctd = NULL;
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea_2->activeSubWindow())
        ctd = qobject_cast<ComboTradeDialog *>(activeSubWindow->widget());
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
        TradeItem *ti = (TradeItem *)*it;
        QStandardItem* item1 = new QStandardItem;
        QStandardItem* item2 = new QStandardItem(QString("%1").arg(ti->getTradeTime()));
        QStandardItem* item3 = new QStandardItem(QString("%1").arg(ti->getOrderType()));
        QStandardItem* item4 = new QStandardItem(QString("%1").arg(ti->getBuySell()));
        QStandardItem* item5 = new QStandardItem(QString("%1").arg(ti->getTradePrice()));
        QStandardItem* item6 = new QStandardItem(QString("%1").arg(ti->getQty()));
        QList<QStandardItem *> child;
        child << item1 << item2 << item3 << item4 << item5 << item6;
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
    Position position;
    position.setQuoteId("EUR/USD");
    for(int i=0; i<5; i++)
    {
        TradeItem ti;
        ti.setTradeTime(20130925);
        ti.setOrderType('M');
        ti.setBuySell('B');
        ti.setTradePrice(1.31415);
        ti.setQty(10);
        position.getTradeList().push_back(&ti);

    }
    displaySwingAddPositions(&position);
}

void MainWindow::update_swing_positions()
{
    Position position;
    position.setQuoteId("DJIA");
    for(int i=0; i<3; i++)
    {
        TradeItem ti;
        ti.setTradeTime(20130924);
        ti.setOrderType('L');
        ti.setBuySell('S');
        ti.setTradePrice(18888.5657);
        ti.setQty(200);
        position.getTradeList().push_back(&ti);

    }
    displaySwingUpdatePositions(&position);
}

void MainWindow::displaySwingAddWorkingOrders(OrderItem *orderItem)
{
    QStandardItem* item1 = new QStandardItem(QString(orderItem->getQuoteId().c_str()));
    QStandardItem* item2 = new QStandardItem;
    QStandardItem* item3 = new QStandardItem(QString("%1").arg(orderItem->getOrderType()));
    QStandardItem* item4 = new QStandardItem(QString("%1").arg(orderItem->getBuySell()));
    QStandardItem* item5 = new QStandardItem(QString("%1").arg(orderItem->getSubmitPrice()));
    QStandardItem* item6 = new QStandardItem(QString("%1").arg(orderItem->getQty()));
    QList<QStandardItem *> data;
    data << item1 << item2 << item3 << item4 << item5 << item6;
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
    OrderItem oi;
    oi.setQuoteId("EUR/USD");
    oi.setOrderType(1);
    oi.setBuySell('B');
    oi.setSubmitPrice(1.31415);
    oi.setQty(10);
    displaySwingAddWorkingOrders(&oi);
}

void MainWindow::update_swing_working_orders()
{
    OrderItem oi;
    oi.setQuoteId("DJIA");
    oi.setOrderType(2);
    oi.setBuySell('S');
    oi.setSubmitPrice(18888.589);
    oi.setQty(200);
    displaySwingUpdateWorkingOrders(&oi);
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
    data << item1 << item2 << item3 << item4 << item5 << item6;
    swingOrderHistoryModel->insertRow(0, data);
}

void MainWindow::add_swing_order_history()
{
    TradeItem ti;
    ti.setQuoteId("DJIA");
    ti.setTradeTime(20130924);
    ti.setOrderType('L');
    ti.setBuySell('S');
    ti.setTradePrice(18888.5657);
    ti.setQty(200);
    displaySwingAddOrderHistory(&ti);
}
