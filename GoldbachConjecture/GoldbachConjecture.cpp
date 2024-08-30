#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void initArrayRandInt (int x[], int s);
int isPrime(int x);
int isEven(int x);
void printGoldbachsPairInArray (int x[], int s);


int main ()
{
    srand(time(0));
    int s = 10;
    int x[s];
    initArrayRandInt (x,s);
    //cout << isPrime(1);
    //cout << isEven(37);
    printGoldbachsPairInArray (x,s);


}

/* Initializes array x of size s with random positive integers*/
void initArrayRandInt (int x[], int s)
{
    for (int i = 0; i<s;i++)
    {
        x[i]= rand()%10+1;
    }
}

/* Determines if integer x is an prime number, return 1 if prime 0 if 
otherwise*/
int isPrime(int x)
{
    int f = 2, ctr = 0;
    while (f<=x)
    {
        if (x%f==0)
            ctr++;
        f++;    
    }
    if (ctr != 1)
        return 0;
    return 1;    
}

/* Determines if integer x is an even greater than 4, return 1 if even 0 if 
otherwise.*/
int isEven(int x)
{
    if (x>4 && x%2 == 0)
        return 1;
    return 0;         
}

/* Prints the Goldbach’s pair (1 pair only) of element(s) in array (if there 
are any). Using the functions isPrime and isEven*/
void printGoldbachsPairInArray (int x[], int s)
{
    for (int i= 0; i<s ; i++)
    {
        for (int j = i+1; j<s ; j++)
        {
            if (isEven(x[i]+x[j]) && isPrime(x[i]) && isPrime(x[j]))
            {
                cout << x[i]+ x[j] << " = " << x[i] << " + " << x[j];
                return;
            }
        }
    }    
}

