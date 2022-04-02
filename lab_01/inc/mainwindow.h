#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>

#include "requests.h"
#include "errors.h"

#define WINDOW_WIDTH 995
#define WINDOW_HEIGHT 485

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

    error_t draw_actions(void);

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // _MAINWINDOW_H_
