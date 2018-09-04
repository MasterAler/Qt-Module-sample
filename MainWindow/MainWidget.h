#pragma once

#include <QWidget>
#include <QScopedPointer>

namespace Ui {
class MainWidget;
}

class SubviewWidget;
class Subview;
class QPushButton;

typedef QHash<QString, SubviewWidget*> SubviewOneDict;
typedef QHash<QString, Subview*> SubviewTwoDict;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget* parent = nullptr
            , const SubviewOneDict& subviewOneDict = SubviewOneDict()
            , const SubviewTwoDict& subviewTwoDict = SubviewTwoDict()
            );
    ~MainWidget();

public slots:
    void setupOneSubviews(const SubviewOneDict& subviewDict);
    void setupTwoSubviews(const SubviewTwoDict &subviewDict);

public:
    void closeEvent(QCloseEvent* event) override;

signals:
    void closeRequested();


private:
    QScopedPointer<Ui::MainWidget> ui;
    QPushButton* m_exitButton;
    SubviewOneDict m_subviews_one;
    SubviewTwoDict m_subviews_two;
};

