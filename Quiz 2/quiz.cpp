#include <iostream>
#include <cmath>

using namespace std;

int re(int x = 7);
int log(int x);
int log2(int x);

int main()
{
    for (int i=100; i<20000; i*= 3)
    {
        cout << log(i)<< ",";
        cout << log2(i) << ",";
    }
    //cout <<re();
}

int re(int x)
{
    int maxCount = 0, r;
    for (int n = 1; n<10; n++)
    {
        r = static_cast<int>(pow((x-1), n) + pow((x+1), n));
        r = static_cast<int>(r) % static_cast<int>(pow(x, 2));
        if (maxCount < r)
        {
            maxCount = r;
        }
    }
    return maxCount;
}
int log(int x)
{
    if (x<4)
        return 1;
    else 
        return log(x/2)+1;    
}

int log2(int x)
{
    int ctr = 0;
    while (x>=2)
    {
        x = x/2;
        ctr++;
    }
    return ctr;
}
