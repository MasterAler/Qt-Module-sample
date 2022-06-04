#include "FirstPlugin.h"

#include "FirstModule.h"

FirstPlugin::FirstPlugin(QObject *parent)
    : QObject(parent)
{}

QString FirstPlugin::id() const
{
    return "firstfirst";
}

SubviewWidget* FirstPlugin::createSubview() const
{
    return new FirstModule;
}

QVariantMap FirstPlugin::permissions() const
{
    return QVariantMap();
}

