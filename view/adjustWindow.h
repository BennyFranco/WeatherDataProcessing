//
// Created by Benny Franco Dennis on 18/09/16.
//

#ifndef WEATHER_BACKEND_APP_ADJUSTWINDOW_H
#define WEATHER_BACKEND_APP_ADJUSTWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "ui_adjustWindow.h"

namespace Ui {
    class adjustWindow;
}

class adjustWindow: public QDialog {
Q_OBJECT

public:
    explicit adjustWindow(QWidget *parent = 0);
    ~adjustWindow();

public slots:

private:
    Ui::adjustWindow *ui;
};


#endif //WEATHER_BACKEND_APP_ADJUSTWINDOW_H
