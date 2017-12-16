#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nfa = new Nfa(0);
    nfa->addState(1,false);
    nfa->addState(2,true);
    nfa->addState(3,true);
    nfa->addState(4,true);
    nfa->addState(5,false);
    nfa->addState(6,true);
    nfa->addState(7,true);
    nfa->addState(8,true);
    nfa->addState(9,false);
    nfa->addState(10,true);
    nfa->addState(11,true);
    nfa->addState(12,true);

    nfa->addTransition(0,'-',{1});
    nfa->addTransition(0,'0',{3});
    nfa->addTransition(0,'1',{2});

    nfa->addTransition(0,'2',{3});
    nfa->addTransition(0,'3',{3});
    nfa->addTransition(0,'4',{3});
    nfa->addTransition(0,'5',{3});
    nfa->addTransition(0,'6',{3});
    nfa->addTransition(0,'7',{3});
    nfa->addTransition(0,'8',{3});
    nfa->addTransition(0,'9',{3});

    nfa->addTransition(1,'0',{3});
    nfa->addTransition(1,'1',{2});

    nfa->addTransition(1,'2',{3});
    nfa->addTransition(1,'3',{3});
    nfa->addTransition(1,'4',{3});
    nfa->addTransition(1,'5',{3});
    nfa->addTransition(1,'6',{3});
    nfa->addTransition(1,'7',{3});
    nfa->addTransition(1,'8',{3});
    nfa->addTransition(1,'9',{3});

    nfa->addTransition(2,'0',{4});
    nfa->addTransition(2,',',{5});

    nfa->addTransition(3,',',{5});

    nfa->addTransition(4,',',{9});


    nfa->addTransition(5,'0',{6});
    nfa->addTransition(5,'1',{6});

    nfa->addTransition(5,'2',{6});
    nfa->addTransition(5,'3',{6});
    nfa->addTransition(5,'4',{6});
    nfa->addTransition(5,'5',{6});
    nfa->addTransition(5,'6',{6});
    nfa->addTransition(5,'7',{6});
    nfa->addTransition(5,'8',{6});
    nfa->addTransition(5,'9',{6});


    nfa->addTransition(6,'0',{7});
    nfa->addTransition(6,'1',{7});

    nfa->addTransition(6,'2',{7});
    nfa->addTransition(6,'3',{7});
    nfa->addTransition(6,'4',{7});
    nfa->addTransition(6,'5',{7});
    nfa->addTransition(6,'6',{7});
    nfa->addTransition(6,'7',{7});
    nfa->addTransition(6,'8',{7});
    nfa->addTransition(6,'9',{7});



    nfa->addTransition(7,'0',{8});
    nfa->addTransition(7,'1',{8});

    nfa->addTransition(7,'2',{8});
    nfa->addTransition(7,'3',{8});
    nfa->addTransition(7,'4',{8});
    nfa->addTransition(7,'5',{8});
    nfa->addTransition(7,'6',{8});
    nfa->addTransition(7,'7',{8});
    nfa->addTransition(7,'8',{8});
    nfa->addTransition(7,'9',{8});

    nfa->addTransition(9,'0',{10});
    nfa->addTransition(10,'0',{11});
    nfa->addTransition(11,'0',{12});





//    nfa->addTransition(0,'0',{0,1});
//    nfa->addTransition(1,'0',{3});
//    nfa->addTransition(3,'0',{5});
//    nfa->addTransition(5,'0',{5});
//    nfa->addTransition(5,'1',{5});

//    nfa->addTransition(0,'1',{0,2});
//    nfa->addTransition(2,'1',{4});
//    nfa->addTransition(4,'1',{6});
//    nfa->addTransition(6,'0',{6});
//    nfa->addTransition(6,'1',{6});
}

MainWindow::~MainWindow()
{
    delete nfa;
    delete ui;
}



void MainWindow::on_startButton_clicked()
{
    int i=1;
    for(auto inputWord: *inputWords)
    {
        ui->inputWordsPlainText->appendPlainText(QString::number(i) + "#: "+QString::fromStdString(inputWord));
        nfa->makeSteps(inputWord);
        for(auto vec: nfa->treeGraph)
        {
            QString qstring ="";
            int j=0;
            for(int state: vec)
            {
                qstring.insert(j,QString::number(state));
                j++;
            }
            ui->consolePlainText->appendPlainText(QString::number(i)+"#: "+ qstring);
            qstring.clear();
        }
        nfa->resetAutomata();
        i++;
    }

}

void MainWindow::on_browseFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open File","/home","All files (*.*)");

    if( !filename.isNull() )
    {
      qDebug() << "selected file path : " << filename.toUtf8();
    }

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    std::vector<std::string> tempInputWords;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        line.remove(QRegExp("[\\n\\t\\r ]"));
        if(line.isEmpty())
        {

        }

        QStringList lineList = line.split(QRegExp("[#]"),QString::SkipEmptyParts);


        for(auto tempLine : lineList)
        {
            std::string utf8_line = tempLine.toUtf8().constData();
            tempInputWords.push_back(utf8_line);
        }
    }

    if(inputWords != nullptr )
    {
        delete inputWords;

    }
    inputWords = new std::vector<std::string>(tempInputWords.size());
    inputWords->swap(tempInputWords);
}

void MainWindow::on_resetButton_clicked()
{

}
