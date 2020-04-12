#ifndef RULE_H
#define RULE_H
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


class Rule
{
    public:
        Rule(string name);
        bool isTerminal();
        bool isNullable();
        set<string> getFirst();
        set<string> getFollow();
        void addFirst(string f);
        void addFollow(string f);
        void addFirst(set<string> f);
        void addFollow(set<string> f);
        string getName();
        void addProduction(vector<Rule*> r);
        vector<vector<Rule*>> getProductions();
        void setTerminal();


    protected:

    private:
        bool terminal;
        vector<vector<Rule*>> productions;
        set<string> first;
        set<string> follow;
        bool nullable;
        string name;

};

static inline void printProductions(vector<vector<Rule*>> p){
    for(int j = 0; j < p.size(); j++){
        //cout << "production " << j << " :";
        for(int k = 0; k < p[j].size(); k++){
            cout << " " <<p[j][k]->getName();
        }
        cout << " | ";
    }
    cout << endl;
}

#endif // RULE_H
