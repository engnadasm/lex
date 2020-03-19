#ifndef DFADRIVER_H
#define DFADRIVER_H


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
