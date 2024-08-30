 #include <iostream>
 #include <cmath>
 #include <iomanip>

 using namespace std;

 int isFib(int x);
 void dispFibsInRange(int s, int e);
 void dispFibsReciprocalInRange(int s, int e);
 double FibsReciprocalSumInRange(int s, int e);

 int main()
 {
   cout << isFib(1) << endl;

   cout << "Fibronacci in Range: ";
   dispFibsInRange(1,10);
   cout << '\n';

   cout << "Reciprocal Fibronacci in Range: ";
   dispFibsReciprocalInRange(1,10);

   cout << '\n';

   cout << "Sum: " << setprecision(3) << FibsReciprocalSumInRange(1,10);


   return 0;

 }

 int isFib(int x)
 {
     int first=0;
     int second=1;
     int next;
     for (int i = 1; i<100; i++)
     {
         next = first + second;
         first = second;
         second = next;
         if (x == first)
             return 1;
     }
     return 0;
 }

void dispFibsInRange(int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (isFib(i))
        {
            cout << i << ",";
        }
    }
}

void dispFibsReciprocalInRange(int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (isFib(i))
        {
            cout << 1/static_cast<double>(i) << ",";
        }
    }
}

double FibsReciprocalSumInRange(int s, int e)
{
    double sum = 0;
    for (int i = s; i <= e; i++)
    {
        if (isFib(i))
        {
            sum += (1/static_cast<double>(i));
        }
    }
    return sum;
}
