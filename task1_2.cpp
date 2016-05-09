#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string data;
    string word;

    getline(cin, data);

    istringstream getString(data);

    while(getString >> word)
        if(word[0] == 'A')
            cout << word << " ";

    return 0;
}

