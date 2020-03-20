#ifndef DFADRIVER_H
#define DFADRIVER_H
#include <string>
#include <vector>
#include "DFA.h"

using namespace std;

class DFADriver
{
    public:
        DFADriver(DFA* dfa);
        void setInputFile(string path);
        void start();
        vector<string> getTokens();
        //functions to return symbol table


    protected:

    private:
        DFA* dfa;
        vector<string> tokens;
        string inputBuf;
};

#endif // DFADRIVER_H
