#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct student
{
 string studentName;
 double score;
};

vector<student> readFromRecord (string fileName); //s
double recAverage (vector<student> S);
double recSTDev(vector<student> S);
double recPearCorr(vector<student> S1, vector <student> S2);
void writeResultToFile (double ave1, double ave2, double stDev1,double stDev2, double PearCorr);

int main()
{
    vector<student> S1= readFromRecord("StudentRecord1.txt");
    vector<student> S2= readFromRecord("StudentRecord2.txt");

    /*for (size_t i = 0; i < S1.size(); i++)
    {
        cout<< S1[i].studentName << " : "<< S1[i].score << endl;
    }*/

    //cout << recAverage (S1);
    //cout <<recSTDev(S1);
    //cout << recPearCorr(S1,S2);

    recAverage(S1);
    recAverage(S2);
    recSTDev(S1);
    recSTDev(S2);
    recPearCorr(S1,S2);

    writeResultToFile(recAverage(S1),recAverage(S2), recSTDev(S1),recSTDev(S2),  recPearCorr(S1,S2));



}

vector<student> readFromRecord (string fileName)
{
    ifstream inStudentRecord;
    inStudentRecord.open(fileName);
    student sTemp;
    vector<student> S;

    if(inStudentRecord.is_open())
    {
        while (!inStudentRecord.eof())
        {
            getline(inStudentRecord, sTemp.studentName , '\t');
            inStudentRecord>> sTemp.score;
            S.push_back(sTemp);
        }
    }
    else
    {
        cout << "File not found";
    }
    inStudentRecord.close();
    return S;


}

double recAverage (vector<student> S)
{
    double sum = 0;
    for (int i = 0; i<S.size();i++ )
    {
        sum += S.at(i).score;
    }
    return sum / S.size();
}

double recSTDev(vector<student> S)
{
    double sum = 0;
    double mean = recAverage(S);
    for (int i = 0; i < S.size(); i++)
    {
        sum = sum + pow((S.at(i).score-mean), 2);
    }
    return sqrt(sum / S.size());
}

double recPearCorr(vector<student> S1, vector <student> S2)
{
    double sum = 0;
    double mean1 = recAverage(S1);
    double mean2 = recAverage(S2);
    double std1 = recSTDev(S1);
    double std2 = recSTDev(S2);
    for (int i = 0; i<S1.size(); i++)
    {
        sum = sum + ((S1.at(i).score-mean1)*(S2.at(i).score-mean2))/(std1*std2);
    }
    return sum / S1.size();
}

void writeResultToFile (double ave1, double ave2, double stDev1,double stDev2, double PearCorr)
{
    ofstream outStudentRecord;
    outStudentRecord.open("scoreDescStat.txt");

    if (outStudentRecord.is_open())
    {
        outStudentRecord << "Average Score 1: " << ave1 << endl;
        outStudentRecord << "Average Score 2: " << ave2 << endl;
        outStudentRecord << "Standard Deviation 1: " << stDev1 << endl;
        outStudentRecord << "Standard Deviation 2: " << stDev2 << endl;
        outStudentRecord << "Pearson Correlation Coefficient: " << PearCorr << endl;
    }
    else
    {
        cout << "Failed to open file";
    }
    outStudentRecord.close();
}

