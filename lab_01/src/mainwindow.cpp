#include <QFileDialog>
#include <QStringList>

#include <cstdlib>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "errors.h"
#include "object.h"
#include "requests.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

MainWindow::~MainWindow(void)
{
    request_t request;
    request.option = QUIT;
    request_handle(request);

    delete ui;
}

error_t MainWindow::draw_actions(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    request_t request;
    request.option = DRAW;
    request.canvas = canvas;

    error_t error_code = request_handle(request);

    return error_code;
}

void MainWindow::on_move_button_clicked(void)
{
    transfer_t coeffs;
    coeffs.dx = ui->dx_box->value();
    coeffs.dy = ui->dy_box->value();
    coeffs.dz = ui->dz_box->value();

    request_t request;
    request.option = TRANSFER;
    request.transfer = coeffs;

    error_t error_code = request_handle(request);

    if (error_code)
        error_handle(error_code);
    else
    {
        error_code = draw_actions();

        if (error_code)
            error_handle(error_code);
    }
}

void MainWindow::on_scale_button_clicked(void)
{
    scale_t coeffs;
    coeffs.k_x = ui->kx_box->value();
    coeffs.k_y = ui->ky_box->value();
    coeffs.k_z = ui->kz_box->value();

    request_t request;
    request.option = SCALE;
    request.scale = coeffs;

    error_t error_code = request_handle(request);

    if (error_code)
        error_handle(error_code);
    else
    {
        error_code = draw_actions();

        if (error_code)
            error_handle(error_code);
    }
}

void MainWindow::on_turn_button_clicked(void)
{
    rotate_t coeffs;
    coeffs.phi_x = ui->phi_x_box->value();
    coeffs.phi_y = ui->phi_y_box->value();
    coeffs.phi_z = ui->phi_z_box->value();

    request_t request;
    request.option = ROTATE;
    request.rotate = coeffs;

    error_t error_code = request_handle(request);

    if (error_code)
        error_handle(error_code);
    {
        error_code = draw_actions();

        if (error_code)
            error_handle(error_code);
    }
}

void MainWindow::on_action_triggered()
{
    QStringList Files = QFileDialog::getOpenFileNames(
                        this, tr("Открыть файлы"),
                        "../", "*.csv;");

    const char *name = Files[0].toStdString().c_str();
    request_t request;

    request.option = LOAD;
    request.file_name = name;

    error_t error_code = request_handle(request);

    if (error_code)
        error_handle(error_code);
    else
    {
        error_code = draw_actions();

        if (error_code)
            error_handle(error_code);
    }
}
