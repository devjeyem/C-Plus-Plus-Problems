#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long calculateLCM(int n);

int main() 
{
    int n = 20;
    cout << "The smallest positive number evenly divisible by all numbers from 1 to " << n << " is: " << calculateLCM(n) << endl;
    return 0;
}

long long gcd(long long a, long long b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) 
{
    return (a / gcd(a, b)) * b;
}

long long calculateLCM(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; ++i) 
    {
        result = lcm(result, i);
    }
    return result;
}

