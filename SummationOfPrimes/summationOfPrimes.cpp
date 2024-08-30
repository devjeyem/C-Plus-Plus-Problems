#include <iostream>

using namespace std;

long long isPrime(long long x);

int main ()
{
    long long sum = 0;
    for (long long i = 2; i<=2000000 ; i++)
    {
        if (isPrime(i))
            sum += i;
    }
    cout << sum;

}

long long isPrime(long long x)
{
    if (x<=1)
        return 0;
    for (int i = 2; i*i<=x; i++)
    {
        if (x%i==0)
            return 0;
    }
    return 1;
}