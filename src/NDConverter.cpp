#include "../include/NDConverter.h"
#include <iostream>
#include <Vector>
#include <queue>
NDConverter::NDConverter(NFA* nfa)
{
    //ctor
    this->nfa = nfa;
}

/*void NDConverter::convert()
{
    set<char> inputSymbols = nfa.getSymbols();
    int stateCounter = 0;
    int TNum = 0;
    set<int> T = nfa.epsloneClosure(nfa.getStartState());
    vector< set<int> > Dstates;
    set<char> :: iterator it = inputSymbols.begin();
    queue< set<int> > unmarkedStates;
    Dstates.push_back(T);
    unmarkedStates.push(T);
    dfa = DFA(inputSymbols, 0, stateCounter);
    // subset construction algorithm
    while(!unmarkedStates.empty()){
            // mark state T by removing it from unmarked states
            T = unmarkedStates.front();
            unmarkedStates.pop();
            // find its number in the dfa states
            vector< set<int> >::iterator itr = find(Dstates.begin(), Dstates.end(), T);
            Tnum = distance(Dstates.begin(), itr);
        // Iterate over the input symbols
        while (it != inputSymbols.end())
        {
        set<int> U = nfa.epsloneClosure(nfa.inputMove(T,*it));
        vector< set<int> >::iterator i = Dstates.begin();
        while (i != Dstates.end())
        {
            if(U == *i){
                //found -> add transition from T to U under *it
                dfa.addTransition(T,)
                break;
            }
            i++;
        }
        if(i == Dstates.end()){//not found -> add U as a new state to Dstates
             Dstates.push_back(U);
             unmarkedStates.push(U);
             stateCounter++;
            }
            it++;
        }
    }
//states.find(U) != states.end()
//vector<int>::iterator itr = std::find(v.begin(), v.end(), key)---> distance(v.begin(), itr)
}*/
DFA* NDConverter::getDFA()
{
    return this->dfa;
}
