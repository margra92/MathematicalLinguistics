#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "QDebug"
#include "alphabetautomat.h"

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
    void on_symbolaButton_clicked();

    void on_symbolbButton_clicked();

    void on_finishButton_clicked();

private:
    Ui::MainWindow *ui;
    AlphabetAutomat* alphabetAutomat;
};

#endif // MAINWINDOW_H
