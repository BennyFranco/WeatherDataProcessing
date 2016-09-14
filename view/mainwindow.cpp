//
// Created by Benny Franco Dennis on 14/03/16.
//

#include <qfiledialog.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CreateStationWindow.h"
#include "../config/Connection.h"
#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <QTextStream>
#include <algorithm>


using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::finalize;


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{

    std::vector<std::string> s;
    std::vector<std::string>::const_iterator j;

    Connection *connection = new Connection("mongodb://127.0.0.1/ClimaPIEAES?","ClimaPIEAES","Configurations","");

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{connection->getMongoURI()}};

    auto collection = conn[connection->getDatabase()][connection->getCollectionName()];

    auto cursor = collection.find({});

    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;

        bsoncxx::document::element name_ele{doc["name"]};
        if (name_ele) {
            std::string d = bsoncxx::to_json(name_ele.get_document());
            // this block will only execute if "store" was found in the document
            std::replace(d.begin(), d.end(), '"', ' ');
            d.erase( std::remove_if( d.begin(), d.end(), ::isspace ), d.end() );
            std::cout << d << std::endl;
            s.push_back(d);
        }
    }

    ui->setupUi(this);
    for(j=s.begin(); j!=s.end(); ++j){
        std::string temp = (*j);
        ui->listWidget->addItem(temp.data());
    }
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

void MainWindow::on_itemClicked() {
    const QString& s = ui->listWidget->currentItem()->text();
    std::cout << s.toStdString() << std::endl;

    Connection *connection = new Connection("mongodb://127.0.0.1/ClimaPIEAES?","ClimaPIEAES",s.toStdString(),"");

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{connection->getMongoURI()}};

    auto collection = conn[connection->getDatabase()]["Configurations"];

    auto cursor = collection.find({document{} << "name" << s.toStdString() << finalize});

    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;

        bsoncxx::document::element name_ele{doc["name"]};
        if (name_ele) {
            // this block will only execute if "store" was found in the document
            std::cout << bsoncxx::to_json(name_ele.get_document()) << std::endl;
            ui->lblName->setText(("Name: " + bsoncxx::to_json(name_ele.get_document())).data());
        }

        bsoncxx::document::element fileURI_ele{doc["fileURI"]};
        if (fileURI_ele) {
            // this block will only execute if "store" was found in the document
            std::cout << bsoncxx::to_json(fileURI_ele.get_document()) << std::endl;
            ui->lblFileURI->setText(("URI: " + bsoncxx::to_json(fileURI_ele.get_document())).data());
        }
    }



}