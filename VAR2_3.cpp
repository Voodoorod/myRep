#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string data;// вся
    string word;// херня
    string shortestWord; //запомнить самое короткое
    string preLastWord; //запомнить предпоследнее

    int wordPosition = 0; // счетчик, чтобы знат ькогда вставлять то или иное слдово
    int shortestWordLength = 0; //длина самого короткого
    int wordsAmount = 0; //число слов
    int shortestWordPosition = 0; //позиция самого короткого слова в строке

    getline(cin, data);

    istringstream getWordsAmount(data);//ну тут понятно, просто куча потоков
    istringstream getShortest(data);
    istringstream oStream(data);

    while(getWordsAmount >> word)//считаем кол-во слов (чтоб потом найти предпоследнее) и заодно получаем какой-нибудь значение длины короткого
    {
        wordsAmount++;
        shortestWordLength = word.size();
    }

    wordPosition = 0; // сброс счетчика для исп. в след. цикле

    while(getShortest>> word)
    {
        wordPosition++;
        if(word.size() < shortestWordLength)
        {
            shortestWord = word;
            shortestWordLength = word.size();
            shortestWordPosition = wordPosition; // запомним, где самое короткое, чтобы знать ,куда тыкать предпоследнее
        }
        if(wordPosition == wordsAmount - 1)
            preLastWord = word;
    }

    wordPosition = 0;

    while(oStream >> word)
    {
        wordPosition++;
        if(wordPosition == shortestWordPosition) //тут расставим приоритеты: по логике, вначале встретится замое короткое (разве что оно последнее, на это отдельнавя проверка)
            cout << preLastWord << " ";                 //значит, вначале ищем куда ткнуть предпоследнее на место короткого
        else                                     //если не находим, смотрим, вдруг это уже предпоследнее слово?
            if(wordPosition == wordsAmount - 1)
                cout << shortestWord << " ";
            else                                 //если позиция не "критическая", просто бахаем текущее слово, ни на что не заменяя
                cout << word << " ";
    }
    return 0;
}

