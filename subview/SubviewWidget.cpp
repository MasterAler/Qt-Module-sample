#include "SubviewWidget.h"

#include <QApplication>
#include <QThread>

SubviewWidget::SubviewWidget(QWidget* parent)
    : QWidget(parent)
    , m_hasActiveRequest(false)
    , m_stopRequested(false)
{}

SubviewWidget::~SubviewWidget()
{}

QString SubviewWidget::name() const
{
    return QString(typeid(*this).name()).replace("class ", ""); // class name
}

void SubviewWidget::setupUserPermissions(const QStringList&)
{}

bool SubviewWidget::initialize()
{
    return initializeImpl();
}

void SubviewWidget::activate()
{}

void SubviewWidget::stop()
{
    m_stopRequested = true;

    while (m_hasActiveRequest)
    {
        QThread::msleep(1);
        QApplication::processEvents();
    }
}

bool SubviewWidget::initializeImpl()
{
    return true;
}


