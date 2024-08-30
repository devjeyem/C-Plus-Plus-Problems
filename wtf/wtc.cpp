#include <iostream>
#include <cmath>

using namespace std;

long long int intExp(int a, int b);
int digitSum (long long int x);
void storeLargestExpDigitSum (int x[], int s);
int dispExpDigitSum(int x[],int s);

int main ()
{
    //cout << intExp(8,2);
    //cout << digitSum (512);
    int s = 10;
    int x[s];
    storeLargestExpDigitSum (x,s);
    dispExpDigitSum(x,s);



}

long long int intExp(int a, int b)
{
    return static_cast<long long int>(pow(a,b));
}

int digitSum (long long int x)
{
    int sum = 0;
    while (x > 0)
    {
        int digit = x % 10;
        sum += digit;
        x /= 10;
    }
    return sum;
}

void storeLargestExpDigitSum (int x[], int s)
{
    int temp = 0;
    int max = 0;
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 19; b++)
        {
            temp = digitSum(intExp(a,b));
            if (temp > max)
            {
                max = temp;
            }
            x[a] = max;
        }
    }

}

int dispExpDigitSum(int x[],int s)
{
    for (int i = 0 ; i<s ; i++)
    {
        cout << x[i] << " ";
    }
}











