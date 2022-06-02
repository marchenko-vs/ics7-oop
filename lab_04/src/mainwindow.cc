#include <QWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(250, 500);
    this->layout_ = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->ui->centralwidget->setLayout(this->layout_.get());
    this->layout_->addWidget(this->elevator_.widget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

