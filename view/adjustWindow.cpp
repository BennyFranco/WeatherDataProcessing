//
// Created by Benny Franco Dennis on 18/09/16.
//
#include <qfiledialog.h>
#include "adjustWindow.h"

adjustWindow::adjustWindow(QWidget *parent):
        QDialog(parent),
        ui(new Ui::adjustWindow)
{
    ui->setupUi(this);
}

adjustWindow::~adjustWindow()
{
    delete ui;
}