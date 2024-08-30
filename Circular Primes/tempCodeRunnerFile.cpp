#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x);
bool isCircularPrime(int x);

int main ()
{
    //cout << isPrime(7);
    int ctr = 0;
    for (int i = 2 ; i<=1000000; i++)
    {
        if (isCircularPrime(i))
            ctr++;
    }
    cout << ctr;

}

bool isPrime(int x) 
{
    if (x <= 1) return false;
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
    int num = x;
    for (int i = 0; i < numDigits; i++) 
    {
        if (!isPrime(num))
            return false;
        int lastDigit = num % 10; // Extract the last digit
        num /= 10; // Remove the last digit
        int placeValue = pow(10, numDigits - 1); // Get the place value of the most significant digit
        num += lastDigit * placeValue; // Append the last digit to the front
    }
    return true;
}





