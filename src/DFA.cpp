#include "../include/DFA.h"

DFA::DFA(set<char> inputs, int initState){
    this->inputs = inputs;
    this->initState = initState;
    this->currentState = initState;
    lastValidToken = "";
    lexeme = "";
    inputSequence = "";
    initTransitionTableEntry(initState);
}

void DFA::initTransitionTableEntry(int state){
    unordered_map<char, int> trans;
    transitionTable[state] = trans;
    for(auto c: inputs){
        transitionTable[state][(char)c] = -1;
    }
}

void DFA::addTransition(int s1, int s2, char input){
    if(transitionTable.find(s1) == transitionTable.end()){
        initTransitionTableEntry(s1);
    }
    if(transitionTable.find(s2) == transitionTable.end()){
        initTransitionTableEntry(s2);
    }
    transitionTable[s1][input] = s2;
}
void DFA::accept(int state, string className){
    if(transitionTable.find(state) != transitionTable.end()){
        acceptStates[state] = className;
    }
}
unordered_map<int, string> DFA::getAcceptStates(){
    return acceptStates;
}
set<char> DFA::getInputSymbols(){
    return inputs;
}
int DFA::getInitState(){
    return initState;
}
int DFA::getNumStates(){
    return transitionTable.size();
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
    lexeme = "";
    currentState = initState;
}

bool DFA::isDead(){
    return currentState == -1;
}

int DFA::move(char input){
    if(inputs.find(input) == inputs.end()){
            inputSequence += input;
            return -1;
    }
    currentState = transitionTable[currentState][input];
    inputSequence += input;
    if(isAccept(currentState)){
        lexeme = inputSequence;
        // get token from nfa
        //lastValidToken = inputSequence;
    }
    return currentState;
}
string DFA::getLexeme(){
    return lexeme;
}
string DFA::getInputSequence(){
    return inputSequence;
}
