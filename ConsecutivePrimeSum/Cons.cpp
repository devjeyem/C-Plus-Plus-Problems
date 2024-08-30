#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x);

int main() 
{
    const int limit = 1000000;
    int maxSum = 0;
    int maxCount = 0;
    
    // Iterate through prime numbers up to one million
    for (int i = 2; i < limit; ++i) 
    {
        if (isPrime(i)) 
        {
            int sum = i;
            int count = 1;
            for (int j = i + 1; sum + j < limit; ++j) 
            {
                if (isPrime(j)) 
                {
                    sum += j;
                    count++;
                    if (isPrime(sum) && count > maxCount) 
                    {
                        maxCount = count;
                        maxSum = sum;
                    }
                }
            }
        }
    }
    
    cout << maxSum << endl;
    
    return 0;
}

bool isPrime(int x)
{
    if (x<2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }    
    return true;
}
