#include <qfiledialog.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller/StationController.h"
#include "config/Configuration.h"

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

void MainWindow::on_btnSave_clicked()
{
    std::string uiMongoURI = ui->txtMongoUri->toPlainText().toStdString();
    std::string uiDatabase = ui->txtDatabaseName->toPlainText().toStdString();
    std::string uiCollectionName = ui->txtCollectionName->toPlainText().toStdString();
    std::string uiFileName = ui->txtFileName->toPlainText().toStdString();

    Connection *connection = new Connection(uiMongoURI,uiDatabase,uiCollectionName,uiFileName);

    StationController *stationController = new StationController();
    stationController->create(*connection);

    Configuration *configuration = new Configuration();
    configuration->create(*connection);

    printf("info saved\n");
}

void MainWindow::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                    tr("Text Files (*.txt)"));
    ui->txtFileName->setPlainText(fileName);
}