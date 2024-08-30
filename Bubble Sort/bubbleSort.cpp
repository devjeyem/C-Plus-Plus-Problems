#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

void randomGenerator(int x[], int s);
void bubbleSort(int x[], int s);
void printSorted(int x[], int s);

int main ()
{
    srand(time(0));
    int s = 10;
    int x[s];
    randomGenerator(x,s);
    bubbleSort(x,s);
    printSorted(x,s);

}

void randomGenerator(int x[], int s)
{
    for (int i = 0; i < s ; i++)
    {
        x[i] = rand()%100;
    }
}

void bubbleSort(int x[], int s)
{
    int temp = 0;
    
    for (int i = 0; i<s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            if (x[i]>x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}

void printSorted(int x[], int s)
{
    for (int i=0;i<s;i++)
    {
        cout << "x[" << i << "] : " << x[i] << endl;
    }
}
