#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    long long num = 36;
    long long largestPrime = 0;

    while (num != 1)
    {
        for (int i = 2 ; i <= num; i++)
        {
            if (num % i == 0)
            {
                largestPrime = i;
                num /= i;
                break;
            }
        }
    }
    cout << largestPrime;
}
