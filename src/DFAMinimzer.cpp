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
    this->numStates = dfa->getNumStates();
    cout << this->numStates << endl;
}
void DFAMinimzer::minimize()
{
    this->inputs = dfa->getInputSymbols();
    this->initState = dfa->getInitState();
    this->numStates = dfa->getNumStates();
    this->acceptStates = dfa->getAcceptStates();
    unordered_map<int, string> nonAcceptStates;
    cout << this->numStates<< endl;
    for (int i =0 ; i< this->numStates; i++)
    {
        if (!this->dfa->isAccept(i))
        {
            cout <<  "nonAccept : " << i << endl;
            nonAcceptStates.insert(pair<int,string>(i, ""));
            groupStates.insert(pair<int,int>(i, 0));
        }
        else
        {
            cout <<  "Accept : " << i << endl;
            groupStates.insert(pair<int,int>(i, 1));
            //this->counter++;
        }
    }

    this->partitions[0] = nonAcceptStates;
    //partitions[1] = acceptStates;

    this->flag = true;

    while(flag)
    {
        this->flag = false;
        for(int i = 0 ; i < this->numStates; i++)
        {
            this->partitions = doPartition();
        }
    }
    oneStateOfEachGroup();

}

unordered_map<int, unordered_map<int, string>> DFAMinimzer::doPartition()
{

    //for(int j = 0 ; j < partitions[i].size() ; j++)
    int j = 0;
    for (auto& firstState: this->partitions[0])
    {
        unordered_map<int, string> currentPartition;
        //std::cout << p.first << ": " << p.second << std::endl;
        currentPartition.insert(pair<int,string>(firstState.first,firstState.second));
        j++;
        //for(int k = j+1 ; k < partitions[i].size() ; k++)
        int k = 0;
        for(unordered_map<int, string>::iterator secondState = this->partitions[0].begin(); secondState != partitions[0].end(); ++secondState){
            if(k < j + 1 ){
                continue;
            } else {
                bool check = true;
                for(char charInput : this->inputs)
                {
                    //firstState is j & secondState is k
                    int nextFirstState = groupStates[this->dfa->getNextState(firstState.first,charInput)];
                    int nextSecondState = groupStates[this->dfa->getNextState(secondState->first,charInput)];
                    if ((nextFirstState != nextSecondState) && (
                        (nextSecondState != -1 ) || (nextFirstState != -1)))
                    {
                        check =false;
                        break;
                    }
                }
                if (check)
                {
                    currentPartition.insert(pair<int,string>(secondState->first,secondState->second));
                    this->partitions[0].erase(secondState->first);
                    k--;
                }
                else
                {
                    this->flag = true;
                }
                k++;
            }
        }
        for (auto& state: currentPartition)
        //for (int m =0; m < currentPartition.size(); m++)
        {
            groupStates[state.first] = this->counter;
        }
        this->partitions[this->counter] = currentPartition;
        //this->partitions.insert(this->counter,currentPartition);
        this->partitions[0].erase(firstState.first);
        j--;
        this->counter++;
    }
    return this->partitions;
}

DFA* DFAMinimzer::getMinimizedDFA()
{
    return this->dfa;
}

void DFAMinimzer::oneStateOfEachGroup(){
    unordered_map<int, string> mainStates;
    unordered_map<int, string> currentPartition;

    int currentState = 0;//initState
    int nextState ;
    for(int i = 0 ; i < this->numStates; i++)
    {
        currentState = i;
        for(char charInput : this->inputs)
        {
            nextState = this->dfa->getNextState(currentState, charInput); // return -1 if dead state
            if(nextState != -1){
                this->dfa->addTransition(this->groupStates[currentState], this->groupStates[nextState], charInput);
            }
        }
    }
    //dfa->setNumStates(partitions.size() + acceptStates.size();
}
