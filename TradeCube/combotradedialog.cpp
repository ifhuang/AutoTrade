#include "combotradedialog.h"
#include "ui_combotradedialog.h"

#include <QSize>

ComboTradeDialog::ComboTradeDialog(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::ComboTradeDialog)
{
    ui_->setupUi(this);
    setupToolbar();
    setupStrategyButton();
    setupRightPopup();
    setupConnect();

    setAttribute(Qt::WA_DeleteOnClose);
}

void ComboTradeDialog::setupToolbar()
{
    toolbar_ = new QToolBar(this);
    QSize pbSize(20, 20);
    pb1_ = new QPushButton(tr("1"));
    pb1_->setFixedSize(pbSize);
    toolbar_->addWidget(pb1_);
    label_strategy_ = new QLabel(tr("Strategy Name"));
    toolbar_->addWidget(label_strategy_);
    pb2_ = new QPushButton(tr("2"));
    pb2_->setFixedSize(pbSize);
    toolbar_->addWidget(pb2_);
    label_blank_ = new QLabel(tr("                     "));
    toolbar_->addWidget(label_blank_);
    pb3_ = new QPushButton(tr("3"));
    pb3_->setFixedSize(pbSize);
    toolbar_->addWidget(pb3_);
    pb4_ = new QPushButton(tr("4"));
    pb4_->setFixedSize(pbSize);
    toolbar_->addWidget(pb4_);
    pb5_ = new QPushButton(tr("5"));
    pb5_->setFixedSize(pbSize);
    toolbar_->addWidget(pb5_);
}

void ComboTradeDialog::setupStrategyButton()
{
    pb2_menu_ = new QMenu;
    pb2_menu_open_ = pb2_menu_->addAction(tr("Open/Close Strategy"));
    pb2_menu_->addSeparator();
    pb2_menu_attr_ = pb2_menu_->addAction(tr("Attribute"));
    pb2_menu_auto_ = pb2_menu_->addAction(tr("Auto Trade"));
    pb2_menu_warn_ = pb2_menu_->addAction(tr("Warn"));
}

void ComboTradeDialog::setupRightPopup()
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    comboright_ = new QMenu;
    comboright_setwin_ = comboright_->addAction(tr("Set Window"));
    comboright_->addSeparator();
    comboright_insstr_ = comboright_->addAction(tr("Insert Strategy"));
    comboright_setstr_ = comboright_->addAction(tr("Set Strategy"));
    comboright_remstr_ = comboright_->addAction(tr("Remove Strategy"));
    comboright_->addSeparator();
    comboright_addcon_ = comboright_->addAction(tr("Add Contract"));
    comboright_modcon_ = comboright_->addAction(tr("Modify Contract"));
    comboright_remcon_ = comboright_->addAction(tr("Remove Contract"));
}

void ComboTradeDialog::setupConnect()
{
    connect(pb2_, SIGNAL(clicked()), this, SLOT(on_trigger_pb2()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tab_customContextMenuRequested_combo()));
}

ComboTradeDialog::~ComboTradeDialog()
{
    delete ui_;
    delete pb1_;
    delete label_strategy_;
    delete pb2_;
    delete label_blank_;
    delete pb3_;
    delete pb4_;
    delete pb5_;
    delete toolbar_;
    delete pb2_menu_open_;
    delete pb2_menu_attr_;
    delete pb2_menu_auto_;
    delete pb2_menu_warn_;
    delete pb2_menu_;
    delete comboright_setwin_;
    delete comboright_insstr_;
    delete comboright_setstr_;
    delete comboright_remstr_;
    delete comboright_addcon_;
    delete comboright_modcon_;
    delete comboright_remcon_;
    delete comboright_;
}

void ComboTradeDialog::on_tab_customContextMenuRequested_combo()
{
    comboright_->exec(QCursor::pos());
}

void ComboTradeDialog::on_trigger_pb2()
{
    pb2_menu_->exec(QCursor::pos());
}
