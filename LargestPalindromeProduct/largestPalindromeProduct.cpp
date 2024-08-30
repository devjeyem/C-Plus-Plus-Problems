#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int isPalindrome(int num);

int main ()
{
    int max = 0;
    int product = 0;
    for (int i = 100 ; i<1000; i++)
    {
        for (int j = 100 ; j<=i ; j++)
        {
            product = i*j;
            if(isPalindrome(product) && product>max)
            {
                max = product;
            }
        }
    }
    cout << max;
}

int isPalindrome(int num)
{
    int origNum = num;
    int reversed = 0;
    while (num!=0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return origNum == reversed;
}