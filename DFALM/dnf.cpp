#include "dnf.h"


template <typename T>
DNF<T>::DNF(int startState)
{
    this->startState = startState;
    this->currentState = startState;
    addState(startState,false);
}

template <typename T>
DNF<T>::~DNF()
{}





template <typename T>
void DNF<T>::addState(int state, bool isFinal)
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

template <typename T>
void DNF<T>::addTransition(int src, T input, int destination)
{
    transitionFunction.insert(std::pair<std::pair<int,T>,int>(std::pair<int,T>(src,input),destination));
}

template <typename T>
void DNF<T>::makeStep(T symbol)
{
    std::pair<int, T> tempTransition= std::make_pair(currentState,symbol);
    if(transitionFunction.count(tempTransition)==1)
    {

        currentState = transitionFunction[tempTransition];
        if(currentState != startState)
        {
            if(isAcceptState(currentState))
            {
                setStateMessage("This is the final state: " + std::to_string(currentState) + "\n");
                setTransitionsMessage((symbol));
            }
            else
            {
                setStateMessage("You are on: " + std::to_string(currentState) + " state. Do next step.\n");
                setTransitionsMessage((symbol));
            }
        }
        else
        {
            setStateMessage("Automaton Reset.You have to start from beginning\n");
            setTransitionsMessage(transitions);
            transitions="";

        }
    }
    else
    {
        setStateMessage("Forbidden input symbol\n");
    }
}
template <typename T>
bool DNF<T>::isAcceptState(int state)
{
    return acceptStates.count(state);
}

template <typename T>
int DNF<T>::getCurrentState() const
{
    return currentState;
}

template <typename T>
void DNF<T>::setStateMessage(const std::string &value)
{
    stateMessage = value;
}

template <typename T>
void DNF<T>::setTransitionsMessage(const std::string &value)
{
    transitionsMessage += value;
}

template <typename T>
void DNF<T>::setTransitionsMessage(T &input)
{
    transitionsMessage += input;
}

template<typename T>
void DNF<T>::resetAutomata()
{
    transitionsMessage.clear();
    stateMessage.clear();
    currentState = startState;

}

template <typename T>
std::string DNF<T>::returnActualStateMessage()
{
    return stateMessage;
}

template <typename T>
std::string DNF<T>::returnTransitionsMessage()
{
    return transitionsMessage;
}
