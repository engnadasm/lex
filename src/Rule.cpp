#include "Rule.h"

Rule::Rule(string name)
{
    this->name = name;
    this->terminal = false;
}

bool Rule::isTerminal(){
    return this->terminal;
}
bool Rule::isNullable(){
    return this->nullable;
}
set<string> Rule::getFirst(){
    return this->first;
}
set<string> Rule::getFollow(){
    return this->follow;
}
string Rule::getName(){
    return this->name;
}
void Rule::addProduction(vector<Rule*> r){
    /*cout << "adding production in rule "<<name <<":" ;
    for(auto x: r){
        cout << " " << x->getName();
    }
    cout << endl;*/


    this->productions.push_back(r);
    //cout << "productions so far" << endl;
    //printProductions(productions);
}

void Rule::setTerminal(){
    terminal = true;
}

vector<vector<Rule*>> Rule::getProductions(){
    return productions;
}

void Rule::addFirst(string f){
    this->first.insert(f);
}
void Rule::addFollow(string f){
    this->follow.insert(f);
}
void Rule::addFirst(set<string> f){
    first.insert(f.begin(), f.end());
}
void Rule::addFollow(set<string> f){
    follow.insert(f.begin(), f.end());
}
