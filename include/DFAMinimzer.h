#ifndef DFAMINIMZER_H
#define DFAMINIMZER_H


class DFAMinimzer
{
    public:
        DFAMinimzer(DFA dfa);
        void minimize();
        DFA getMinimizedDFA();
    protected:

    private:
};

#endif // DFAMINIMZER_H
