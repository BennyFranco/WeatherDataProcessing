#include <qfiledialog.h>
#include "ui_CreateStationWindow.h"
#include "CreateStationWindow.h"
#include "../config/Connection.h"
#include "../controller/StationController.h"
#include "../config/Configuration.h"
#include "../include/json.hpp"
#include <fstream>

using JSON = nlohmann::json;

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
    std::string uiCollectionName = ui->txtCollectionName->toPlainText().toStdString();
    std::string uiFileName = ui->txtFileName->toPlainText().toStdString();

    // Read Config File
    std::string line;
    std::ifstream configFile ("config.json");

    JSON jsonConfigFile;

    if (configFile.is_open())
    {
        while ( getline (configFile,line) )
        {
            jsonConfigFile = JSON::parse(line);
        }
        configFile.close();
    }

    else std::cout << "Unable to open file";

    std::string mongoURI = jsonConfigFile["mongoURI"];
    std::string dataBase = jsonConfigFile["database"];

    Connection *connection = new Connection(mongoURI,dataBase,uiCollectionName,uiFileName);

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