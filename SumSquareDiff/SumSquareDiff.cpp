#include <iostream>
#include <cmath>

using namespace std;

int sumOfSquares(int s, int e);
int squareOfSum(int s, int e);

int main ()
{
    int s = 1;
    int e = 100;
    int result = sumOfSquares(s,e);
    int result2 = squareOfSum(s,e);
    cout << result2 - result;
}
int sumOfSquares(int s, int e)
{
    int sum = 0;
    for (int i= s ; i<=e ; i++)
    {
        sum += i * i;
    }
    return sum;
}

int squareOfSum(int s, int e)
{
    int sum = 0;
    for (int i= s ; i<=e ; i++)
    {
        sum += i;
    }
    return sum * sum;
}
