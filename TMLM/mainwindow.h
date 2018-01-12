#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tm.h>
#include <QTimer>

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
    void on_makeStepButton_clicked();

    void on_addTextToTapeButton_clicked();

    void on_autoMoveButton_clicked();

    void performStep();

private:
    Ui::MainWindow *ui;
    Tm* tm;
    std::string* tapeTextPtr;
    std::string head;
    std::string emptyHead;
    std::string tempText;
    QTimer *timer = new QTimer(this);
    bool isAutoEnabled = false;
};

#endif // MAINWINDOW_H
