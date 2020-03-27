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
}
void DFAMinimzer::minimize()
{
    this->inputs = dfa->getInputSymbols();
    this->initState = dfa->getInitState();
    this->numStates = dfa->getNumStates();
    this->acceptStates = dfa->getAcceptStates();
    unordered_map<int, string> nonAcceptStates;
    for (int i =0 ; i< this->numStates; i++)
    {
        if (!this->dfa->isAccept(i))
        {
            cout <<  "nonAccept : " << i << endl;
            nonAcceptStates.insert(pair<int,string>(i, ""));
            groupStates.insert(pair<int,int>(i,0));
        }
        else
        {
            cout <<  "Accept : " << i << endl;
            groupStates.insert(pair<int,int>(i, 1));
            //this->counter++;
        }
    }
    this->partitions.push_back(acceptStates);
    this->partitions.push_back(nonAcceptStates);

    this->flag = true;
    for (auto& firstState: this->acceptStates){
        cout << "state : " << firstState.first << "acc : " << firstState.second << "\n";
    }

    while(flag)
    {
        this->flag = false;
        int partitionCount = partitions.size();
        for(int i = 0 ; i < partitionCount; i++)
        {
            this->partitions = doPartition();
        }
    }
    cout<<"table befor : \n";
    for(int i = 0 ; i < numStates; i++) {
            cout << i << " : ";
            for (auto& chars : inputs)
            {
                cout << chars << " -> " << this->dfa->getNextState(i, chars) << ", \n";
            }
      }
    oneStateOfEachGroup();

}

vector<unordered_map<int, string>> DFAMinimzer::doPartition()
{
    int j = 0;
    for (auto& firstState: this->partitions[0])
    {
        unordered_map<int, string> currentPartition;
        currentPartition.insert(pair<int,string>(firstState.first,firstState.second));
        //for(int k = j+1 ; k < partitions[i].size() ; k++)
        int k = 0;
        for(unordered_map<int, string>::iterator secondState = this->partitions[0].begin();
         secondState != partitions[0].end(); ++secondState){
            if(k < (j + 1) ){
                k++;
                continue;
            } else {
                cout << "j = " << firstState.first << "k = " << secondState->first << std::endl;
                bool check = true;
                for(char charInput : this->inputs)
                {
                    //firstState is j & secondState is k
                    int nextFirstState = this->dfa->getNextState(firstState.first,charInput);
                    int nextSecondState = this->dfa->getNextState(secondState->first,charInput);
                    cout << "nextFirstState : " << nextFirstState << "nextSecondState : " << nextSecondState <<"input :"<<charInput << endl;
                   // cout<< "acc1 : " << acceptStates.at(nextFirstState) << "acc2 : "<< acceptStates.at(nextSecondState);
                    if ((nextFirstState != nextSecondState))
                    {
                        cout << "enter divide1\n";
                        check =false;
                        break;
                    } else if ((nextFirstState == nextSecondState)&& dfa->isAccept(firstState.first)
                                && dfa->isAccept(secondState->first)
                                )
                    {
                      cout<< "acc1 : " << acceptStates.at(firstState.first) << "acc2 : "<< acceptStates.at(secondState->first) << "\n";
                        if(acceptStates.at(firstState.first)!= acceptStates.at(secondState->first)) {
                                cout << "enter divide2\n";
                        check =false;
                        break;
                        }
                    }

                }
                if (check)
                {
                    currentPartition.insert(pair<int,string>(secondState->first,secondState->second));
                    this->partitions[0].erase( secondState->first);
                    k--;
                }
                else
                {
                    this->flag = true;
                }
                k++;
            }
        }
        if(partitions[0].size() != 1){
        for (auto& state: currentPartition)
        //for (int m =0; m < currentPartition.size(); m++)
        {
            groupStates[state.first] = this->counter;
        //    cout << "state.first" << state.first << "groupStates : " << counter << endl;
        }
        }
        this->partitions.push_back(currentPartition);
        //this->partitions.insert(this->counter,currentPartition);
        this->partitions[0].erase(firstState.first);
        this->counter++;
    }
        if(flag){
            this->partitions.erase(partitions.begin());
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
        for(auto& charInput : this->inputs)
        {
            nextState = this->dfa->getNextState(currentState, charInput); // return -1 if dead state
            cout <<"currentState = "<<currentState << "-->"   << nextState<< "char : "<< charInput <<endl;
            if(nextState != -1){
                this->dfa->replaceTransition(currentState,nextState,this->groupStates[currentState],
                                              this->groupStates[nextState], charInput);
                        cout << i << "-currentState : " << this->groupStates[currentState]
                         << "nextState : " << groupStates[nextState] << "under : "<< charInput << "\n" << endl;
            } else {
                /*this->dfa->replaceTransition(currentState,nextState,this->groupStates[currentState],
                                              -1 , charInput);*/
                                              cout << i << "-currentState : " << this->groupStates[currentState]
                         << "nextState : " << -1 << "under : "<< charInput << "\n" << endl;
            }
        }
        if(dfa->isAccept(currentState)) {
                this->dfa->newaccept(this->groupStates[currentState], acceptStates.at(currentState));
            }
    }
}
