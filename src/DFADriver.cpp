#include "../include/DFADriver.h"

DFADriver::DFADriver(DFA* dfa)
{
    this->dfa=dfa;
    this->symbolTable = new SymbolTable();
}
void DFADriver::setInputFile(string path){

}
void DFADriver::start(){
    int i = 0;
    int j = 0;
    int index = 0;
    while( j < inputBuf.size()){
        while(!dfa->isDead()&& j+i < inputBuf.size()){
            dfa->move(inputBuf[j+i]);
            i++;
        }
        string token = dfa->getToken();
        string lexeme = dfa->getLexeme();
        //insert identifiers into symbol table
        if(token == "id"){
            symbolTable->insert(lexeme);
        }
        //no match exists
        if(token == ""){
            //call error recovery routine to produce an error message
        }
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
