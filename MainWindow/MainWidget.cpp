#include "MainWidget.h"
#include "ui_MainWidget.h"

#include "SubviewWidget.h"
#include "Subview.h"

#include <QDebug>
#include <QCloseEvent>
#include <QPushButton>

MainWidget::MainWidget(QWidget* parent, const SubviewOneDict& subviewOneDict, const SubviewTwoDict& subviewTwoDict)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , m_exitButton(new QPushButton(tr("Выход")))
    , m_subviews_one(subviewOneDict)
    , m_subviews_two(subviewTwoDict)
{
    ui->setupUi(this);

    connect(m_exitButton, &QPushButton::clicked, this, &QWidget::close);
    ui->mainTabWidget->setCornerWidget(m_exitButton);

    connect(ui->mainTabWidget, &QTabWidget::currentChanged, [this](int tabIndex)
    {
        SubviewWidget* subview = static_cast<SubviewWidget*>(ui->mainTabWidget->widget(tabIndex));

        if (subview)
            subview->activate();
        else
            qDebug() << QString("Wrong tab index: %1").arg(tabIndex);
    });

    if (!m_subviews_one.empty() && !m_subviews_two.empty())
        ui->mainTabWidget->clear();

    setupOneSubviews(m_subviews_one);
    setupTwoSubviews(m_subviews_two);
}

MainWidget::~MainWidget()
{ }

void MainWidget::setupTwoSubviews(const SubviewTwoDict &subviewDict)
{
    m_subviews_two = subviewDict;

    for (SubviewTwoDict::ConstIterator i = m_subviews_two.constBegin(), e = m_subviews_two.constEnd(); i != e; ++i)
        ui->mainTabWidget->addTab(i.value(), i.value()->name());
}

void MainWidget::setupOneSubviews(const SubviewOneDict &subviewDict)
{
    m_subviews_one = subviewDict;

    for (SubviewOneDict::ConstIterator i = m_subviews_one.constBegin(), e = m_subviews_one.constEnd(); i != e; ++i)
        ui->mainTabWidget->addTab(i.value(), i.value()->name());
}

void MainWidget::closeEvent(QCloseEvent *event)
{
    foreach (SubviewWidget* subview, m_subviews_one.values())
        subview->stop();

    foreach (Subview* subview, m_subviews_two.values())
        subview->stop();

    emit closeRequested();

    event->ignore();
}
