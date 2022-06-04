#include "SecondModule.h"
#include "ui_SecondModule.h"

SecondModule::SecondModule(QWidget *parent)
    : Subview(parent)
    , ui(new Ui::SecondModule)
{
    ui->setupUi(this);
}

SecondModule::~SecondModule()
{
    delete ui;
}

QString SecondModule::name() const
{
    return "OLOLO";
}

QByteArray SecondModule::id() const
{
    return "Second222";
}
