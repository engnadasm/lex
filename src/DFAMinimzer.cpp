#include "../include/DFAMinimzer.h"
#include "../include/DFA.h"
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

DFAMinimzer::DFAMinimzer(DFA* dfa)
{
    this->dfa = dfa;
}
void DFAMinimzer::minimize(){
    set<char> inputs = dfa->getInputSymbols();
    int initState = dfa->getInitState();
    int numStates = dfa->getNumStates();
    unordered_map<int, string> states = dfa->getAcceptStates();
    unordered_map<int, string> acceptStates;
    unordered_map<int, string> nonAcceptStates;
    for (int i =0 ; i< states.size();i++)
    {
        if (!dfa->isAccept(i))
        {
            acceptStates.insert(pair<int,string>(i, states.at(i)));
            stateSet.insert(pair<char,int>(i, 0));
        }else
        {
            nonAcceptStates.insert(pair<int,string>(i, states.at(i)));
           stateSet.insert(pair<char,int>(i, 1));
        }
    }

    vector<unordered_map<int, string>> partitions;
    partitions.push_back(acceptStates);
    partitions.push_back(nonAcceptStates);

    dfa->reset(); //reset to initial state deleting the token reached.*/
    int nextState;
    int currentState = dfa->getCurrentState(); // return current state or -1 if dead

    this->flag = true;

    while(flag)
    {
        this->flag = false;
       partitions = DFAMinimzer::doPartition(partitions);
    }

}

 vector<unordered_map<int, string>> DFAMinimzer::doPartition( vector<unordered_map<int, string>> partitions)
{
        for(int i = 0 ; i < partitions.size() ; i++)
        {
            for(int j = 0 ; j < partitions[0].size() ; j++)
            {
                unordered_map<int, string> currentPartition;
                currentPartition.insert(pair<int,string>(j,partitions[0].at(j)));
                //int
                for(int k = j+1 ; k < partitions[0].size() ; k++)
                {
                    bool check = true;
                    set<char> inputs = dfa->getInputSymbols();
                    for(char charInput : inputs){
                            //firstState is j & secondState is k
                            if ((dfa->getNextState(j,charInput))!=(dfa->getNextState(k,charInput))){
                                check =false;
                                break;
                           }
                    }
                    if (check)
                    {
                        currentPartition.insert(pair<int,string>(k,partitions[0].at(k)));
                        partitions[0].erase(k);
                        k--;
                    }
                    else{
                        this->flag = true;
                    }
                }
                for (int m =0; m < currentPartition.size(); m++)
                {
                    stateSet[m] = this->counter;
                }
                partitions.push_back(currentPartition);
                partitions[0].erase(j);
                j--;
                this->counter++;
            }
        }
    return partitions;
}

DFA* DFAMinimzer::getMinimizedDFA(){
    return this->dfa;
}
