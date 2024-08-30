#include <iostream>

using namespace std;

bool isPrime(int x);

int main ()
{
    //cout << isPrime(7);
    const int limit = 1000000;
    int maxCount = 0;
    int maxSum = 0;
    for (int i = 2; i<limit; i++)
    {
        if (isPrime(i))
        {
            int sum = i;
            int count = 1;
            for (int j = i + 1; sum + j < limit; j++)
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
    cout << maxSum;
}

bool isPrime(int x)
{
    if (x<2)
        return false;
    for (int i = 2; i * i <= x ; i++) 
    {
        if (x%i==0)
            return 0;
    }  
    return 1; 
}