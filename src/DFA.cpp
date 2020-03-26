#include "../include/DFA.h"
#include <fstream>
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
            currentState = -1;
            return -1;
    }
    currentState = transitionTable[currentState][input];
    inputSequence += input;
    if(isAccept(currentState)){
        lexeme = inputSequence;
        lastValidToken = acceptStates[currentState];
    }
    return currentState;
}
string DFA::getLexeme(){
    return lexeme;
}
string DFA::getInputSequence(){
    return inputSequence;
}
void DFA::printTransitionTable(){
ofstream myfile ("transition table.txt");
  if (myfile.is_open())
  {
      for (auto& state: transitionTable) {
            myfile << state.first << " : ";
            for (auto& transition: state.second)
            {
                myfile << transition.first << " -> " << transition.second << ", ";
            }
         myfile << "\n";
      }
      myfile << "Accept states \n";
      for(auto& s: acceptStates){
        myfile << s.first << " : ";
        myfile << s.second;
        myfile << "\n";
      }
    myfile.close();
  }
  //else cout << "Unable to open file";
  }
