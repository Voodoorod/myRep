#include <iostream>

using namespace std;

int main()
{
    int arraySize;
    int N;
    cin >> N;
    arraySize = N - 2;

    int *mainArray = new int [arraySize];

    for(int counter = 0; counter <= arraySize; counter ++)
        mainArray[counter] = counter + 2;

    int prime = 2;
    int i = 0;

    while(prime < N)
    {
        for(int counter = prime*prime - 2; counter <= arraySize; counter += prime)
            mainArray[counter] = -1;

        while(mainArray[i] <= prime)
            i++;

        prime = mainArray[i];
    }

    for(int counter = 0; counter <= N - 2; counter++)
        if(mainArray[counter] != -1)
            cout << mainArray[counter] << " ";
}
