#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string data;
    string word;
    string leftMiddleWord;
    string outputString;
    int wordsAmount = 0;
    int wordPosition = -1;

    getline(cin, data);

    istringstream getWord(data);
    istringstream getWordsAmount(data);

    while(getWordsAmount >> word)
        wordsAmount++;

    if(wordsAmount % 2 == 0)
    {
        while(getWord >> word)
        {
            wordPosition++;
            if(wordPosition == wordsAmount / 2 - 1)
                leftMiddleWord = word.substr(0);
            else
                if(wordPosition == wordsAmount / 2)
                    outputString += word + " " + leftMiddleWord + " ";
                else
                    outputString += word + " ";
        }
    }
    else
        while(getWord >> word)
        {
            wordPosition++;
            if(wordPosition != wordsAmount/2)
                cout << word << " ";
        }

    cout << endl;
    cout << outputString;

    return 0;
}

