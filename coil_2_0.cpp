#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    const int N = 10;
    int A[N][N];
    int line = 0, column = 0;
    int count = 0;
    int c = 1;
    int k = 1;


    while (c <= N*N)
    {
        if (count % 4 == 0)
        {
            for (int j = k - 1; j <= N - k; j++)
            {
                A[line][j] = c++;
                column = j;

                cout << count << " ping 1 -- " << line << " " << j <<   endl;

            }
            count++;
        }

        if (count % 4 == 1)
        {
            for (int i = k; i <= N - k; i++)
            {
                A[i][column] = c++;
                line = i + 1;

                cout << count <<  " ping 2 -- " << i << " " << column << endl;
            }
            count++;
        }

        if (count % 4 == 2)
        {
            line--;
            for (int j = N - k - 1; j >= k - 1; j--)
            {
                A[line][j] = c++;
                column = j;

                cout << count << " ping 3 -- " << line << " " << j << endl ;
            }
            count++;
        }

        if (count % 4 == 3)
        {
            for (int i = N - k - 1; i >= k; i--)
            {
                A[i][column] = c++;
                line = i + 1;

                cout << count <<  " ping 4 -- " << i << " " << column << endl;
            }
            count++;
        }
        k++;
        line--;

    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";

        cout << endl;
    }

    return 0;
}
