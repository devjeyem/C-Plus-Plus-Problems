#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x);
void storeQuadraticPrime(int x[], int n = 41, int a= 1, int b= 41);
void printQuadraticPrime(int x[], int n);

int main ()
{
    int a,b,n;
    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter n: ";
    cin >> n;


    int x[n];
    storeQuadraticPrime(x,n,a,b);
    printQuadraticPrime(x, n);


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

void storeQuadraticPrime(int x[], int n , int a, int b)
{
    for (int i = 0; i<n ;i++)
    {
        int result = i*i + a*i + b;
        if (isPrime(result))
        {
            x[i] = result;
        }
        else
        {
            x[i] = 0;
        }
    }
}

void printQuadraticPrime(int x[], int n)
{
    for(int i = 0; i<n ; i++)
    {
        if(x[i] != 0)
            cout << x[i] << " ";
    }
}