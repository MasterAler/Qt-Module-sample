#pragma once

#include "PluginInterface.h"

class SecondPlugin : public QObject, public PluginInterface
{
    Q_OBJECT

    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid)

public:
    explicit SecondPlugin(QObject* parent = nullptr);

    QString id() const override;
    SubviewWidget* createSubview() const override;
    QVariantMap permissions() const override;
};
