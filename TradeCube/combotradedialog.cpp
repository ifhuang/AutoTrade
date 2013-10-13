#include "combotradedialog.h"
#include "ui_combotradedialog.h"
#include <QSize>

ComboTradeDialog::ComboTradeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboTradeDialog)
{
    ui->setupUi(this);

    toolbar = new QToolBar(this);
    QSize pbSize(20, 20);
    pb1 = new QPushButton(tr("1"));
    pb1->setFixedSize(pbSize);
    toolbar->addWidget(pb1);

    label_strategy = new QLabel(tr("Strategy Name"));
    toolbar->addWidget(label_strategy);

    pb2 = new QPushButton(tr("2"));
    pb2->setFixedSize(pbSize);
    pb2_menu = new QMenu;
    pb2_menu_open = pb2_menu->addAction(tr("Open/Close Strategy"));
    pb2_menu->addSeparator();
    pb2_menu_attr = pb2_menu->addAction(tr("Attribute"));
    pb2_menu_auto = pb2_menu->addAction(tr("Auto Trade"));
    pb2_menu_warn = pb2_menu->addAction(tr("Warn"));
    toolbar->addWidget(pb2);

    label_blank = new QLabel(tr("                     "));
    toolbar->addWidget(label_blank);

    pb3 = new QPushButton(tr("3"));
    pb3->setFixedSize(pbSize);
    toolbar->addWidget(pb3);

    pb4 = new QPushButton(tr("4"));
    pb4->setFixedSize(pbSize);
    toolbar->addWidget(pb4);

    pb5 = new QPushButton(tr("5"));
    pb5->setFixedSize(pbSize);
    toolbar->addWidget(pb5);

    setContextMenuPolicy(Qt::CustomContextMenu);
    comboright = new QMenu;
    comboright_setwin = comboright->addAction(tr("Set Window"));
    comboright->addSeparator();
    comboright_insstr = comboright->addAction(tr("Insert Strategy"));
    comboright_setstr = comboright->addAction(tr("Set Strategy"));
    comboright_remstr = comboright->addAction(tr("Remove Strategy"));
    comboright->addSeparator();
    comboright_addcon = comboright->addAction(tr("Add Contract"));
    comboright_modcon = comboright->addAction(tr("Modify Contract"));
    comboright_remcon = comboright->addAction(tr("Remove Contract"));

    connect(pb2, SIGNAL(clicked()), this, SLOT(on_trigger_pb2()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested_combo()));

    setAttribute(Qt::WA_DeleteOnClose);
}

ComboTradeDialog::~ComboTradeDialog()
{
    delete ui;   
    delete pb1;
    delete label_strategy;
    delete pb2;
    delete label_blank;
    delete pb3;
    delete pb4;
    delete pb5;
    delete toolbar;
    delete pb2_menu_open;
    delete pb2_menu_attr;
    delete pb2_menu_auto;
    delete pb2_menu_warn;
    delete pb2_menu;
    delete comboright_setwin;
    delete comboright_insstr;
    delete comboright_setstr;
    delete comboright_remstr;
    delete comboright_addcon;
    delete comboright_modcon;
    delete comboright_remcon;
    delete comboright;
}

void ComboTradeDialog::on_tab_customContextMenuRequested_combo()
{
    comboright->exec(QCursor::pos());
}

void ComboTradeDialog::on_trigger_pb2()
{
    pb2_menu->exec(QCursor::pos());
}
