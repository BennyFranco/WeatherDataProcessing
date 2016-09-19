//
// Created by Benny Franco Dennis on 18/09/16.
//
#include <qfiledialog.h>
#include "adjustWindow.h"
#include "../config/Connection.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include "../include/json.hpp"

using json = nlohmann::json;

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

void adjustWindow::accept() {
    json configJSONFile;
    configJSONFile["mongoURI"] = ui->uriLineEdit->text().toStdString();
    configJSONFile["database"] = ui->collectionLineEdit->text().toStdString();

    std::ofstream configFile;
    configFile.open ("config.json");
    configFile << configJSONFile.dump();
    configFile.close();

    QDialog::accept();
}

void adjustWindow::on_testButton_Clicked() {
    QMessageBox Msgbox;
    Connection *connection = new Connection(ui->uriLineEdit->text().toStdString(),ui->collectionLineEdit->text().toStdString(),"Configurations","");

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{connection->getMongoURI()}};

    try {

        auto collection = conn[connection->getDatabase()][connection->getCollectionName()];

        auto cursor = collection.find({});

        for (auto &&doc : cursor) {
            bsoncxx::document::element name_ele{doc["name"]};
        }

        Msgbox.setText("Test Passed");
        Msgbox.exec();

    } catch(std::exception& e) {
        Msgbox.setText("Test Failed: No existe una instancia de MongoDB ejecutandose, revisa tu configuración");
        Msgbox.exec();
    }
}