#include "tm.h"

Tm::Tm(int startState)
{
    this->startState = startState;
    this->currentState = startState;
    addState(startState,false);
}

void Tm::makeSteps(std::string* tapeText)
{
//    if(isAuto)
//    {
//        while (!isFinal && !isForbidden)// "!is finall" || "!is forbidden")
//        {
//            makeStep(tapeText);
//         /*
//          * wez aktualny stan
//          * wez wskazywany symbol
//          * sprawdz, czy jest funkcja przejscia
//          * jesli jest:
//          *     nadpisz aktualny stan z funkcji przejscia
//          *     nadpisz wskazywany symbol symbolem z funkcji przejscia
//          *     zwieksz indeks glowicy o 1 jesli ruch jest w prawo(RIGHT)
//          *     zmniejsz indeks glowicy o 1 jesli ruch jest w lewo (LEFT)
//          *     jezeli aktualny stan jest finalny ("!is finall = !true"), przerwij petle
//          *     jezeli nie ma finalnego stanu ("!is final = !false), kontynuuj petle
//          * jesli nie ma
//          * "!is forbidden" jest na !true. Przerywa sie petla, wywala blad
//          *
//          */
//        }
//    }
//    else
//    {
        makeStep(tapeText);
//    }

}

void Tm::makeStep(std::string *tapeText)
{
    if(headIndex <= tapeText->length()-1)
    {
      const char currentSymbol = tapeText->at(headIndex);
      std::pair<int, char> tempTransition= std::make_pair(currentState,currentSymbol);
      isForbidden = transitionFunction.count(tempTransition) != 1;
      if(!isForbidden)
      {
        StateEdge* statePtr = &transitionFunction[tempTransition];
        currentState = statePtr->nextState;
        isFinal = isFinaltState(currentState);
        tapeText->at(headIndex) = statePtr->write;
        if(statePtr->direction == RIGHT)
        {
            std::cout << 'R';
           headIndex++;
        }
        else if(statePtr->direction == LEFT)
        {
            std::cout << 'L';
            headIndex--;
        }
      }
      else
      {
        std::cout << "Forbidden input";
      }
    }

}

void Tm::addState(int state, bool isFinal)
{
    if(isFinal)
    {
        finalStates.insert(state);
    }
    else
    {
        states.insert(state);
    }
}

void Tm::addTransition(int srcState, char currentSymbol, StateEdge edge)
{
    transitionFunction.insert(std::pair<std::pair<int,char>,StateEdge>(std::pair<int,char>(srcState, currentSymbol),edge));
}

bool Tm::isFinaltState(int state)
{
    return finalStates.count(state);
}

void Tm::reset()
{
    this->currentState = this->startState;
    headIndex = 0;
}

