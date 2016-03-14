//
// Created by Benny Franco Dennis on 14/03/16.
//

#include <qfiledialog.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CreateStationWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCrear_triggered()
{
    CreateStationWindow *w = new CreateStationWindow();
    w->show();
}