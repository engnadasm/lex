#include "../include/DFADriver.h"
#include <fstream>
#include "../include/ErrorMessages.h"
DFADriver::DFADriver(DFA* dfa)
{
    this->dfa = dfa;
    this->symbolTable = new SymbolTable();
    inputBuf = "";
}
void DFADriver::setInputFile(string path){
    string line;
    ifstream file(path);
    if (file.is_open())
    {
        while(getline(file, line)){
            inputBuf += line;
        }
        file.close();
    }
}
void DFADriver::start(){
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int index = 0;
    while( j < inputBuf.size()){
        while(!dfa->isDead()&& j+i < inputBuf.size()){
            dfa->move(inputBuf[j+i]);
            i++;
        }
        string token = dfa->getToken();
        string lexeme = dfa->getLexeme();
        //no match exists
        if(token == ""){
             if(dfa->getInputSequence()== " " || dfa->getInputSequence()== "\n"){// No Error
                j++;
             }else{
                //call error recovery routine to produce an error message
                produceLexicalError(dfa->getInputSequence());
                j++;
             }

        }//match exist
        else{
            tokens[index] = token;
            index++;
         //insert identifiers into symbol table
            if(token == "id"){
                symbolTable->insert(lexeme, token);
            }
            j = j + token.size();
        }

        i = 0;
        dfa->reset();
    }
}
vector<string> DFADriver::getTokens(){
    return tokens;
}
SymbolTable* DFADriver::getSymbolTable(){
    return symbolTable;
}
void DFADriver::produceOutputFile(){
    ofstream myfile ("lexical file.txt");
  if (myfile.is_open())
  {
      vector< string >::iterator i = tokens.begin();
            while (i != tokens.end())
            {
                myfile << *i;
                myfile << "\n";
                i++;
            }
    myfile.close();
  }
  else cout << "Unable to open file";
}
