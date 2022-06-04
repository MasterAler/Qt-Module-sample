#pragma once

#include "Subview.h"

#include <QWidget>

namespace Ui {
class SecondModule;
}

class SecondModule : public Subview
{
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)
    Q_PLUGIN_METADATA(IID ModuleInterface_iid)

public:
    explicit SecondModule(QWidget *parent = 0);
    virtual ~SecondModule();

    QString name() const override;
    QByteArray id() const override;

private:
    Ui::SecondModule *ui;
};

