#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct address
{
    string street;
    string brgy;
    string townCity;
    string province;
    int zipCode;
};

struct employee
{
    int IDNum;
    string name;
    double monthlySalary;
    address empAddress;
};

void addProfile(employee p[], int x, ofstream &outEmpRec);
void readProfile(employee p[], int x, ifstream &inEmpRec);

int main ()
{
    employee person[2];

    ofstream outEmpRec("CompanyEmployeeRecord.txt");
    if(outEmpRec.is_open())
    {
        for (int i = 0; i<2; i++)
        {
            addProfile(person,i,outEmpRec);
        }
        outEmpRec.close();
    }

    else
    {
        cout << "Failed" << endl;
    }

    ifstream inEmpRec;
    inEmpRec.open("CompanyEmployeeRecord.txt");
    if (inEmpRec.is_open())
    {
        for (int i = 0; i < 2; i++)
        {
            readProfile(person,i,inEmpRec);
        }
        inEmpRec.close();
    }

}

void addProfile(employee p[], int x, ofstream &outEmpRec)
{
        cout << "Enter ID Num: ";
        cin >> p[x].IDNum;
        cin.ignore();
        cout << "Enter your name: ";
        getline(cin,p[x].name);
        cout << "Salary Monthly: ";
        cin >> p[x].monthlySalary;
        cin.ignore();
        cout <<"-----------------------------" << endl;
        
        outEmpRec << p[x].IDNum << ",";
        outEmpRec << p[x].name << ",";
        outEmpRec << p[x].monthlySalary << endl;
}

void readProfile(employee p[], int x, ifstream &inEmpRec)
{
    char comma;
    //employee inEmpRec;

   cout << "ID Num: ";
   inEmpRec >> p[x].IDNum >> comma;
   //inEmpRec.ignore();
    cout << p[x].IDNum << endl;

   cout << "Name: ";
   getline(inEmpRec,p[x].name,',');
   cout << p[x].name<< endl;
   
   cout << "Monthly Salary: ";
   inEmpRec >> p[x].monthlySalary;
   cout << p[x].monthlySalary<< endl;





   cout << "----------------------------" << endl;
   

}   