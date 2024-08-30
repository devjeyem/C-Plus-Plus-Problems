#include <iostream>
#include <cmath>

int main ()
{
    long long num = 600851475143;

    while (num != 1)
    {
        for (int i = 2 ; i <= num; i++)
        {
            if (num % i == 0)
            {
                cout << i << " ";
                num /= i;
                break;
            }
        }
    }


}
