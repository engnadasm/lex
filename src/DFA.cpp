#include "../include/DFA.h"

DFA::DFA(set<char> inputs,int initState){
    this->inputs = inputs;
    this->initState = initState;
}

void DFA::setNumStates(int num){

}
void DFA::addTransition(int s1, int s2, char input){

}
void DFA::accept(int state){

}
set<int> DFA::getAcceptStates(){
    return acceptStates;
}
set<char> DFA::getInputSymbols(){
    return inputs;
}
int DFA::getInitState(){
    return 0;
}
int DFA::getNumStates(){
    return 0;
}
int DFA::getNextState(int state, char input){
    return 0;
}
int DFA::getCurrentState(){
    return 0;
}
bool DFA::isAccept(int state){
    return false;
}
string DFA::getToken(){
    return NULL;
}
void DFA::reset(){

}
