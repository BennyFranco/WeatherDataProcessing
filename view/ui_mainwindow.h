/********************************************************************************
** Form generated from reading UI file 'mainwindowd37760.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWD37760_H
#define MAINWINDOWD37760_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCrear;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QGroupBox *groupDetails;
    QLabel *lblName;
    QLabel *lblFileURI;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuEstaciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(599, 504);
        actionCrear = new QAction(MainWindow);
        actionCrear->setObjectName(QStringLiteral("actionCrear"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 256, 461));
        groupDetails = new QGroupBox(centralwidget);
        groupDetails->setObjectName(QStringLiteral("groupDetails"));
        groupDetails->setGeometry(QRect(260, 0, 331, 431));
        lblName = new QLabel(groupDetails);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(10, 30, 311, 20));
        lblFileURI = new QLabel(groupDetails);
        lblFileURI->setObjectName(QStringLiteral("lblFileURI"));
        lblFileURI->setGeometry(QRect(10, 60, 311, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 430, 113, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 430, 113, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 599, 22));
        menuEstaciones = new QMenu(menubar);
        menuEstaciones->setObjectName(QStringLiteral("menuEstaciones"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEstaciones->menuAction());
        menuEstaciones->addAction(actionCrear);

        retranslateUi(MainWindow);
        QObject::connect(actionCrear, SIGNAL(triggered()), actionCrear, SLOT(on_actionCrear_triggered()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCrear->setText(QApplication::translate("MainWindow", "Crear", 0));
        actionCrear->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        groupDetails->setTitle(QApplication::translate("MainWindow", "Detalles", 0));
        lblName->setText(QApplication::translate("MainWindow", "Name: ", 0));
        lblFileURI->setText(QApplication::translate("MainWindow", "URI:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuEstaciones->setTitle(QApplication::translate("MainWindow", "Estaciones", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWD37760_H
