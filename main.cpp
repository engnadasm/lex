#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    set<char> s;
    s.insert('\0');
    s.insert('1');
    cout << *s.begin() << endl;
    return 0;
}
