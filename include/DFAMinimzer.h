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
        vector<unordered_map<int, string>> doPartition( vector<unordered_map<int, string>> oldPartition);//Construct New Partition
    protected:

    private:
        DFA* dfa;
        bool flag = true;
        int counter = 2;
        map <int, int> stateSet;
};

#endif // DFAMINIMZER_H
