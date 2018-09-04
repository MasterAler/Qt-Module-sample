#pragma once

#include <QtPlugin>
#include <QVariant>

class SubviewWidget;

class PluginInterface
{
public:
    virtual ~PluginInterface() {}

    virtual QString id() const = 0;
    virtual SubviewWidget* createSubview() const = 0;
    virtual QVariantMap permissions() const = 0;
};

#define PluginInterface_iid "org.kraftway.qt.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
