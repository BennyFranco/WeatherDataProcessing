/********************************************************************************
** Form generated from reading UI file 'mainwindowK34179.ui'
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
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
    QGroupBox *optionsGroup;
    QToolButton *addStationButton;
    QToolButton *editStationButton;
    QToolButton *deleteStationButton;
    QMenuBar *menubar;
    QMenu *menuEstaciones;
    QStatusBar *statusbar;


    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(709, 504);
        actionCrear = new QAction(MainWindow);
        actionCrear->setObjectName(QStringLiteral("actionCrear"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(100, 0, 256, 461));
        groupDetails = new QGroupBox(centralwidget);
        groupDetails->setObjectName(QStringLiteral("groupDetails"));
        groupDetails->setGeometry(QRect(370, 0, 331, 461));
        lblName = new QLabel(groupDetails);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(10, 30, 311, 20));
        lblFileURI = new QLabel(groupDetails);
        lblFileURI->setObjectName(QStringLiteral("lblFileURI"));
        lblFileURI->setGeometry(QRect(10, 60, 311, 71));
        lblFileURI->setMaximumSize(QSize(311, 71));
        lblFileURI->setTextFormat(Qt::AutoText);
        lblFileURI->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblFileURI->setWordWrap(true);
        lblFileURI->setMargin(1);
        lblFileURI->setIndent(0);
        lblFileURI->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        optionsGroup = new QGroupBox(centralwidget);
        optionsGroup->setObjectName(QStringLiteral("optionsGroup"));
        optionsGroup->setGeometry(QRect(10, 0, 81, 461));
        addStationButton = new QToolButton(optionsGroup);
        addStationButton->setObjectName(QStringLiteral("addStationButton"));
        addStationButton->setGeometry(QRect(10, 30, 61, 61));
        addStationButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        editStationButton = new QToolButton(optionsGroup);
        editStationButton->setObjectName(QStringLiteral("editStationButton"));
        editStationButton->setGeometry(QRect(10, 100, 61, 61));
        editStationButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        deleteStationButton = new QToolButton(optionsGroup);
        deleteStationButton->setObjectName(QStringLiteral("deleteStationButton"));
        deleteStationButton->setGeometry(QRect(10, 170, 61, 61));
        deleteStationButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 709, 22));
        menuEstaciones = new QMenu(menubar);
        menuEstaciones->setObjectName(QStringLiteral("menuEstaciones"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEstaciones->menuAction());
        menuEstaciones->addAction(actionCrear);

        retranslateUi(MainWindow);
        QObject::connect(actionCrear, SIGNAL(triggered()), MainWindow, SLOT(on_actionCrear_triggered()));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), MainWindow, SLOT(on_itemClicked()));
        QObject::connect(addStationButton,SIGNAL(clicked()), MainWindow, SLOT(on_actionCrear_triggered()));

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
        optionsGroup->setTitle(QApplication::translate("MainWindow", "Opciones", 0));
        addStationButton->setText(QApplication::translate("MainWindow", "A\303\261adir", 0));
        editStationButton->setText(QApplication::translate("MainWindow", "Editar", 0));
        deleteStationButton->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        menuEstaciones->setTitle(QApplication::translate("MainWindow", "Estaciones", 0));
    } // retranslateUi

public slots:
    void on_actionCrear_triggered();
    void on_itemClicked();
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWK34179_H