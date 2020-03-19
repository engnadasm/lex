#ifndef DFADRIVER_H
#define DFADRIVER_H
#include <string>
#include <set>
#include "DFA.h"

using namespace std;

class DFADriver
{
    public:
        DFADriver(DFA dfa);
        void setInputFile(string path);
        void start();
        set<string> getTokens();
        //functions to return symbol table


    protected:

    private:
};

#endif // DFADRIVER_H
