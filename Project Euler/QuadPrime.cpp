#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x);

int main ()
{
    int a = -1000;
    int b = -1000;
    int n = 1000;
    int count = 0;

    int product;

    for (a=-1000; a<=1000; a++)
    {
        for (b=-1000; b<=1000; b++)
        {
            int tempctr = 0;
            for (int i = 0;i<n; i++)
            {
                int result = i * i + (a*i) + b;
                if (isPrime(result))
                {
                    tempctr++;
                }
                else 
                {
                    break;
                }
            }
            if (tempctr > count)
            {
                product = a * b;
                count = tempctr;   
            }
        }
    }
    cout << product; 

}

bool isPrime(int x)
{
    int f = 2, ctr = 0;
    while (f<=x)
    {
        if (x%f==0)
            ctr++;
        f++;    
    }
    if (ctr!=1)
        return 0;
    return 1;    
}