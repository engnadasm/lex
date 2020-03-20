#ifndef DFA_H
#define DFA_H
#include <set>
#include <string>

using namespace std;


class DFA
{
    public:
        /* DFA construction functions */
        DFA(); //states from 0 to n-1, initial state usually 0
        void setParameters(set<char> inputs, int numStates);
        void setNumStates(int num);
        void addTransition(int s1, int s2, char input); //transition from s1 to s2 under input character
        void accept(int state); //set state state accept state

        set<int> getAcceptStates();
        set<char> getInputSymbols();
        int getInitState();
        int getNumStates();
        int getNextState(int state, char input); // return -1 if dead state

        int getCurrentState(); // return current state or -1 if dead
        int move(char input); //return new state
        bool isAccept(int state);
        string getToken(); //get token reached by a sequence of move calls
        void reset(); //reset to initial state deleting the token reached.

    protected:

    private:
        set<char> inputs;
        set<int> acceptStates;
        int numStates;
        int initState;
};

#endif // DFA_H
