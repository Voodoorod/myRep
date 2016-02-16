#include <iostream>
#include <cmath>

using namespace std;

bool get_palindrome(int n)
{
    int reversedN = 0;
    while(n != 0)
    {
        reversedN = (reversedN * 10) + (n % 10);
        n /= 10;
    }
    if(reversedN == n)
        return true;
    else
        return false;
}

int main()
{
    bool isPrime[100000];
    int FROM;
    int TO;
    double sqTO;
    int xSquared = 0;
    int ySquared = 0;
    int n;

    cin >> FROM >> TO;

    sqTO = sqrt(TO);

    isPrime[1, 2, 3] = true;

    for(int x = 1; x <= sqTO; x++)
    {
        for(int y = 1; y <= sqTO; y++)
        {
            xSquared = x*x;
            ySquared = y*y;

            n = 4*xSquared + ySquared;
            if((n % 12 == 5) || (n % 12 == 1))
                isPrime[n] = true;

            n -= xSquared;
            if(n % 12 == 7)
                isPrime[n] = true;

            n -= 2 * ySquared;
            if((y < x) && (n % 12 == 11))
                isPrime[n] = true;

        }
    }

    for(n = 5; n <= sqTO; n ++)
        if(isPrime[n])
            for(long k = 5*5; k <= sqTO; k += 5*5)
                isPrime[k] = false;

    for(int k = FROM; k <= TO; k++)
        if(isPrime[k])
            if(get_palindrome(k))
                cout << k;

    return 0;
}
