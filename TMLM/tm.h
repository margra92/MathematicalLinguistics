#ifndef TM_H
#define TM_H

#include <map>
#include <set>
#include <iostream>
#include <string>
#include "stateedge.h"
#include "QDebug"
#include <time.h>

class Tm
{
public:
    Tm(int startState);

protected:
    std::map<std::pair<int,char>,StateEdge> transitionFunction;
    std::set<int> states;
    std::set<int> finalStates;
    int startState;

public:
    unsigned int headIndex = 0;
    bool isFinal = false;
    bool isForbidden = false;
    int currentState;
    void makeSteps(std::string* tapeText);
    void makeStep(std::string* tapeText);
    void addState(int state, bool isFinal);
    void addTransition(int srcState, char currentSymbol, StateEdge edge);
    bool isFinaltState(int state);
    void reset();
};

#endif // TM_H
