#include "../include/DFA.h"

DFA::DFA(set<char> inputs, int initState){
    this->inputs = inputs;
    this->initState = initState;
    this->currentState = initState;
    lastValidToken = "";
    inputSequence = "";
}

void DFA::initTransitionTable(){
    for(int i = 0; i < numStates; i++){
        for(auto c: inputs){
            transitionTable[i][(char)c] = -1;
        }
    }
}

void DFA::setNumStates(int num){
    this->numStates = num;
    initTransitionTable();
}
void DFA::addTransition(int s1, int s2, char input){
    transitionTable[s1][input] = s2;
}
void DFA::accept(int state){
    if(state >= 0 && state < numStates){
        acceptStates.insert(state);
    }
}
set<int> DFA::getAcceptStates(){
    return acceptStates;
}
set<char> DFA::getInputSymbols(){
    return inputs;
}
int DFA::getInitState(){
    return initState;
}
int DFA::getNumStates(){
    return numStates;
}
int DFA::getNextState(int state, char input){
    return transitionTable[state][input];
}
int DFA::getCurrentState(){
    return currentState;
}
bool DFA::isAccept(int state){
    return (acceptStates.find(state) != acceptStates.end());
}
string DFA::getToken(){
    return lastValidToken;
}
void DFA::reset(){
    lastValidToken = "";
    inputSequence = "";
    currentState = initState;
}

bool DFA::isDead(){
    return currentState == -1;
}

int DFA::move(char input){
    if(inputs.find(input) == inputs.end()) return -1;
    currentState = transitionTable[currentState][input];
    inputSequence += input;
    if(isAccept(currentState)){
        lastValidToken = inputSequence;
    }
    return currentState;
}
