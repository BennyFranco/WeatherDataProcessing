#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TextFileProcessor.h"

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
    string uiMongoURI = ui->txtMongoUri->toPlainText().toStdString();
    string uiDatabase = ui->txtDatabaseName->toPlainText().toStdString();
    string uiCollectionName = ui->txtCollectionName->toPlainText().toStdString();
    string uiFileName = ui->txtFileName->toPlainText().toStdString();

    TextFileProcessor *transform = new TextFileProcessor(uiMongoURI,uiDatabase,uiCollectionName,uiFileName);
    transform->transformTextFile();

    printf("info saved");
}
