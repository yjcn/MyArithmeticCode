#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "myarithmeticcode.h"
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_code_clicked();

    void on_decode_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    MyArithmeticCode *name;
    MyArithmeticCode *num;
};

#endif // MAINWINDOW_H
