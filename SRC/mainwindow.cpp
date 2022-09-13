#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString Str = {
        "Item 1\r\n"
        "    Item 1.1\r\n"
        "    Item 1.2\r\n"
        "    Item 1.3\r\n"
        "        Item 1.3.1\r\n"
        "    Item 1.4\r\n"
        "Item 2\r\n"
        "    Item 2.1\r\n"
        "    Item 2.2\r\n"
    };

    Model = new TreeModel();
    Model->AddItems(Str);

    CT = new ComboTree(this);
    CT->SetModel(Model);
    CT->expandAll();
}

MainWindow::~MainWindow()
{
    delete CT;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    CT->MoveResize(QPoint(10,10),QSize(size().width()-20,30));
}
