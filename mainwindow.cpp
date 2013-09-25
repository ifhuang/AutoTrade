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
