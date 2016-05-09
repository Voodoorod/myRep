#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string data;
    string word;
    string longestWord;
    string secondWord;

    int longestWordPosition;
    int longestWordLength = 0;
    int wordPosition = 0;

    getline(cin, data);

    istringstream getWord(data);
    istringstream getMax(data);
    istringstream oStream(data);

    while(getWord >> word)
    {
        wordPosition++;
        if(word.size() > longestWordLength)
        {
            longestWordLength = word.size();
            longestWordPosition = wordPosition;
        }
    }

    wordPosition = 0;

    while(getMax>> word)
    {
        wordPosition++;
        if(word.size() == longestWordLength)
            longestWord = word;
        if(wordPosition == 2)
            secondWord = word;
    }

    wordPosition = 0;

    while(oStream >> word)
    {
        wordPosition++;
        if(wordPosition == 2)
            cout << longestWord << " ";
        else
            if(wordPosition == longestWordPosition)
                cout << secondWord << " ";
            else
                cout << word << " ";
    }
    //cout << longestWord << " " << secondWord;

    return 0;
}
