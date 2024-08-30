#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct address
{

    int streetNum;
    string town;

};

struct employee
{
   int idNum=123;
   string name;
   double monthlySalary;
   address empAddress;
   int age;
};


//int f1(employee emp1);


int main()
{
    employee companyAEmp,companyBEmp;

    companyAEmp.idNum = 12343;
    companyAEmp.name = "SampleName";
    companyAEmp.monthlySalary = 14325.212;
    companyAEmp.age = 18;


    ifstream inRecEmp;
    ofstream outRecEmp;


    outRecEmp.open("CompanyAEmployeeRecord.txt");

    outRecEmp<<companyAEmp.idNum<<",";
    outRecEmp<<companyAEmp.name<<",";
    outRecEmp<<companyAEmp.monthlySalary<<",";
    outRecEmp<<companyAEmp.age<<endl;

    int x;
    string z;
    double y;
    int a;
    inRecEmp.open("CompanyAEmployeeRecord.txt");
    if (inRecEmp.is_open())
    {
        while (!inRecEmp.eof())
        {
        char comma;

        inRecEmp>>x>>comma;
        cout<<x<<endl;

        getline(inRecEmp,z,',');
        //inRecEmp>>y;
        cout<<z<<endl;

        inRecEmp>>y>>comma;
        cout<<y<<endl;

        inRecEmp>>a;
        cout<<a<<endl;
        }
    }
    else
    {
        cout<<"File does not exist";
    }
}