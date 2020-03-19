#ifndef PARSER_H
#define PARSER_H


class Parser
{
    public:
        Parser(string path);
        void parse();
        NFA getCombinedNFA();

    protected:

    private:
        NFA parseLine(string line);
};

#endif // PARSER_H
