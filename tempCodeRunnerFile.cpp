#include <iostream>

int getMinArrIdx(int x[], int s, int e);
double gMVA (int x[], int s);
bool isEven(int x);

int main ()
{
    int x[7] {5,2,3,5,1,3,2};
    int x1 [8]={1,2,1,2,2,4,1,1}; 
    int sX= sizeof (x) /sizeof (int); 
    int sX1 = sizeof (x1) /sizeof(int);

    std::cout<<gMVA (x, sX)<<std::endl; 
    for (int i=0;i<sX; i++)
    {
        std::cout<<x[i]<<", ";
    }


}

int getMinArrIdx(int x[], int s, int e)
{
    int minVal =x[s], minValIdx = s;
    for (int i = s; i<e;i++)
    {
        if (x[i]<minVal)
        {
            minVal = x[i];
            minValIdx = i;
        }
    }
    return minValIdx;
}

double gMVA (int x[], int s)
{
    int temp, idxSmall;
    for (int i = 0; i <(s/2)+1 ;i++)
    {
        idxSmall = i;
        idxSmall = getMinArrIdx(x,i,s);
        temp = x[i];
        x[i] = x[idxSmall];
        x[idxSmall] = temp;
    }

    if (isEven(s))
        return (static_cast<double>(x[s/2-1]+x[s/2])/2);
    else
        return x[s/2];


}

bool isEven (int x)
{
    if (x%2==0)
        return 1;
    return 0;
}


