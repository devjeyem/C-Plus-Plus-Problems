#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    const int limit = 1000000;
    vector<int> primes;
    int maxSum = 0;
    int maxCount = 0;
    
    // Generate prime numbers up to one million
    for (int i = 2; i < limit; ++i)
    {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    
    // Iterate through consecutive prime numbers
    for (int i = 0; i < primes.size(); ++i) 
    {
        int sum = 0;
        int count = 0;
        for (int j = i; j < primes.size(); ++j) 
        {
            sum += primes[j];
            count++;
            if (sum >= limit)
                break;
            if (isPrime(sum) && count > maxCount) 
            {
                maxCount = count;
                maxSum = sum;
            }
        }
    }
    
    cout << maxSum << endl;
    
    return 0;
}
