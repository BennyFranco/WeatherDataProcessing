/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *txtMongoUri;
    QPlainTextEdit *txtDatabaseName;
    QPlainTextEdit *txtCollectionName;
    QPlainTextEdit *txtFileName;
    QPushButton *btnSave;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 222);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        txtMongoUri = new QPlainTextEdit(centralWidget);
        txtMongoUri->setObjectName(QStringLiteral("txtMongoUri"));
        txtMongoUri->setGeometry(QRect(10, 10, 381, 31));
        txtDatabaseName = new QPlainTextEdit(centralWidget);
        txtDatabaseName->setObjectName(QStringLiteral("txtDatabaseName"));
        txtDatabaseName->setGeometry(QRect(10, 50, 381, 31));
        txtCollectionName = new QPlainTextEdit(centralWidget);
        txtCollectionName->setObjectName(QStringLiteral("txtCollectionName"));
        txtCollectionName->setGeometry(QRect(10, 90, 381, 31));
        txtFileName = new QPlainTextEdit(centralWidget);
        txtFileName->setObjectName(QStringLiteral("txtFileName"));
        txtFileName->setGeometry(QRect(10, 130, 381, 31));
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(140, 180, 113, 32));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        txtMongoUri->setPlaceholderText(QApplication::translate("MainWindow", "MongoURI", 0));
        txtDatabaseName->setPlaceholderText(QApplication::translate("MainWindow", "Database Name", 0));
        txtCollectionName->setPlaceholderText(QApplication::translate("MainWindow", "Collection Name", 0));
        txtFileName->setPlaceholderText(QApplication::translate("MainWindow", "File name with path", 0));
        btnSave->setText(QApplication::translate("MainWindow", "Save Info", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
