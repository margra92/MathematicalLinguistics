#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alphabetAutomat = new AlphabetAutomat(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_symbolaButton_clicked()
{
    alphabetAutomat->makeStep('a');
    ui->actualStateNumber->display(alphabetAutomat->getCurrentState());
    ui->consolePlainText->appendPlainText(QString::fromStdString(alphabetAutomat->returnActualStateMessage()));
}

void MainWindow::on_symbolbButton_clicked()
{
    alphabetAutomat->makeStep('b');
    ui->actualStateNumber->display(alphabetAutomat->getCurrentState());
    ui->consolePlainText->appendPlainText(QString::fromStdString(alphabetAutomat->returnActualStateMessage()));
    qDebug() << QString::fromStdString(alphabetAutomat->returnTransitionsMessage());
}

void MainWindow::on_finishButton_clicked()
{
    QMessageBox::information(0, QString("Current State")
                             ,QString("Final word is: " +QString::fromStdString(alphabetAutomat->returnTransitionsMessage() +"\n")
                                                        +"on state " + QString::number(alphabetAutomat->getCurrentState())
                                                        +" which is " + (alphabetAutomat->isAcceptState(alphabetAutomat->getCurrentState()) ? "Final state" : "temp state"))
                             ,QMessageBox::Ok);
    alphabetAutomat->resetAutomata();
    ui->actualStateNumber->display(alphabetAutomat->getCurrentState());
    ui->consolePlainText->clear();

}
