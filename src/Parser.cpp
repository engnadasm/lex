#include "../include/Parser.h"

Parser::Parser(string path)
{
    this->path = path;
}
void Parser::parse(){
    vector<NFA> all;
    string line;
    ifstream file(path);
    while(getline(file, line)){
        all.insert(parseLine(line));
    }
    file.close();
    NFA arr[all.size()];
    copy(all.begin(), all.end(), arr);
    nfa = new NFA();
    nfa.combine(arr, all.size());
}

NFA Parser::parseLine(string line){

}

NFA* Parser::getCombinedNFA(){
    return nfa;
}

