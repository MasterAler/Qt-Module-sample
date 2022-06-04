#pragma once

#include <QtPlugin>

class QWidget;
class Subview;

class ModuleInterface
{
public:
    virtual ~ModuleInterface() {}

    virtual bool activate() = 0;
    virtual void stop() = 0;

    virtual QByteArray id() const = 0;
    virtual QString name() const = 0;
    virtual Subview* widget() const = 0;
};

#define ModuleInterface_iid "org.kraftway.qt.ModuleInterface"

Q_DECLARE_INTERFACE(ModuleInterface, ModuleInterface_iid)
