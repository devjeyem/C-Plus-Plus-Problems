#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int x);
bool isCircularPrime(int x);

int main()
{
    int ctr = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        if (isCircularPrime(i))
            ctr++;
    }
    cout << "The number of circular primes between 2 and 1,000,000 is: " << ctr << endl;
}

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false; // Not a prime
        }
    }
    return true; // Prime
}

bool isCircularPrime(int x)
{
    int numDigits = log10(x) + 1; // Number of digits in the number
    vector<int> digits(numDigits);
    int num = x;

    // Extract digits and store them in a vector
    for (int i = 0; i < numDigits; i++)
    {
        digits[i] = num % 10;
        num /= 10;
    }

    // Generate all cyclic permutations
    for (int i = 0; i < numDigits; i++)
    {
        int rotatedNum = 0;
        for (int j = 0; j < numDigits; j++)
        {
            rotatedNum = rotatedNum * 10 + digits[(i + j) % numDigits];
        }
        if (!isPrime(rotatedNum))
            return false;
    }
    return true;
}
