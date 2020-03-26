#include <iostream>
#include "include/Parser.h"
#include "include/NDConverter.h"
#include "include/DFAMinimzer.h"
#include "include/DFADriver.h"
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	string rulesPath = "rules.txt";
	string programPath = "program.txt";
	Parser p(rulesPath);
	p.parse();
	NFA* nfaCombined = p.getCombinedNFA();
	int startState = nfaCombined->getStartState();
    set<int> acceptedStates = nfaCombined->getAcceptStates();
    set<char> symbols = nfaCombined->getSymbols();
    set<int> states = nfaCombined->getStates();
    vector<map<char,set<int>>> transitionTable = nfaCombined->getTransitionTable();
    string tokenName = nfaCombined->getName();
    //unordered_map<int, string> acceptedOfAllNFA = nfaCombined->getAcceptedTokens();
    unordered_map<int, pair<int, string>> acceptedOfAllNFA = nfaCombined->getAcceptedTokens();
    cout<<"start state: "<<startState<<endl;
    cout<<"accepted states: ";
    for(int i : acceptedStates)
        cout<< i << " ";
    cout<<endl;
    cout<< "symbols: ";
    for(char c : symbols)
        cout<< c << " ";
    cout<<endl;
    cout<<"states: ";
    for(int i : states)
        cout<< i << " ";
    cout<<endl;
    cout<<"transition Table: "<<endl;
    for(int i = 0; i < transitionTable.size(); i++){
        map<char, set<int>> m = transitionTable.at(i);
        for(map<char, set<int>>::iterator it = m.begin(); it!=m.end(); it++){
            cout<<"state: "<< i <<" takes input: "<<it->first<< " and go to state: ";
            for(int j : it->second){
                cout<<j<< " ";
            }
            cout<<endl;
        }
    }
   /* for(unordered_map<int, string>::iterator it = acceptedOfAllNFA.begin(); it!=acceptedOfAllNFA.end(); it++){
            cout<<"final state: "<< it->first <<" token Name: " << it->second << endl;
    }*/
    for(unordered_map<int, pair<int, string>>::iterator it = acceptedOfAllNFA.begin(); it!=acceptedOfAllNFA.end(); it++){
            cout<<"final state: "<< it->first <<" token Name: " << it->second.second << endl;
    }
    cout<<"Start epsilon closure"<<endl;
    set<int> epsi = nfaCombined->epsloneClosure({3,19});
    for(int j : epsi){
        cout<<j<< " ";
    }
    cout<<endl;
    cout<<"finished epsilon closure"<<endl;
	NDConverter converter(nfaCombined);
	converter.convert();
	DFA* dfaConverted = converter.getDFA();
	dfaConverted->printTransitionTable();
	//DFAMinimzer minimizer(dfaConverted);
	//DFA* dfaMinimized = minimizer.getMinimizedDFA();
	//minimizer.minimize();
	//dfaMinimized->printTransitionTable();

	DFADriver driver(dfaConverted);
	driver.setInputFile(programPath);
	driver.start();
	driver.produceOutputFile();
    return 0;
}
