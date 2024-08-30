#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int ctr = 10001;
    int iniCtr = 0;
    while(iniCtr <= ctr)
    {
        long long i ,j;
        for (i= 2; i<100000000; i++)
        {
            for (j =2 ; j<=i ; j++)
            {
                if (i%j == 0)
                {
                    break;
                }
            }
            if (i==j)
            {
                iniCtr++;
                if (iniCtr==ctr)
                {
                    cout << i;
                }
            }
        }
    }
}