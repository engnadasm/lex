#include "../include/NFA.h"

NFA::NFA()
{
    //ctor
}

void NFA::dashOperator(char a, char b){

}
void NFA::orOperator(char a, char b){

}
void NFA::orOperator(NFA nfa, char c){

}
void NFA::orOperator(NFA nfa1, NFA nfa2){

}
void NFA::concatenateOperator(char a, char b){

}
void NFA::concatenateOperator(NFA nfa, char c){

}
void NFA::concatenateOperator(NFA nfa1, NFA nfa2){

}
void NFA::plusOperator(char c){

}
void NFA::plusOperator(NFA nfa){

}
void NFA::starOperator(char c){

}
void NFA::starOperator(NFA nfa){

}
void NFA::keyword(string word){

}
void NFA::keyword(char word[], int len){

}
void NFA::combine(NFA nfa[], int n){

}
set<int> NFA::epsloneClosure(int s){

}
set<int> NFA::epsloneClosure(set<int> T){

}
set<int> NFA::inputMove(set<int> T, char c){

}
set<char> NFA::getSymbols(){

}
set<int> NFA::getStates(){

}
int NFA::getStartState(){

}
set<int> NFA::getAcceptStates(){

}
