#include <iostream>

using namespace std;

void bubbleSort(int arr[][3], int r, int c);

int main ()
{
    int arr [3][3] = {  {3,5,4},
                        {6,2,1},
                        {1,2,4},
                     };
    bubbleSort(arr,3,3);
    
}

void bubbleSort(int x[][3], int r, int c)
{
    int temp = 0;
for (int ia=0; ia <3; ia++)
  for (int ja=0; ja <3; ja++)
    for (int ib=0; ib <3; ib++)
      for (int jb=0; jb <3; jb++)
        if(x[ia][ib]<x[ja][jb])
        {
            int temp = x[ia][ib];
            x[ia][ib] = x[ja][jb];
            x[ja][jb] = temp;
        }  
    for (int i = 0; i<3 ; i++)
    {
        for (int j = 0; j<3 ; j++)
        {
            cout << x [i][j] << " ";
        }
        cout << endl;
    }
}