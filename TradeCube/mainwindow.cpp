#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "swingtradedialog.h"
#include <QMdiSubWindow>
#include "combotradedialog.h"
#include <QResizeEvent>
#include <QSize>
#include <QMessageBox>
#include <list>
#include "../TC/DispatcherFactory.h"
#include "logindialog.h"
#include <QDateTime>
#include <boost/date_time/posix_time/posix_time.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    swing_counter = 0;
    combo_counter = 0;

    ui->setupUi(this);
    //int currentScreenWid = QApplication::desktop()->width();
    //int currentScreenHei = QApplication::desktop()->height();
    //setFixedSize(currentScreenWid, currentScreenHei);
    showMaximized();

    selcon = new QComboBox;
    selcon->insertItem(0, tr("Select Contract"));
    selcon->setEditable(true);
    ui->mainToolBar->addWidget(selcon);
    ordertype = new QComboBox;
    ordertype->insertItem(0, tr("Order Type"));
    ordertype->insertItem(1, tr("Market"));
    ordertype->insertItem(2, tr("Stop"));
    ordertype->insertItem(3, tr("Limit"));
    ordertype->insertItem(4, tr("Stop Limit"));
    ui->mainToolBar->addWidget(ordertype);
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

    swingmdiright = new QMenu;
    insertswing = swingmdiright->addAction(tr("Insert Swing Trader"));
    insertswing->setEnabled(false);

    combomdiright = new QMenu;
    insertcombo = combomdiright->addAction(tr("Insert Combo Trader"));
    insertcombo->setEnabled(false);

    swingpositionsmodel = new QStandardItemModel;
    swingpositionsmodel->setColumnCount(7);
    swingpositionsmodel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    swingpositionsmodel->setHeaderData(1, Qt::Horizontal, tr("Instrument"));
    swingpositionsmodel->setHeaderData(2, Qt::Horizontal, tr("Date"));
    swingpositionsmodel->setHeaderData(3, Qt::Horizontal, tr("Buy Sell"));
    swingpositionsmodel->setHeaderData(4, Qt::Horizontal, tr("Price"));
    swingpositionsmodel->setHeaderData(5, Qt::Horizontal, tr("Quantity"));
    swingpositionsmodel->setHeaderData(6, Qt::Horizontal, tr("Status"));
    ui->swingPositionsView->setModel(swingpositionsmodel);

    swingworkingordersmodel = new QStandardItemModel;
    swingworkingordersmodel->setColumnCount(8);
    swingworkingordersmodel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    swingworkingordersmodel->setHeaderData(1, Qt::Horizontal, tr("Instrument"));
    swingworkingordersmodel->setHeaderData(2, Qt::Horizontal, tr("Date"));
    swingworkingordersmodel->setHeaderData(3, Qt::Horizontal, tr("Order Type"));
    swingworkingordersmodel->setHeaderData(4, Qt::Horizontal, tr("Buy Sell"));
    swingworkingordersmodel->setHeaderData(5, Qt::Horizontal, tr("Price"));
    swingworkingordersmodel->setHeaderData(6, Qt::Horizontal, tr("Quantity"));
    swingworkingordersmodel->setHeaderData(7, Qt::Horizontal, tr("Status"));
    ui->swingWorkingOrdersView->setModel(swingworkingordersmodel);

    swingorderhistorymodel = new QStandardItemModel;
    swingorderhistorymodel->setColumnCount(7);
    swingorderhistorymodel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    swingorderhistorymodel->setHeaderData(1, Qt::Horizontal, tr("Instrument"));
    swingorderhistorymodel->setHeaderData(2, Qt::Horizontal, tr("Date"));
    swingorderhistorymodel->setHeaderData(3, Qt::Horizontal, tr("Buy Sell"));
    swingorderhistorymodel->setHeaderData(4, Qt::Horizontal, tr("Price"));
    swingorderhistorymodel->setHeaderData(5, Qt::Horizontal, tr("Quantity"));
    swingorderhistorymodel->setHeaderData(6, Qt::Horizontal, tr("Status"));
    ui->swingOrderHistoryView->setModel(swingorderhistorymodel);

    connect(insertswing, SIGNAL(triggered()), this, SLOT(new_swing_trade()));
    connect(insertcombo, SIGNAL(triggered()), this, SLOT(new_combo_trade()));

//    setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete selcon;
    delete ordertype;
    delete qty;
    delete price;
    delete valid;
    delete buy;
    delete sell;
    delete swingpositionsmodel;
    delete swingworkingordersmodel;
    delete swingorderhistorymodel;
    delete ui;
    delete insertswing;
    delete swingmdiright;
    delete insertcombo;
    delete combomdiright;
//    delete disp;

}

void MainWindow::new_swing_trade()
{
    QString contractName = tr("Exchange-Contract-").append(QString("%1").arg(swing_counter));
    SwingTradeDialog *swingTradeDialog = new SwingTradeDialog(contractName, swing_counter, disp, this);

    connect(swingTradeDialog, SIGNAL(update_contract(QString)), this, SLOT(update_swing_contract(QString)));

    QMdiSubWindow *qMdiSubWindow = ui->mdiArea_swing->addSubWindow(swingTradeDialog);
    qMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    qMdiSubWindow->setFixedSize(265, 220);
    qMdiSubWindow->setWindowFlags(qMdiSubWindow->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    qMdiSubWindow->setWindowTitle(contractName);
    qMdiSubWindow->show();

    swing_counter++;
    selcon->setCurrentText(contractName);
}

void MainWindow::new_combo_trade()
{
    ComboTradeDialog *comboTradeDialog = new ComboTradeDialog;
    QMdiSubWindow *qMdiSubWindow = ui->mdiArea_combo->addSubWindow(comboTradeDialog);
    qMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    qMdiSubWindow->setFixedSize(320, 240);
    qMdiSubWindow->setWindowFlags(qMdiSubWindow->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    qMdiSubWindow->show();
}

void MainWindow::resizeEvent(QResizeEvent *event)
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
        selcon->setCurrentText(swingTradeDialog->getExchangeContract());
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
    selcon->setCurrentText(contract);
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
    swingpositionsmodel->insertRow(0, data);
}

void MainWindow::displaySwingUpdatePositions(Position *position)
{
    swingpositionsmodel->removeRow(0);
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
    swingworkingordersmodel->insertRow(0, data);
}

void MainWindow::displaySwingUpdateWorkingOrders(long orderRefId, OrderItem *orderItem)
{
    for(int i=0; i<swingworkingordersmodel->rowCount(); i++)
    {
        if(swingworkingordersmodel->item(i)->text().compare(QString("%0").arg(orderRefId)) == 0)
        {
            swingworkingordersmodel->setItem(i, 0, new QStandardItem(QString("%0").arg(orderItem->getOrderRefId())));
            swingworkingordersmodel->setItem(i, 1, new QStandardItem(QString(orderItem->getQuoteId().c_str())));
            swingworkingordersmodel->setItem(i, 2, new QStandardItem(QDateTime::currentDateTime().toString("YYYY-mmm-DD HH:MM:SS.fffffffff")));
            swingworkingordersmodel->setItem(i, 3, new QStandardItem(QString("%0").arg(orderItem->getOrderType())));
            swingworkingordersmodel->setItem(i, 4, new QStandardItem(QString("%0").arg(orderItem->getBuySell())));
            swingworkingordersmodel->setItem(i, 5, new QStandardItem(QString("%0").arg(orderItem->getSubmitPrice())));
            swingworkingordersmodel->setItem(i, 6, new QStandardItem(QString("%0").arg(orderItem->getQty())));
            swingworkingordersmodel->setItem(i, 7, new QStandardItem(QString("%0").arg(orderItem->getStatus())));
            break;
        }
    }
}

void MainWindow::displaySwingRemoveWorkingOrders(long orderRefId)
{
    for(int i=0; i<swingworkingordersmodel->rowCount(); i++)
    {
        if(swingworkingordersmodel->item(i)->text().compare(QString("%0").arg(orderRefId)) == 0)
        {
            swingworkingordersmodel->removeRow(i);
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
    swingorderhistorymodel->insertRow(0, data);
}

void MainWindow::connect_dispatcher()
{
    LogInDialog *logindialog = new LogInDialog(&platforminfo);
    if(logindialog->exec() == LogInDialog::Accepted)
    {
        disp = DispatcherFactory::createDispatcher(platforminfo);
        ui->action_Connect->setEnabled(false);
        insertswing->setEnabled(true);
        insertcombo->setEnabled(true);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea_swing->closeAllSubWindows();
    if (ui->mdiArea_swing->currentSubWindow()) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::click_swing_right()
{
    swingmdiright->exec(QCursor::pos());
}

void MainWindow::click_combo_right()
{
    combomdiright->exec(QCursor::pos());
}
