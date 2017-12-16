#ifndef DNF_H
#define DNF_H

#include <map>
#include <set>
#include <iostream>
#include <string>

template <typename T>
class DNF
{
public:
    explicit DNF(int startState);
    ~DNF();

//    virtual void initAutomata() = 0;
    std::string returnActualStateMessage();
    std::string returnTransitionsMessage();

    void setStateMessage(const std::string &value);
    void setTransitionsMessage(const std::string &value);
    void setTransitionsMessage(T &input);
    void resetAutomata();
    void addState(int state, bool isFinal);
    void addTransition(int src, T input, int destination);
    void makeStep(T symbol);
    bool isAcceptState(int state);
    int getCurrentState() const;

protected:
    int currentState;
    int startState;
    std::set<int> alphabet;
    std::set<int> states;
    std::set<int> acceptStates;
    std::map<std::pair<int,T>,int> transitionFunction;

private:
    std::string stateMessage;
    std::string transitionsMessage;
    std::string transitions ="0";
};

template class DNF<int>;
template class DNF<char>;
template class DNF<double>;

#endif // DNF_H
