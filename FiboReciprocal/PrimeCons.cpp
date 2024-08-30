#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int x);
int sumOfConsecutivePrime(int x);

int main ()
{
    isPrime(3);
    //cout << "Sum: " << sumOfConsecutivePrime(1000000);
}

int isPrime(int x)
{
    int f=2, ctr=0;
    while (f<=x)
    {
        if (x%f==0)
            ctr++;
        f++;
    }
    if (ctr != 1)
        return 0;
    return 1;
}

int sumOfConsecutivePrime(int x)
{
    int sum = 0;

    while (sum < x)
    {
        for (int i = 2; i < x; i++)
        {
            if (isPrime(i))
            {
                sum += i;
            }
        }
    }
    return sum;
}
