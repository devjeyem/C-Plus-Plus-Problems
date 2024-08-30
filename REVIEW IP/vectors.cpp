#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct employee
{
    int IDNum;
    string name;
    double monthlySalary;
};

int main ()
{
    struct employee p1;
    p1.IDNum = 1214;
    p1.name = "Jm";
    p1.monthlySalary = 100000;

    struct employee p2;
    p2 = p1;

    if (p1.IDNum==p2.IDNum)
    {
        cout << "same" << endl;
    }


}