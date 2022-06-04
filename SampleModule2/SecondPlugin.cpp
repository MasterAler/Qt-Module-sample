#include "SecondPlugin.h"

#include "SecondModule.h"

SecondPlugin::SecondPlugin(QObject *parent)
    : QObject(parent)
{}

QString SecondPlugin::id() const
{
    return "olooolkll";
}

SubviewWidget* SecondPlugin::createSubview() const
{
    return new SecondModule;
}

QVariantMap SecondPlugin::permissions() const
{
    return QVariantMap();
}

