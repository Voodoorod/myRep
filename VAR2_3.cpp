#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string data;// ���
    string word;// �����
    string shortestWord; //��������� ����� ��������
    string preLastWord; //��������� �������������

    int wordPosition = 0; // �������, ����� ���� ������ ��������� �� ��� ���� ������
    int shortestWordLength = 0; //����� ������ ���������
    int wordsAmount = 0; //����� ����
    int shortestWordPosition = 0; //������� ������ ��������� ����� � ������

    getline(cin, data);

    istringstream getWordsAmount(data);//�� ��� �������, ������ ���� �������
    istringstream getShortest(data);
    istringstream oStream(data);

    while(getWordsAmount >> word)//������� ���-�� ���� (���� ����� ����� �������������) � ������ �������� �����-������ �������� ����� ���������
    {
        wordsAmount++;
        shortestWordLength = word.size();
    }

    wordPosition = 0; // ����� �������� ��� ���. � ����. �����

    while(getShortest>> word)
    {
        wordPosition++;
        if(word.size() < shortestWordLength)
        {
            shortestWord = word;
            shortestWordLength = word.size();
            shortestWordPosition = wordPosition; // ��������, ��� ����� ��������, ����� ����� ,���� ������ �������������
        }
        if(wordPosition == wordsAmount - 1)
            preLastWord = word;
    }

    wordPosition = 0;

    while(oStream >> word)
    {
        wordPosition++;
        if(wordPosition == shortestWordPosition) //��� ��������� ����������: �� ������, ������� ���������� ����� �������� (����� ��� ��� ���������, �� ��� ���������� ��������)
            cout << preLastWord << " ";                 //������, ������� ���� ���� ������ ������������� �� ����� ���������
        else                                     //���� �� �������, �������, ����� ��� ��� ������������� �����?
            if(wordPosition == wordsAmount - 1)
                cout << shortestWord << " ";
            else                                 //���� ������� �� "�����������", ������ ������ ������� �����, �� �� ��� �� �������
                cout << word << " ";
    }
    return 0;
}

