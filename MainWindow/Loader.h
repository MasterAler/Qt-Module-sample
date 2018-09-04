#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QHash>

class QPluginLoader;
class MainWidget;
class SubviewWidget;
class Subview;

typedef QSharedPointer<QPluginLoader> PluginLoaderPtr;

class Loader : public QObject
{
    Q_OBJECT

public:
    explicit Loader(QObject* parent = nullptr);
    virtual ~Loader();

public:
    bool authDialogAccepted();

public slots:
    void start();
    void stop();

    void loadModules();
    void unloadModules();

    void createWindow();
    void destroyWindow();

private:
    QHash<QString, PluginLoaderPtr> m_loaders;
    QHash<QString, SubviewWidget*> m_subviews_one;
    QHash<QString, Subview*> m_subviews_two;
    QScopedPointer<MainWidget> m_mainView;
};

