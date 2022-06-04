#pragma once

#include <QWidget>

class SubviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubviewWidget(QWidget* parent = nullptr);
    virtual ~SubviewWidget();

public:
    virtual QString name() const;
    virtual void setupUserPermissions(const QStringList&);

public slots:
    bool initialize();

    virtual void activate();
    virtual void stop();

protected:
    virtual bool initializeImpl();

protected:
    bool m_hasActiveRequest;
    bool m_stopRequested;
};
