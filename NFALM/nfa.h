#ifndef NFA_H
#define NFA_H

#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include "QDebug"
class Nfa
{
public:
    explicit Nfa(int startState);
    ~Nfa();

    std::string returnActualStateMessage();
    std::string returnTransitionsMessage();

    void setStateMessage(const std::string &value);
    void setTransitionsMessage(const std::string &value);
    void setTransitionsMessage(char &input);
    void resetAutomata();
    void addState(int state, bool isFinal);
    void addTransition(int src, char input, std::set<int> destination);
    void makeSteps(std::string symbols, std::vector<int> elements = std::vector<int>());
    bool isAcceptState(int state);
    int getCurrentState() const;

//protected:
    int i = 0;
    int currentState;
//    std::set<int> presumableStates;
    int startState;
    std::set<int> alphabet;
    std::set<int> states;
    std::set<int> acceptStates;
    std::map<std::pair<int,char>,std::set<int>> transitionFunction;
    std::vector<std::vector<int>> treeGraph;
    std::vector<std::vector<int>> treeGraphElement;
    std::vector<int> element;

private:
    bool isLast = false;
    std::string stateMessage;
    std::string transitionsMessage;
    std::string transitions ="0";
    //std::string tempSymbols;
};


#endif // NFA_H
