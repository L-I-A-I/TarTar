#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QTabWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QWebEngineView>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);

private:
    QTabWidget* webTabs;
    QLineEdit* address;
    QTextEdit* JS;
    QPushButton* buttons[4];
    QHBoxLayout* upper;
    QHBoxLayout* lower;
    QVBoxLayout* lowerRight;
    QVBoxLayout* lay;

signals:
};

#endif // CENTRALWIDGET_H
