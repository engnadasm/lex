#ifndef NDCONVERTER_H
#define NDCONVERTER_H
#include "DFA.h"
#include "NFA.h"

using namespace std;

class NDConverter
{
    public:
        NDConverter(NFA nfa);
        void convert();
        DFA getDFA();

    protected:

    private:
};

#endif // NDCONVERTER_H
