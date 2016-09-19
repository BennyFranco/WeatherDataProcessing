/********************************************************************************
** Form generated from reading UI file 'CreateStationWindowF37760.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATESTATIONWINDOWF37760_H
#define CREATESTATIONWINDOWF37760_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateStationWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *txtCollectionName;
    QPushButton *btnSave;
    QPushButton *btnOpenFile;
    QTextEdit *txtFileName;

    void setupUi(QMainWindow *CreateStationWindow)
    {
        if (CreateStationWindow->objectName().isEmpty())
            CreateStationWindow->setObjectName(QStringLiteral("CreateStationWindow"));
        CreateStationWindow->resize(512, 140);
        centralWidget = new QWidget(CreateStationWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        txtCollectionName = new QPlainTextEdit(centralWidget);
        txtCollectionName->setObjectName(QStringLiteral("txtCollectionName"));
        txtCollectionName->setGeometry(QRect(10, 10, 381, 31));
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(140, 100, 113, 32));
        btnOpenFile = new QPushButton(centralWidget);
        btnOpenFile->setObjectName(QStringLiteral("btnOpenFile"));
        btnOpenFile->setGeometry(QRect(400, 50, 113, 32));
        txtFileName = new QTextEdit(centralWidget);
        txtFileName->setObjectName(QStringLiteral("txtFileName"));
        txtFileName->setGeometry(QRect(10, 50, 381, 31));
        CreateStationWindow->setCentralWidget(centralWidget);

        retranslateUi(CreateStationWindow);

        QMetaObject::connectSlotsByName(CreateStationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CreateStationWindow)
    {
        CreateStationWindow->setWindowTitle(QApplication::translate("CreateStationWindow", "Create Station", 0));
        txtCollectionName->setPlaceholderText(QApplication::translate("CreateStationWindow", "Collection Name", 0));
        btnSave->setText(QApplication::translate("CreateStationWindow", "Save Info", 0));
        btnOpenFile->setText(QApplication::translate("CreateStationWindow", "Open File", 0));
        txtFileName->setPlaceholderText(QApplication::translate("CreateStationWindow", "File name with path", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateStationWindow: public Ui_CreateStationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATESTATIONWINDOWF37760_H
