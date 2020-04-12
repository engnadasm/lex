#include "../include/ParserGenerator.h"

ParserGenerator::ParserGenerator(vector<Rule> grammer)
{
    //ctor
    this->grammer = grammer;
}

void ParserGenerator::generateParsingTable()
{
    vector< Rule >::iterator lhs = this->grammer.begin();
    //for each nonTerminal
    while (lhs != this->grammer.end())
    {
        //loop over its productions
        vector<vector<Rule*>>productions = lhs->getProductions();

       lhs++;
    }

}
void ParserGenerator::printParsingTable()
{

}
void ParserGenerator::printParsingTable(string outputFile)
{

}
unordered_map<string,unordered_map<string, Rule>>ParserGenerator::getParsingTable()
{
   return this->parsingTable;

}
