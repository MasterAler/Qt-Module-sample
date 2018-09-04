#include "Subview.h"

#include <QApplication>
#include <QThread>

Subview::Subview(QWidget* parent)
    : QWidget(parent)
    , m_hasActiveRequest(false)
    , m_stopRequested(false)
{}

Subview::~Subview()
{}

QVariantMap Subview::modulePermissions() const
{
    return QVariantMap();
}

void Subview::setupUserPermissions(const QStringList&)
{}

bool Subview::initializeImpl()
{
    return true;
}

bool Subview::initialize()
{
    return initializeImpl();
}

void Subview::stop()
{
    m_stopRequested = true;

    while (m_hasActiveRequest)
    {
        QThread::msleep(1);
        QApplication::processEvents();
    }
}

bool Subview::activate()
{
    return true;
}

Subview* Subview::widget() const
{
//    return static_cast<QWidget*>(const_cast<Subview*>(this)); // widget itself
    return const_cast<Subview*>(this);
}

QByteArray Subview::id() const
{
    return QByteArray();
}

QString Subview::name() const
{
    return QString(typeid(*this).name()).replace("class ", ""); // class name
}
