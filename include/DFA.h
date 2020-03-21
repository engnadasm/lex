#ifndef DFA_H
#define DFA_H
#include <set>
#include <string>
#include <unordered_map>

using namespace std;


class DFA
{
    public:
        /* DFA construction functions */
        DFA(set<char> inputs, int initState); //states from 0 to n-1, initial state usually 0
        void setNumStates(int num);
        void addTransition(int s1, int s2, char input); //transition from s1 to s2 under input character
        void accept(int state, string className); //set state state accept state

        unordered_map<int, string> getAcceptStates();
        set<char> getInputSymbols();
        int getInitState();
        int getNumStates();
        int getNextState(int state, char input); // return -1 if dead state

        int getCurrentState(); // return current state or -1 if dead
        int move(char input); //return new state
        bool isAccept(int state);
        string getToken(); //get token reached by a sequence of move calls
        string getLexeme(); //get lexeme reached by a sequence of move calls
        void reset(); //reset to initial state deleting the token reached.
        bool isDead();

    protected:

    private:
        set<char> inputs;
        unordered_map<int, string> acceptStates;
        int initState;
        int currentState;
        string lastValidToken;
        string lexeme;
        string inputSequence;
        //(Key:state, value: (key: input, value:next state))
        unordered_map<int , unordered_map<char, int>> transitionTable;
        void initTransitionTableEntry(int state);
};

#endif // DFA_H
