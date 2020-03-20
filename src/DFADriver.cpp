#include "../include/DFADriver.h"

DFADriver::DFADriver(DFA* dfa)
{
    this->dfa=dfa;
}
void DFADriver::setInputFile(string path){

}
void DFADriver::start(){
    int i = 0;
    int j = 0;
    int index = 0;
    while( j < inputBuf.size()){
        while(!dfa->isDead()){
            dfa->move(inputBuf[j+i]);
            i++;
        }
        string token = dfa->getToken();
        dfa->reset();
        j = j + token.size();
        i = 0;
        tokens[index] = token;
        index++;
    }
}
vector<string> DFADriver::getTokens(){
    return tokens;
}
