//
// Created by Benny Franco Dennis on 18/09/16.
//
#include <qfiledialog.h>
#include "adjustWindow.h"
#include "../config/Connection.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <iostream>
#include <QMessageBox>

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

void adjustWindow::on_testButton_Clicked() {
    Connection *connection = new Connection(ui->uriLineEdit->text().toStdString(),ui->collectionLineEdit->text().toStdString(),"Configurations","");

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{connection->getMongoURI()}};

    try {

        auto collection = conn[connection->getDatabase()][connection->getCollectionName()];

        auto cursor = collection.find({});

        for (auto &&doc : cursor) {
            bsoncxx::document::element name_ele{doc["name"]};
        }
    } catch(std::exception& e)
    {
        QMessageBox Msgbox;
        Msgbox.setText("Test Failed: No existe una instancia de MongoDB ejecutandose, revisa tu configuración");
        Msgbox.exec();
    }
}