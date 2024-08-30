#include <iostream>

using namespace std;

int main ()
{
    int sum = 0;
    int maxctr=0;
    int count = 0;
    for(int i = 1; ; i++)
    {
        sum += i;
        count = 0;       
        for (int j = 1 ; j*j < sum ; j++)
        {
            if (sum % j == 0)
            {
                count += 2;
            }
            if (j*j== sum)
            {
                count++;
            }
        }
        if (count>maxctr)
        {
            maxctr = count;
            if (count>=500)
            {
                cout << sum;
                return 0;
            }
        }
    }
}