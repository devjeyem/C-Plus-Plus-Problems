#include <iostream>
using namespace std;

int isWellOrdered(int x);
double fRecursive(int n = 5);
int countWellOrderedInRange(int s , int e);


int main ()
{
    /*cout<< isWellOrdered(143);
    cout<< isWellOrdered(12);
    cout<< isWellOrdered(32);
    cout<< isWellOrdered(1433);
    cout<< isWellOrdered(1445);
    cout<< isWellOrdered(14334);
    cout<< isWellOrdered(1467);*/

    for (int i = 1; i<5;i++)
    {
        cout << fRecursive(i) << ",";
    }
    cout << fRecursive(); 
    cout << endl;
    cout << countWellOrderedInRange(100,500);



}

int isWellOrdered(int x)
{
    int temp = x / 10;
    while (x > 0)
    {
        if (temp % 10 <= x % 10)
        {
            temp /= 10;
            x /= 10;
        }
        else 
            return 0;
    }
    return 1;
}

double fRecursive(int n)
{
    if (n<2)
        return 1;
    else 
        return (1/static_cast<double>(n * fRecursive(n - 1)));    
}

int countWellOrderedInRange(int s = 100, int e = 500)
{
    int ctr = 0;
    for (int i = s; i<= e; i++)
    {
        if (isWellOrdered(i))
        {
            ctr++;
        }
    }
    return ctr;
}