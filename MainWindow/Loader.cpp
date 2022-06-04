#include "Loader.h"

#include "MainWidget.h"

#include "PluginInterface.h"
#include "ModuleInterface.h"
#include "SubviewWidget.h"
#include "Subview.h"


#include <QDir>
#include <QCoreApplication>
#include <QPluginLoader>

#include <QDebug>

namespace
{
    const QString SUBVIEWS_DIR_ONE("subviews_one");
    const QString SUBVIEWS_DIR_TWO("subviews_two");

#ifdef Q_OS_LINUX
    const QString SHARED_LIBRARY_SUFFIX = QStringLiteral("*.so*");
#else
    const QString SHARED_LIBRARY_SUFFIX = QStringLiteral("*.dll");
#endif
}

Loader::Loader(QObject* parent)
    : QObject(parent)
    , m_mainView(new MainWidget)
{}

Loader::~Loader()
{
    foreach(const QString& key, m_subviews_one.keys())
        if (m_subviews_one[key]->parent() == nullptr)
            delete m_subviews_one[key];

    foreach(const QString& key, m_subviews_two.keys())
        if (m_subviews_two[key]->parent() == nullptr)
            delete m_subviews_two[key];
}

bool Loader::authDialogAccepted()
{
    // TODO: Check auth here
    return true;
}

void Loader::start()
{
    loadModules();
    createWindow();
}

void Loader::stop()
{
    destroyWindow();
    unloadModules();
}

void Loader::loadModules()
{
    QDir pluginsDir(QCoreApplication::applicationDirPath());

    //-------------------------------------------------------------------

    if (pluginsDir.cd(SUBVIEWS_DIR_ONE))
    {
        foreach (const QString& fileName, pluginsDir.entryList(QStringList() << SHARED_LIBRARY_SUFFIX, QDir::Files))
        {
            QString moduleName = QFileInfo(fileName).baseName();

            QSharedPointer<QPluginLoader> loader(new QPluginLoader(pluginsDir.absoluteFilePath(fileName)));
            PluginInterface* const interface = qobject_cast<PluginInterface*>(loader->instance());

            if (interface)
            {
                if (!m_subviews_one.contains(interface->id()))
                {
                    SubviewWidget* subview = interface->createSubview();

                    if (subview->initialize())
                    {
                        m_loaders[moduleName] = loader;

                        m_subviews_one[interface->id()] = subview;
                        m_subviews_one[interface->id()]->setupUserPermissions(QStringList());
                    }
                    else
                    {
                        qWarning() << QString("Reject to load \"%1\": failed to initialize").arg(subview->name());
                        loader->unload();
                    }
                }
                else
                {
                    qWarning() << QString("Reject to load \"%1\": module id already exists").arg(interface->id());
                    loader->unload();

                    m_subviews_one[interface->id()]->setupUserPermissions(QStringList());
                }
            }
            else
                qWarning() << QString("Unable to load \"%1\": object is not a ModuleInterface instance").arg(fileName).toUtf8().data();
        }

        pluginsDir.cdUp();
    }

    //-------------------------------------------------------------------

    if (pluginsDir.cd(SUBVIEWS_DIR_TWO))
    {
        foreach (const QString& fileName, pluginsDir.entryList(QStringList() << SHARED_LIBRARY_SUFFIX, QDir::Files))
        {
            QString moduleName = QFileInfo(fileName).baseName();

            QSharedPointer<QPluginLoader> loader(new QPluginLoader(pluginsDir.absoluteFilePath(fileName)));
            ModuleInterface* const interface = qobject_cast<ModuleInterface*>(loader->instance());

            if (interface)
            {
                if (!m_subviews_two.contains(interface->id()))
                {
                    Subview* subview = interface->widget();

                    if (subview && interface->activate())
                    {
                        m_loaders[moduleName] = loader;
                        m_subviews_two[interface->id()] = subview;
                    }
                    else
                    {
                        qWarning() << QString("Reject to load \"%1\": failed to initialize").arg(interface->name());
                        loader->unload();
                    }
                }
                else
                {
                    qWarning() << QString("Reject to load \"%1\": module id already exists").arg(QString(interface->id()));
                    loader->unload();
                }
            }
            else
                qWarning() << QString("Unable to load \"%1\": object is not a ModuleInterface instance").arg(fileName).toUtf8().data();
        }
    }
}

void Loader::unloadModules()
{
    foreach (const PluginLoaderPtr& loader, m_loaders.values())
        loader->unload();

    m_loaders.clear();
}

void Loader::createWindow()
{
    m_mainView.reset(new MainWidget(nullptr, m_subviews_one, m_subviews_two));

    connect(m_mainView.data(), &MainWidget::closeRequested, this, [this]
    {
        stop();

//------ Possible loop on auth ---
//        if (authDialogAccepted())
//            start();
//        else
//            qApp->exit();

    }, Qt::QueuedConnection);

    m_mainView->showMaximized();
}

void Loader::destroyWindow()
{
    m_mainView.reset();
    m_subviews_one.clear();
    m_subviews_two.clear();
}
