#include <iostream>
#include "include/Parser.h"


using namespace std;

int main()
{

    Parser p("hhh");
    vector<string> tokens = p.segmentation("num: digit+ | digit+ . digits ( \L | E digits) ");
    for(int i = 0; i < tokens.size(); i++){
        cout << tokens[i] << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
