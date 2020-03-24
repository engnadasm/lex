#ifndef DFAMINIMZER_H
#define DFAMINIMZER_H
#include "DFA.h"
#include <set>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class DFAMinimzer
{
    public:
        DFAMinimzer(DFA* dfa);
        void minimize();
        DFA* getMinimizedDFA();
    protected:

    private:
        unordered_map<int, unordered_map<int, string>> doPartition();//Construct New Partition
        void oneStateOfEachGroup();
        DFA* dfa;
        bool flag = true;
        int counter = 1;
        map<int, int> groupStates;
        set<char> inputs ;
        int initState;
        int numStates;
        unordered_map<int, string> acceptStates;
        unordered_map<int, unordered_map<int, string>> partitions;
};

#endif // DFAMINIMZER_H
