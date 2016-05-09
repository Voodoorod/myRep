#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string data;// вся
    string word;// херня
    string longestWord; //запомнить самое короткое
    string sortedString;

    int longestWordLength = 0; //длина самого короткого

    getline(cin, data);

    istringstream getLongest(data);
    istringstream processingStream(data);

    while(getLongest >> word)
        if(word.size() > longestWordLength)
        {
            longestWord = word;
            longestWordLength = word.size();
        }

    while((data !="") && (data != " "))
    {
        while(processingStream >> word)
            if(word.size() > longestWordLength)
            {
                longestWord = word;
                longestWordLength = word.size();
            }
        sortedString += longestWord + " ";
        data.erase(data.find(longestWord), longestWord.size() + 1);
        longestWordLength = 0;

        processingStream.clear();
        processingStream.str(data);
    }
    cout << sortedString;
    return 0;
}


