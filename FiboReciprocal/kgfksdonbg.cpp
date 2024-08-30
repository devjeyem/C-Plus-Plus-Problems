#include <iostream>
#include <cmath>

using namespace std;

int isFib(int x);

int main()
{
    int n = 5;
    double sum = 0;

    for (int i = 1; n>0 ;i++)
    {
        if(isFib(i))
        {
            sum += (1/static_cast<double>(i));
            n--;
        }
    }
    
    cout << sum;
}

int isFib(int x)
{
    int first = 1;
    int second = 2;
    int next;
    if (x==first) return 1;
    for (int i = 1 ; i<100 ; i++)
    {
        next = first + second;
        first = second;
        second = next;
        if (x==first)
            return 1;
    }
    return 0;
}
