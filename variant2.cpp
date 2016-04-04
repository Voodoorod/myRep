#include <iostream>

using namespace std;

int main()
{
    const int matrixSize = 5;
    int matrix[matrixSize][matrixSize];
    int currentDigit = 1;

    for(int turn = 1; turn <= matrixSize/2; turn++)
    {
        for (int k = matrixSize-turn ; k >= turn-1; k--)
            matrix[k][matrixSize - turn] = currentDigit++;

        for (int k = matrixSize-turn-1 ; k >= turn-1; k-- )
            matrix[turn-1][k] = currentDigit++;

        for (int k = turn; k <= matrixSize - turn; k++)
            matrix[k][turn-1] = currentDigit++;

        for (int k = turn; k < matrixSize - turn; k++)
            matrix[matrixSize-turn][k] = currentDigit++;
    }

    if(matrixSize % 2 == 1)
        matrix[matrixSize/2][matrixSize/2] = 25;

    for(int k = 0; k < matrixSize; k ++)
        {
            cout << endl;

            for(int i = 0; i < matrixSize; i ++)
            {
                cout.width(3);
                cout << matrix[k][i] << " ";
            }
        }
}
