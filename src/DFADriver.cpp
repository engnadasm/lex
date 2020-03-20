#include "../include/DFADriver.h"

DFADriver::DFADriver(DFA* dfa)
{
    this->dfa=dfa;
}
void DFADriver::setInputFile(string path){

}
void DFADriver::start(){

}
set<string> DFADriver::getTokens(){
    return tokens;
}
