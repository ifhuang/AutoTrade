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

    label_strategy = new QLabel("Strategy Name");
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

    label_blank = new QLabel("                     ");
    toolBar->addWidget(label_blank);

    pb3 = new QPushButton("3");
    pb3->setFixedSize(pbSize);
    toolBar->addWidget(pb3);

    pb4 = new QPushButton("4");
    pb4->setFixedSize(pbSize);
    toolBar->addWidget(pb4);

    pb5 = new QPushButton("5");
    pb5->setFixedSize(pbSize);
    toolBar->addWidget(pb5);

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

    connect(pb2, SIGNAL(clicked()), this, SLOT(on_trigger_pb2()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested_combo()));
}

ComboTradeDialog::~ComboTradeDialog()
{
    delete ui;
    delete toolBar;
    delete pb2_menu;
    delete comboRight;
    delete pb1;
    delete label_strategy;
    delete pb2;
    delete label_blank;
    delete pb3;
    delete pb4;
    delete pb5;
    delete pb2_menu_open;
    delete pb2_menu_attr;
    delete pb2_menu_auto;
    delete pb2_menu_warn;
    delete comboRight_setwin;
    delete comboRight_insstr;
    delete comboRight_setstr;
    delete comboRight_remstr;
    delete comboRight_addcon;
    delete comboRight_modcon;
    delete comboRight_remcon;
}

void ComboTradeDialog::on_tab_customContextMenuRequested_combo()
{
    comboRight->exec(QCursor::pos());
}

void ComboTradeDialog::on_trigger_pb2()
{
    pb2_menu->exec(QCursor::pos());
}
