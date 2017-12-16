#include "alphabetautomat.h"

AlphabetAutomat::AlphabetAutomat(int startState):DNF<char>(startState)
{
    initAutomata();
}

void AlphabetAutomat::initAutomata()
{
    this->addState(1,false);
    this->addState(2,false);
    this->addState(3,true);
    this->addState(4,false);


    this->addTransition(0,'a',1);
    this->addTransition(0,'b',2);

    this->addTransition(1,'a',2);
    this->addTransition(1,'b',3);

    this->addTransition(2,'a',2);
    this->addTransition(2,'b',2);

    this->addTransition(3,'a',4);
    this->addTransition(3,'b',4);

    this->addTransition(4,'a',3);
    this->addTransition(4,'b',3);
}
