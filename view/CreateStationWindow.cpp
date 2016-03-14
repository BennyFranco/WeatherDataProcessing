#include <qfiledialog.h>
#include "ui_CreateStationWindow.h"
#include "CreateStationWindow.h"
#include "../config/Connection.h"
#include "../controller/StationController.h"
#include "../config/Configuration.h"

CreateStationWindow::CreateStationWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::CreateStationWindow)
{
    ui->setupUi(this);
}

CreateStationWindow::~CreateStationWindow()
{
    delete ui;
}

void CreateStationWindow::on_btnSave_clicked()
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

void CreateStationWindow::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                    tr("Text Files (*.txt)"));
    ui->txtFileName->setPlainText(fileName);
}