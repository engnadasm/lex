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
	NDConverter converter(nfaCombined);
	converter.convert();
	DFA* dfaConverted = converter.getDFA();
	DFAMinimzer minimizer(dfaConverted);
	DFA* dfaMinimized = minimizer.getMinimizedDFA();
	minimizer.minimize();
	dfaMinimized->printTransitionTable();
	DFADriver driver(dfaMinimized);
	driver.setInputFile(programPath);
	driver.start();
	driver.produceOutputFile();
    return 0;
}
