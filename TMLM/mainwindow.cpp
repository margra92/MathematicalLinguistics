#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("--------\n--------");
    tm = new Tm(0);

    tm->addState(1,true);

    tm->addTransition(0,'0',StateEdge(0,'1',RIGHT));
    tm->addTransition(0,'1',StateEdge(0,'0',RIGHT));
    tm->addTransition(0,'-',StateEdge(1,'-',NONE));

    tm->addTransition(1,'0',StateEdge(1,'-',NONE));
    tm->addTransition(1,'1',StateEdge(1,'-',NONE));
    tm->addTransition(1,'-',StateEdge(1,'-',NONE));

    connect(timer, SIGNAL(timeout()), this, SLOT(performStep()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_makeStepButton_clicked()
{
    performStep();
}

void MainWindow::on_addTextToTapeButton_clicked()
{
    tm->reset();

    tempText = ui->tapeTextLineEdit->text().toStdString();
    tapeTextPtr = &tempText;
    qDebug() << "1: "<<QString::number(tempText.length());
    ui->textEdit->moveCursor( QTextCursor::Start, QTextCursor::MoveAnchor);
    ui->textEdit->moveCursor( QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    ui->textEdit->textCursor().insertText(QString::fromStdString(*tapeTextPtr));

    ui->textEdit->moveCursor( QTextCursor::End, QTextCursor::MoveAnchor);
    ui->textEdit->moveCursor( QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
    ui->textEdit->moveCursor( QTextCursor::End, QTextCursor::KeepAnchor);

    head = "^";
    ui->textEdit->textCursor().insertText(QString::fromStdString(head));
    qDebug() << "2: " <<QString::fromStdString(*tapeTextPtr);
}

void MainWindow::on_autoMoveButton_clicked()
{

    if(isAutoEnabled)
    {
        isAutoEnabled = false;
        ui->autoMoveButton->setText("Start auto move");
        timer->stop();
    }
    else if(!isAutoEnabled)
    {
        timer->start(1000);
        isAutoEnabled = true;
        ui->autoMoveButton->setText("Stop auto move");
    }

}

void MainWindow::performStep()
{
    tm->makeStep(tapeTextPtr);

    ui->textEdit->moveCursor( QTextCursor::Start, QTextCursor::MoveAnchor);
    ui->textEdit->moveCursor( QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    ui->textEdit->textCursor().insertText(QString::fromStdString(*tapeTextPtr));

    ui->textEdit->moveCursor( QTextCursor::End, QTextCursor::MoveAnchor);
    ui->textEdit->moveCursor( QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
    ui->textEdit->moveCursor( QTextCursor::End, QTextCursor::KeepAnchor);
    head.clear();
    for(unsigned int i=0; i < tm->headIndex;i++)
    {
        head += "  ";
    }
    head += "^";
    ui->textEdit->textCursor().insertText(QString::fromStdString(head));
    qDebug() << "3 :"  <<QString::fromStdString(*tapeTextPtr);
}
