#pragma once

#include "ModuleInterface.h"

#include <QVariantMap>
#include <QWidget>

class Subview : public QWidget, public ModuleInterface
{
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)

public:
    explicit Subview(QWidget* parent = nullptr);
    virtual ~Subview();

public:
    QByteArray id() const override;
    QString name() const override;
    Subview* widget() const override;

public slots:
    bool initialize();

    bool activate() override;
    void stop() override;

public:
    virtual QVariantMap modulePermissions() const;
    virtual void setupUserPermissions(const QStringList&);

protected:
    virtual bool initializeImpl();

protected:
    bool m_hasActiveRequest;
    bool m_stopRequested;
};
