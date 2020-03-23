#ifndef RDB_H
#define RDB_H
#include <vector>
#include "NFA.h"
#include "Parser.h"


class RDP
{
    public:
        RDP(vector<string> tokens, Parser* parser);
        NFA toNFA();
    protected:

    private:
        Parser* parser;
        vector<string> tokens;
        NFA concat();
        NFA unary();
        NFA primary();
        NFA charSet();
        NFA word();
        bool match(string token);
        bool isOperator();
        bool isChar();
        string current();
        vector<string>::iterator index;
};

#endif // RDB_H
