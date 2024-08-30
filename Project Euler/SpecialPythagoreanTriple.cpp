#include <iostream>
#include <cmath>

using namespace std;

int powNum(int x);
int isSquare(int x);

int main ()
{
    //cout << powNum(13);
    int c, answer;
    for (int a = 1; a<1000; a++)
    {
        for (int b = 1; b < 1000; b++)
        {
            int result = powNum(a) + powNum(b);
            if (isSquare(result))
            {
                c=static_cast<int>(sqrt(result));
                if (a+b+c==1000)
                {
                    answer = a*b*c;
                }
            }
        }
    }
    cout << answer;
}

int powNum(int x)
{
    return round(pow(x,2));
}

int isSquare(int x)
{
    int root = static_cast<int>(sqrt(x));
    return root * root == x;
}
