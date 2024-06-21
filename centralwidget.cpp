#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent):
    QWidget{parent},
    webTabs{new QTabWidget},
    address{new QLineEdit},
    JS{new QTextEdit},
    buttons{new QPushButton, new QPushButton, new QPushButton, new QPushButton},
    upper{new QHBoxLayout},
    lower{new QHBoxLayout},
    lowerRight{new QVBoxLayout},
    lay{new QVBoxLayout}
{
    buttons[0]->setMinimumHeight(40);
    buttons[0]->setText("Backward");
    buttons[1]->setMinimumHeight(40);
    buttons[1]->setText("Forward");
    buttons[2]->setMinimumHeight(40);
    buttons[2]->setText("New Tab");
    buttons[3]->setMinimumHeight(40);
    buttons[3]->setText("Run");
    address->setMinimumHeight(40);
    webTabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    upper->addWidget(buttons[0]);
    upper->addWidget(buttons[1]);
    upper->addWidget(address);
    upper->addWidget(buttons[2]);

    lowerRight->addWidget(JS);
    lowerRight->addWidget(buttons[3]);

    lower->addWidget(webTabs);
    lower->addLayout(lowerRight);

    lay->addLayout(upper);
    lay->addLayout(lower);

    this->setLayout(lay);

    auto web = new QWebEngineView(webTabs);
    web->load(QUrl("https://www.google.com"));

    webTabs->setTabsClosable(true);

    webTabs->addTab(web, "lol");
    webTabs->setTabPosition(QTabWidget::West);
}
