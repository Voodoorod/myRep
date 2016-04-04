#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int range)
{
   return rand()%(range+1);
}


int main()
{
    srand(time(NULL));

    int mainArray[100][100];
    int subArray[10000];

    int mainArraySize;
    int subArraySize;
    int r;
    int temp;
    int counter = 0;

    cin >> mainArraySize;

    subArraySize = mainArraySize * mainArraySize;

    for(int i = 0; i <= subArraySize; i ++)
        subArray[i] = i;

    for(int i = 0; i <= subArraySize; i ++)
    {
        r = random(subArraySize);
        temp = subArray[i];
        subArray[i] = subArray[r];
        subArray[r] = temp;
    }

    for(int i = 0; i < mainArraySize; i ++)
        for(int k = 0; k < mainArraySize; k ++)
            mainArray[i][k] = subArray[counter++];

    for(int i = 0; i < mainArraySize; i ++)
    {
        cout << endl;
        for(int k = 0; k < mainArraySize; k ++)
        {
            cout.width(4);
            cout << mainArray[i][k];
        }
    }
}
