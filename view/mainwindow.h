//
// Created by Benny Franco Dennis on 14/03/16.
//

#ifndef WEATHER_BACKEND_APP_MAINWINDOW_H
#define WEATHER_BACKEND_APP_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{

Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_actionCrear_triggered();
    void on_itemClicked();
    void on_adjustButton_Clicked();

private:
    Ui::MainWindow *ui;
};


#endif //WEATHER_BACKEND_APP_MAINWINDOW_H
