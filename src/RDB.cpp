#include "RDB.h"

RDP::RDP(vector<string> tokens, Parser* parser)
{
    this->tokens = tokens;
    this->parser = parser;
    index = this->tokens.begin();
}

NFA RDP::toNFA(){
    NFA nfa = concat();
    while(match("|")){
        NFA right = concat();
        nfa.orOperator(nfa, right);
    }
    return nfa;
}

NFA RDP::concat(){
    NFA nfa = unary();
    while(!isOperator() && index != tokens.end()){
        NFA right = unary();
        nfa.concatenateOperator(nfa, right);
    }
    return nfa;
}

NFA RDP::unary(){
    NFA nfa = primary();
    if(match("+")){
        nfa.plusOperator(nfa);
    } else if(match("*")){
        nfa.starOperator(nfa);
    }
    return nfa;
}

NFA RDP::primary(){
    NFA nfa;
    if(match("\\L")){
        nfa.concatenateOperator('\0', '\0');
        return nfa;
    } else if(isChar()){
        return charSet();
    } else if(match("(")){
        nfa = toNFA();
        if(!match(")")){
            //error
        }
        return nfa;
    } else {
        return word();
    }

}

NFA RDP::charSet(){
    string w = current();
    w.erase(remove(w.begin(), w.end(), '\\'), w.end());
    NFA nfa;
    char left = w[0];
    if(match("-")){
        w = current();
        w.erase(remove(w.begin(), w.end(), '\\'), w.end());
        char right = w[0];
        nfa.dashOperator(left, right);
    } else {
        nfa.concatenateOperator(left, '\0');
    }
    return nfa;
}

NFA RDP::word(){
    string w = current();
    unordered_map<string, NFA>::const_iterator it = parser->getDefinitions().find(w);
    if(it == parser->getDefinitions().end()){
        NFA nfa;
        w.erase(remove(w.begin(), w.end(), '\\'), w.end());
        nfa.concatenateOperator(w[0], w[1]);
        for(int i = 2; i < w.size(); i++){
            nfa.concatenateOperator(nfa, w[i]);
        }
        return nfa;
    } else {
        return it->second;
    }
}

bool RDP::match(string token){
    if(index == tokens.end()) return false;
    if(token == *index){
        index++;
        return true;
    } else {
        return false;
    }
}

bool RDP::isChar(){
    if(isOperator()) return false;
    string w = *index;
    w.erase(remove(w.begin(), w.end(), '\\'), w.end());
    if(w.size() > 1) return false;
    return true;
}

string RDP::current(){
    string token = *index;
    index++;
    return token;
}

bool RDP::isOperator(){
    if(index == tokens.end()) return false;
    if((*index) == "-"){
        return true;
    } else if((*index) == "|"){
        return true;
    } else if((*index) == "+"){
        return true;
    } else if((*index) == "*"){
        return true;
    } else if((*index) == "("){
        return true;
    } else if((*index) == ")"){
        return true;
    }
    return false;

}
