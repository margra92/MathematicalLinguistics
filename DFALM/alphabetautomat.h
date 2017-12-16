#ifndef ALPHABETAUTOMAT_H
#define ALPHABETAUTOMAT_H
#include "dnf.h"

class AlphabetAutomat : public DNF<char>
{
public:
    AlphabetAutomat(int startState);
    void initAutomata();
};

#endif // ALPHABETAUTOMAT_H
