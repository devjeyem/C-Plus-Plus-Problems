#include <stdio.h>
#include <math.h>

int main ()
{
    float A,p,r,t;

    printf("Principal: ");
    scanf("%f", &p);

    printf("Interest Rate: ");
    scanf("%f", &r);

    printf("Year Compounding: ");
    scanf("%f", &t);

    r = r / 100;

    if (p>0 && r > 0 && t>0)
    {
        for(int i= 1; i<= t; i++)
        {
            A = p * pow(1+r,i);
            printf("Year [%d] = %.2f\n", i,A);

        }
    }
   else
   {
       printf("No negative input allowed!");
   }
    return 0;
}
