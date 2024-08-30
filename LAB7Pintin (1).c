#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    time_t t;
    srand((unsigned) time(&t));

    int max =100;
    int nxm[max][max], r,c,sum=0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Input Array: \n");

    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c; j++)
        {
            nxm[i][j]= rand()%9;
            printf("%d ", nxm[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Average of Columns: ");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c; j++)
        {
            sum+= nxm[j][i];
        }
        printf("%.2lf ",((double)sum)/c);
        sum=0;
    }

    printf("\nAverage of Rows: ");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c; j++)
        {
            sum+= nxm[i][j];
        }
        printf("%.2lf ",((double)sum)/r);
        sum=0;
    }

    printf("\nOverall Average: ");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c; j++)
        {
            sum+= nxm[i][j];
        }
    }
    printf("%.2lf ",((double)sum)/(r*c));

    return 0;
}
