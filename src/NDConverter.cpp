#include "../include/NDConverter.h"
#include <iostream>
#include <Vector>
#include <queue>
#include<bits/stdc++.h>
NDConverter::NDConverter(NFA* nfa)
{
    //ctor
    this->nfa = nfa;

}

void NDConverter::convert()
{
    acceptStates = nfa->getAcceptStates();
    inputSymbols = nfa->getSymbols();
    int TNum = 0;
    set<int> T = nfa->epsloneClosure(nfa->getStartState());
    vector< set<int> > Dstates;
    set<char> :: iterator it = inputSymbols.begin();
    queue< set<int> > unmarkedStates;
    Dstates.push_back(T);
    unmarkedStates.push(T);
    dfa = new DFA(inputSymbols, TNum);

    if(checkAccept(T)){
        dfa->accept(TNum);
     }
    // subset construction algorithm
    while(!unmarkedStates.empty()){
            // mark state T by removing it from unmarked states
            T = unmarkedStates.front();
            unmarkedStates.pop();
            // find its number in the dfa states
            vector< set<int> >::iterator itr = find(Dstates.begin(), Dstates.end(), T);
            TNum = distance(Dstates.begin(), itr);
        // Iterate over the input symbols
        while (it != inputSymbols.end())
        {
            set<int> U = nfa->epsloneClosure(nfa->inputMove(T,*it));
            vector< set<int> >::iterator i = Dstates.begin();
            while (i != Dstates.end())
            {
                if(U == *i){
                //found -> add transition from T to U under char *it
                int UNum = distance(Dstates.begin(), i);
                dfa->addTransition(TNum, UNum, *it);
                break;
                }
                i++;
            }
            if(i == Dstates.end()){
                //not found -> add U as a new state to Dstates & add transition from T to U under char *it
                Dstates.push_back(U);
                unmarkedStates.push(U);
                int UNum = Dstates.size()- 1;
                dfa->addTransition(TNum, UNum, *it);
                if(checkAccept(U)){
                 dfa->accept(UNum);
                }
            }

         it++;
        }
    }
}
DFA* NDConverter::getDFA()
{
    return dfa;
}
bool NDConverter::checkAccept(set<int> U){
    set<int>::iterator  itr1 = acceptStates.begin();
        while (itr1 != acceptStates.end())
        {
            set<int>::iterator itr2 = U.find(*itr1);
            if (itr2 != U.end()){
                return true;
            }
            itr1++;
        }
        return false;
}
