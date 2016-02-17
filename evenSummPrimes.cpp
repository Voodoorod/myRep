#include <iostream>

using namespace std;

bool parity_check(int n)
{
    if((n == 0) || (n == 1))
        return false;
    int summ = 0;

    while(n != 0)
    {
        summ += n % 10;
        n /= 10;
    }
    if(summ % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    int arraySize;
    int N;
    int K;
    cin >> K >> N;
    arraySize = N - 2;

    int mainArray[100000];
    /*int *mainArray = new int [arraySize];*/

    for(int counter = 0; counter <= arraySize; counter ++)
            mainArray[counter] = counter + 2;


    int prime = 2;
    int i = 0;

    while(prime < N)
    {
        for(int counter = prime*prime - 2; counter <= arraySize; counter += prime)
            mainArray[counter] = 0;

        while(mainArray[i] <= prime)
            i++;

        prime = mainArray[i];
    }

    for(int counter = K - 2; counter <= N; counter++)
        if((mainArray[counter] != 0) && (parity_check(mainArray[counter])))
           cout << mainArray[counter] << " ";

    return 0;
}
