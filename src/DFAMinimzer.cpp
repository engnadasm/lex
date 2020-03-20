#include "../include/DFAMinimzer.h"

DFAMinimzer::DFAMinimzer(DFA* dfa)
{
    this->dfa = dfa;
}
void DFAMinimzer::minimize(){

}
DFA* DFAMinimzer::getMinimizedDFA(){
    return this->dfa;
}
