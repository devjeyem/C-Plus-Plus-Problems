#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int x);
int isEven(int x);
void printGoldbachsPair(int x);
void printWaringTrio(int x);


int main ()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    //cout << isPrime (num);
    //cout << isEven(num);
    printGoldbachsPair(num);
    printWaringTrio(num);
}

int isPrime (int x)
{
    int f = 2, ctr = 0;
    while (f<=x)
    {
        if (x % f == 0)
            ctr++;
        f++;    
    }
    if (ctr != 1)
        return 0;
    return 1;    
}

int isEven(int x)
{
    return (x%2==0 && x>4);
}

void printGoldbachsPair(int x)
{
    if (isEven(x))
    {
        for (int i = 2; i < x ; i++)
        {
            for (int j = 2; j <= i; j++)
            {
                if (i+j==x)
                {
                    if (isPrime(i) && isPrime(j))
                    {
                        cout<< "Goldbachs Pair: " << i << " and " << j << endl;
                        return;
                    }
                }
            }
        }
    }
}

void printWaringTrio(int x)
{
    for (int i = 2; i < x ; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k<= j; k++)
            {
                if (i+j+k==x)
                {
                    if (isPrime(i) && isPrime(j) && isPrime(k))
                    {
                        cout<< "Waring Trio: " << i << ", "<< j << ", " << k << endl;
                        return;
                    }
                }
            }
        }
    }    
} 