#include "nfa.h"


Nfa::Nfa(int startState)
{
    this->startState = startState;
    this->currentState = startState;
    addState(startState,false);
}


Nfa::~Nfa()
{}


void Nfa::addState(int state, bool isFinal)
{
    if(isFinal)
    {
        acceptStates.insert(state);
    }
    else
    {
        states.insert(state);
    }
}


void Nfa::addTransition(int src, char input, std::set<int> destination)
{
    transitionFunction.insert(std::pair<std::pair<int,char>,std::set<int>>(std::pair<int,char>(src,input),destination));
}


void Nfa::makeSteps(std::string symbols, std::vector<int> elements)
{
    int tempCurrentState = currentState;
    std::pair<int, char> tempTransition= std::make_pair(tempCurrentState,symbols[0]);
    qDebug() << "tempTransition " << tempTransition;

    qDebug() << "String1 " << QString::fromStdString(symbols);
    if(transitionFunction.count(tempTransition)==1)
    {
//        qDebug() << "1";
        std::set<int> presumableStates= transitionFunction[tempTransition];
        for(int state: presumableStates)
        {
//            qDebug() << "2";
            for(int i: presumableStates)
            {
                qDebug() << "presumableStates" << i;
            }

            currentState = state;
//            qDebug() << "2.1";

            qDebug() << "CurrenState" << currentState;
            elements.push_back(currentState);
//            treeGraphElement[i].push_back(currentState);
//             qDebug() << "3";
            if(symbols.size()>1)
            {
//                qDebug() << "4";
                    std::string tempSymbols = symbols;
                qDebug() << "String2 " << QString::fromStdString(tempSymbols);
                makeSteps(tempSymbols.erase(0,1), elements);
            }
            else
            {
                isLast = true;
                        qDebug() << "^^^^^";
            }
        }
//        qDebug() << "5";
//        treeGraph.push_back(treeGraphElement[i]);
//        treeGraph.push_back(elements);
        i++;
    }
    else
    {
        qDebug() << "6";
        setStateMessage("Forbidden input symbol\n");
        elements.clear();
    }
    if(isLast && elements.size() != 0)
    {
        treeGraph.push_back(elements);
        qDebug() << "Elements: " <<elements;
        qDebug() << "clear";
        isLast = false;
    }
    elements.clear();
}

bool Nfa::isAcceptState(int state)
{
    return acceptStates.count(state);
}


int Nfa::getCurrentState() const
{
    return currentState;
}


void Nfa::setStateMessage(const std::string &value)
{
    stateMessage = value;
}


void Nfa::setTransitionsMessage(const std::string &value)
{
    transitionsMessage += value;
}


void Nfa::setTransitionsMessage(char &input)
{
    transitionsMessage += input;
}

void Nfa::resetAutomata()
{
    transitionsMessage.clear();
    stateMessage.clear();
    treeGraph.clear();
    currentState = startState;
}


std::string Nfa::returnActualStateMessage()
{
    return stateMessage;
}


std::string Nfa::returnTransitionsMessage()
{
    return transitionsMessage;
}
