#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(290, 600);
    this->setWindowTitle("Elevator (lab_04)");

    layout_ = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);

    this->ui->centralwidget->setLayout(layout_.get());

    layout_->addWidget(elevator_.widget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

