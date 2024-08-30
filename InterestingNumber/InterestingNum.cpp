#include <iostream>
#include <cmath>

using namespace std;

int digitSum(int x);
bool isDigitPowerSum(int x);
void printDigitPowerSum(int x=10 );

int main ()
{
    //cout << digitSum(512);
    //cout << isDigitPowerSum(88);
    printDigitPowerSum();

}
int digitSum(int x)
{
    if (x == 0)
        return 0;
    else 
        return (x % 10) + digitSum(x / 10);
}


bool isDigitPowerSum(int x)
{
    int temp = x;
    int result = digitSum(x);
    for (int n = 1; n<20;n++)
    {
        result = static_cast<int>(pow(result,n));
        if (result == temp)
            return 1;
        else
            result = digitSum(x);
    }
    return 0;
}

void printDigitPowerSum(int x)
{
    int ctr = 0;
    cout << "Interesting Numbers: " ;
    for (int i = 10; i<100000000; i++)
    {
        if (isDigitPowerSum(i))
        {
            cout << i << " ";
            ctr++;
            if (ctr == x)
                return;
        }
    }
}



