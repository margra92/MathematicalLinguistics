#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <nfa.h>
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    Nfa* nfa = new Nfa(0);
//    nfa->addState(1,false);
//    nfa->addState(2,false);
//    nfa->addState(3,false);
//    nfa->addState(4,false);
//    nfa->addState(5,true);
//    nfa->addState(6,true);

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

//    std::string input = "00001";
//    std::vector<int> elements;
//    nfa->makeSteps(input,elements);
//    int i = 10;
//    for(std::vector<int> v: nfa->treeGraph)
//    {
//        qDebug() << v;
//    }
}





