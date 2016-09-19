/********************************************************************************
** Form generated from reading UI file 'adjustWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTWINDOW_H
#define UI_ADJUSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adjustWindow
{
public:
    QDialogButtonBox *acceptButtons;
    QGroupBox *adjustGroup;
    QLineEdit *uriLineEdit;
    QLabel *dataBaseLabel;
    QLabel *collectionLabel;
    QLineEdit *collectionLineEdit;
    QPushButton *testButton;

    void setupUi(QDialog *adjustWindow)
    {
        if (adjustWindow->objectName().isEmpty())
            adjustWindow->setObjectName(QStringLiteral("adjustWindow"));
        adjustWindow->resize(400, 168);
        acceptButtons = new QDialogButtonBox(adjustWindow);
        acceptButtons->setObjectName(QStringLiteral("acceptButtons"));
        acceptButtons->setGeometry(QRect(300, 20, 81, 141));
        acceptButtons->setOrientation(Qt::Vertical);
        acceptButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        adjustGroup = new QGroupBox(adjustWindow);
        adjustGroup->setObjectName(QStringLiteral("adjustGroup"));
        adjustGroup->setGeometry(QRect(10, 0, 281, 161));
        uriLineEdit = new QLineEdit(adjustGroup);
        uriLineEdit->setObjectName(QStringLiteral("uriLineEdit"));
        uriLineEdit->setGeometry(QRect(10, 50, 261, 31));
        dataBaseLabel = new QLabel(adjustGroup);
        dataBaseLabel->setObjectName(QStringLiteral("dataBaseLabel"));
        dataBaseLabel->setGeometry(QRect(10, 30, 261, 16));
        collectionLabel = new QLabel(adjustGroup);
        collectionLabel->setObjectName(QStringLiteral("collectionLabel"));
        collectionLabel->setGeometry(QRect(10, 90, 261, 16));
        collectionLineEdit = new QLineEdit(adjustGroup);
        collectionLineEdit->setObjectName(QStringLiteral("collectionLineEdit"));
        collectionLineEdit->setGeometry(QRect(10, 110, 261, 31));
        testButton = new QPushButton(adjustWindow);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setGeometry(QRect(300, 110, 81, 32));

        retranslateUi(adjustWindow);
        QObject::connect(acceptButtons, SIGNAL(accepted()), adjustWindow, SLOT(accept()));
        QObject::connect(acceptButtons, SIGNAL(rejected()), adjustWindow, SLOT(reject()));
        QObject::connect(testButton,SIGNAL(clicked()), adjustWindow, SLOT(on_testButton_Clicked()));

        QMetaObject::connectSlotsByName(adjustWindow);
    } // setupUi

    void retranslateUi(QDialog *adjustWindow)
    {
        adjustWindow->setWindowTitle(QApplication::translate("adjustWindow", "Dialog", 0));
        adjustGroup->setTitle(QApplication::translate("adjustWindow", "Configuraci\303\263n de la base de datos", 0));
        uriLineEdit->setText(QApplication::translate("adjustWindow", "mongodb://127.0.0.1/", 0));
        uriLineEdit->setPlaceholderText(QApplication::translate("adjustWindow", "mongodb://127.0.0.1/", 0));
        dataBaseLabel->setText(QApplication::translate("adjustWindow", "DataBase URI (Mongo URI)", 0));
        collectionLabel->setText(QApplication::translate("adjustWindow", "Colecci\303\263n", 0));
        collectionLineEdit->setText(QApplication::translate("adjustWindow", "ClimaPIEAES", 0));
        collectionLineEdit->setPlaceholderText(QApplication::translate("adjustWindow", "Collection Name", 0));
        testButton->setText(QApplication::translate("adjustWindow", "Probar", 0));
    } // retranslateUi

};

namespace Ui {
    class adjustWindow: public Ui_adjustWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTWINDOW_H
