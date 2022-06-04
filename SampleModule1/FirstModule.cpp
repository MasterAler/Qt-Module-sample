#include "FirstModule.h"
#include "ui_FirstModule.h"

FirstModule::FirstModule(QWidget *parent)
    : SubviewWidget(parent)
    , ui(new Ui::FirstModule)
{
    ui->setupUi(this);
}

FirstModule::~FirstModule()
{
    delete ui;
}

QString FirstModule::name() const
{
    return "First attempt";
}
