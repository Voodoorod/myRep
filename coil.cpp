#include <iostream>

using namespace std;

int main()
{
    const int matrixSize = 4;
    int matrix[matrixSize][matrixSize];
    int currentDigit = 1;

    for(int turn = 1; turn <= matrixSize/2; turn++)
    {
        for (int k = turn-1; k < matrixSize - turn+1; k++)
            matrix[turn-1][k] = currentDigit++;

        for (int k = turn; k < matrixSize - turn+1; k++)
            matrix[k][matrixSize-turn] = currentDigit++;

        for (int k = matrixSize - turn - 1; k >= turn-1; k--)
            matrix[matrixSize-turn][k] = currentDigit++;

        for (int k = matrixSize - turn - 1; k >= turn; k--)
            matrix[k][turn-1] = currentDigit++;
    }

    for(int k = 0; k < matrixSize; k ++)
        {
            cout << endl;

            for(int i = 0; i < matrixSize; i ++)
                cout << matrix[k][i] << " ";
        }
}
