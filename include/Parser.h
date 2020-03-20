#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "NFA.h"

using namespace std;


class Parser
{
    public:
        Parser(string path);
        void parse();
        NFA* getCombinedNFA();

    protected:

    private:
        NFA* parseLine(string line);
};

#endif // PARSER_H
