#pragma once

#include "SubviewWidget.h"

#include <QWidget>

namespace Ui {
class FirstModule;
}

class FirstModule :  public SubviewWidget
{
    Q_OBJECT

public:
    explicit FirstModule(QWidget *parent = 0);
    ~FirstModule();

    QString name() const override;

private:
    Ui::FirstModule *ui;
};

