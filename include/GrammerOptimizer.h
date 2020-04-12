#ifndef GRAMMEROPTIMIZER_H
#define GRAMMEROPTIMIZER_H
#include <vector>
#include "../include/Rule.h"
using namespace std;
class GrammerOptimizer
{
    public:
        GrammerOptimizer(vector<Rule> grammer);
        void RemoveLeftRecusion();
        void leftFactorisation();
        vector<Rule> getRules();

    protected:

    private:
};

#endif // GRAMMEROPTIMIZER_H
