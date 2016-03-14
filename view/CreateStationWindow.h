#ifndef CREATESTATIONWINDOW_H
#define CREATESTATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
    class CreateStationWindow;
}

class CreateStationWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit CreateStationWindow(QWidget *parent = 0);
    ~CreateStationWindow();

private slots:
    void on_btnSave_clicked();
    void on_btnOpenFile_clicked();

private:
    Ui::CreateStationWindow *ui;
};

#endif // CREATESTATIONWINDOW_H