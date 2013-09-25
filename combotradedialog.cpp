#include "combotradedialog.h"
#include "ui_combotradedialog.h"
#include <QSize>

ComboTradeDialog::ComboTradeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboTradeDialog)
{
    ui->setupUi(this);

    toolBar = new QToolBar(this);

    QSize pbSize(20, 20);

    pb1 = new QPushButton("1");
    pb1->setFixedSize(pbSize);
    toolBar->addWidget(pb1);

    label1 = new QLabel("Strategy Name");
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

    label2 = new QLabel("                     ");
    toolBar->addWidget(label2);

    pb2 = new QPushButton("3");
    pb2->setFixedSize(pbSize);
    toolBar->addWidget(pb2);

    pb3 = new QPushButton("4");
    pb3->setFixedSize(pbSize);
    toolBar->addWidget(pb3);

    pb4 = new QPushButton("5");
    pb4->setFixedSize(pbSize);
    toolBar->addWidget(pb4);

    setContextMenuPolicy(Qt::CustomContextMenu);
    comboRight = new QMenu;
    comboRight_setwin = comboRight->addAction(tr("Set Window"));
    comboRight->addSeparator();
    comboRight_insstr = comboRight->addAction(tr("Insert Strategy"));
    comboRight_setstr = comboRight->addAction(tr("Set Strategy"));
    comboRight_remstr = comboRight->addAction(tr("Remove Strategy"));
    comboRight->addSeparator();
    comboRight_addcon = comboRight->addAction(tr("Add Contract"));
    comboRight_modcon = comboRight->addAction(tr("Modify Contract"));
    comboRight_remcon = comboRight->addAction(tr("Remove Contract"));

    connect(cb1, SIGNAL(clicked()), this, SLOT(on_trigger_cb1()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested_combo()));
}

ComboTradeDialog::~ComboTradeDialog()
{
    delete ui;
}

void ComboTradeDialog::on_tab_customContextMenuRequested_combo()
{
    comboRight->exec(QCursor::pos());
}

void ComboTradeDialog::on_trigger_cb1()
{
    cb1_menu->exec(QCursor::pos());
}
