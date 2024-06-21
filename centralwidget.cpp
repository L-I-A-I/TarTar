#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent):
    QWidget{parent},
    webTabs{new QTabWidget(this)},
    address{new QLineEdit(this)},
    JS{new QTextEdit(this)},
    buttons{new QPushButton(this), new QPushButton(this), new QPushButton(this), new QPushButton(this)},
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

    {
        auto web = new QWebEngineView(webTabs);
        auto page = new QWebEnginePage(web);
        web->setPage(page);
        web->load(QUrl("https://google.com"));
        webTabs->addTab(web, "glglgl");
    }

    webTabs->setTabsClosable(true);
    webTabs->setTabPosition(QTabWidget::West);

    //connections
    connect(buttons[0], &QPushButton::clicked, [this](){
        ((QWebEngineView*)webTabs->currentWidget())->back();
    });
    connect(buttons[1], &QPushButton::clicked, [this](){
        ((QWebEngineView*)webTabs->currentWidget())->forward();
    });
    connect(buttons[2], &QPushButton::clicked, [this](){
        auto web = new QWebEngineView(webTabs);
        auto page = new QWebEnginePage(web);
        web->setPage(page);
        web->load(QUrl("https://google.com"));
        webTabs->addTab(web, "loading");
        int ind = webTabs->count() - 1;

        connect(web, &QWebEngineView::loadStarted, [this, ind](){
            webTabs->setTabText(ind, "loading");
        });
        connect(web, &QWebEngineView::loadFinished, [this, ind, web](){
            webTabs->setTabText(ind, web->title());
        });
    });
    connect(buttons[3], &QPushButton::clicked, [this](){
        ((QWebEngineView*)webTabs->currentWidget())->page()->runJavaScript(JS->toPlainText());
    });
    connect(address, &QLineEdit::returnPressed, [this](){
        ((QWebEngineView*)webTabs->currentWidget())->load(address->text());
    });
    connect(webTabs, &QTabWidget::tabCloseRequested, [this](int ind){
        delete ((QWebEngineView*)webTabs->widget(ind));
    });
    connect(webTabs, &QTabWidget::currentChanged, [this](){
        address->setText(((QWebEngineView*)webTabs->currentWidget())->url().toString());
    });

}
