#include <iostream>

using namespace std;

long long countCollatzSequence(long long x);

int main()
{
    int maxCount = 0;
    int maxCollatz = 0;

    for (int i = 2; i < 1000000; i++)
    {
        int count = countCollatzSequence(i);
        if (count > maxCount)
        {
            maxCount = count;
            maxCollatz = i;
        }
    }

    cout << maxCollatz << endl;

    return 0;
}

long long countCollatzSequence(long long x)
{
    long long count = 0;
    while (x != 1)
    {
        if (x % 2 == 0)
            x = x / 2;
        else
            x = 3 * x + 1;
        count++;
    }
    return count + 1;
}
