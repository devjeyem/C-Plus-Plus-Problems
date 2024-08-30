#include <iostream>

using namespace std;

int main ()
{
    int x = 40, f = 1, s = 0;
    bool flag1 = 0, flag2 = 0;
    int i = 12, j;

    for(i=12 ;i<40; i++)
    {
        flag1=0,flag2=0;
        j=x-i;
        f=1;
        s=0;
        while (j>f)
        {
            if (j%f==0)
                s+=f;

            f++;    
        }
        if (s>f)
            flag1=1;
        f=1;
        s=0;
        while (i>f)
        {
            if (i%f==0)
                s+=f;
            f++;    
        }    
        if (s>f)
            flag2=1;
        if (flag1==1&&flag2==1)
            break;
    }
    cout << i << " " << j;
}