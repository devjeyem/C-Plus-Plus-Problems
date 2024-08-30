#include <iostream>
#include <cmath>

using namespace std;

int factorial(int digit);
int isCurious(int num);


int main ()
{
    int sum = 0;
    for(int i = 10; i<10000000;i++)
    {     
       if (isCurious(i))
       {
            sum += i;
       }
    }
    cout << sum;
}

int factorial(int digit)
{
    int result=1;
    for (int i=1; i<=digit;i++)
    {
        result = result * i;
    }
    return result;
}

int isCurious(int num)
{
    int originalNumber = num;
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        sum = sum + factorial(digit);
        num = num / 10;
    }
    return (originalNumber==sum);
}
