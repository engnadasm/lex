#include <iostream>
#include "include/Parser.h"
#include <set>
#include <vector>
#include <map>

using namespace std;

int main()
{

    Parser p("hhh");
    vector<string> tokens = p.segmentation("num: digit+ | digit+ . digits ( \L | E digits) ");
    for(int i = 0; i < tokens.size(); i++){
        cout << tokens[i] << endl;
    }
    cout << "Hello world!" << endl;
    set<char> s;
    s.insert('\0');
    s.insert('1');
    cout << *s.begin() << endl;
    return 0;
}
