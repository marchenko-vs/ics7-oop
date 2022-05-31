/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QPushButton *scale_button;
    QDoubleSpinBox *kx_box;
    QDoubleSpinBox *ky_box;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *kz_box;
    QGroupBox *groupBox_2;
    QPushButton *move_button;
    QLabel *label_2;
    QDoubleSpinBox *dy_box;
    QDoubleSpinBox *dz_box;
    QLabel *label_3;
    QDoubleSpinBox *dx_box;
    QLabel *label;
    QGroupBox *groupBox_3;
    QPushButton *turn_button;
    QDoubleSpinBox *phi_x_box;
    QDoubleSpinBox *phi_y_box;
    QDoubleSpinBox *phi_z_box;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1280, 576);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1280, 576));
        MainWindow->setMaximumSize(QSize(1280, 576));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 1000, 490));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1030, 19, 241, 151));
        scale_button = new QPushButton(groupBox);
        scale_button->setObjectName(QString::fromUtf8("scale_button"));
        scale_button->setGeometry(QRect(10, 110, 221, 31));
        kx_box = new QDoubleSpinBox(groupBox);
        kx_box->setObjectName(QString::fromUtf8("kx_box"));
        kx_box->setGeometry(QRect(80, 20, 131, 20));
        kx_box->setMinimum(0.000000000000000);
        kx_box->setMaximum(10000000000000000.000000000000000);
        kx_box->setValue(1.000000000000000);
        ky_box = new QDoubleSpinBox(groupBox);
        ky_box->setObjectName(QString::fromUtf8("ky_box"));
        ky_box->setGeometry(QRect(80, 50, 131, 20));
        ky_box->setMinimum(0.000000000000000);
        ky_box->setMaximum(10000000000000000000000.000000000000000);
        ky_box->setValue(1.000000000000000);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 20, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 50, 20, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(33, 80, 20, 20));
        kz_box = new QDoubleSpinBox(groupBox);
        kz_box->setObjectName(QString::fromUtf8("kz_box"));
        kz_box->setGeometry(QRect(80, 80, 131, 20));
        kz_box->setMinimum(0.000000000000000);
        kz_box->setMaximum(10000000000000000.000000000000000);
        kz_box->setValue(1.000000000000000);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1030, 190, 241, 151));
        move_button = new QPushButton(groupBox_2);
        move_button->setObjectName(QString::fromUtf8("move_button"));
        move_button->setGeometry(QRect(10, 110, 221, 31));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(30, 50, 20, 20));
        dy_box = new QDoubleSpinBox(groupBox_2);
        dy_box->setObjectName(QString::fromUtf8("dy_box"));
        dy_box->setGeometry(QRect(80, 50, 131, 20));
        dy_box->setMinimum(-10000000000000000000000.000000000000000);
        dy_box->setMaximum(10000000000000000000000.000000000000000);
        dz_box = new QDoubleSpinBox(groupBox_2);
        dz_box->setObjectName(QString::fromUtf8("dz_box"));
        dz_box->setGeometry(QRect(80, 80, 131, 20));
        dz_box->setMinimum(-99999999999999991611392.000000000000000);
        dz_box->setMaximum(10000000000000000.000000000000000);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 80, 20, 20));
        dx_box = new QDoubleSpinBox(groupBox_2);
        dx_box->setObjectName(QString::fromUtf8("dx_box"));
        dx_box->setGeometry(QRect(80, 20, 131, 20));
        dx_box->setMinimum(-10000000000000000.000000000000000);
        dx_box->setMaximum(10000000000000000.000000000000000);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(33, 20, 20, 20));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1030, 360, 241, 151));
        turn_button = new QPushButton(groupBox_3);
        turn_button->setObjectName(QString::fromUtf8("turn_button"));
        turn_button->setGeometry(QRect(10, 110, 221, 31));
        phi_x_box = new QDoubleSpinBox(groupBox_3);
        phi_x_box->setObjectName(QString::fromUtf8("phi_x_box"));
        phi_x_box->setGeometry(QRect(80, 20, 131, 20));
        phi_x_box->setMinimum(-10000000000000000.000000000000000);
        phi_x_box->setMaximum(10000000000000000.000000000000000);
        phi_y_box = new QDoubleSpinBox(groupBox_3);
        phi_y_box->setObjectName(QString::fromUtf8("phi_y_box"));
        phi_y_box->setGeometry(QRect(80, 50, 131, 20));
        phi_y_box->setMinimum(-10000000000000000000000.000000000000000);
        phi_y_box->setMaximum(10000000000000000000000.000000000000000);
        phi_z_box = new QDoubleSpinBox(groupBox_3);
        phi_z_box->setObjectName(QString::fromUtf8("phi_z_box"));
        phi_z_box->setGeometry(QRect(80, 80, 131, 20));
        phi_z_box->setMinimum(-99999999999999991611392.000000000000000);
        phi_z_box->setMaximum(10000000000000000.000000000000000);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 20, 31, 20));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(33, 50, 31, 20));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(33, 80, 31, 20));
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 \342\204\2261", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        scale_button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " kX", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " kY", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "kZ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        move_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " dY", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", " dZ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "dX", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        turn_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", " phi X", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "phi Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "phi Z", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
