#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student
{
    string studentId;
    string surName;
    string  firstName;
    string birthDate;
    char gender;
};

string createNewFile(vector<Student> &students); // Create a File.
void displayStudentRecords(const string &activeFile, const vector<Student> &students); // Display current record.
void manageData(string &activeFile, vector<Student> &students); // Manage data button.
void saveFileButton(const string &activeFile, const vector<Student> &students); // Save current file.
void addRecordButton(vector<Student> &students); // Implement the addRecord button.

int main()
{
    string activeFile = "sample.txt";
    vector<Student> students = 
    {
        {"01-1-00177", "ABELLA", "JOCELYN", "1/1/90", 'F'},
        {"98-1-00754", "AURE REV", "RHIZZA", "1/2/90", 'M'},
        {"01-1-00385", "AUSTERO", "AGNES MARIE", "1/3/90", 'F'},
        {"01-1-01114", "BALDO", "DEMETRIO", "1/4/90", 'M'},
        {"01-1-00706", "CACHUELA", "DAISY", "1/5/90", 'F'},
        {"01-1-01143", "CADIZ", "ADELFA", "1/6/90", 'F'}
    };

    char choice;
    do
    {
        cout << "Active File : [" << activeFile << "]\n";
        cout << "[1] Create New File [2] Open an Existing File [3] Manage Data [4] Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case '1':
                activeFile = createNewFile(students);
                break;
            case '3':
                manageData(activeFile, students);
                break;
            case '4':
                cout << "Thank you for using! :)\n";
                break;
            default:
                cout << "Choose again.\n";
        }
    } while (choice != '4');

    return 0;
}

string createNewFile(vector<Student> &students) // Create a File.
{   
    string newFileName;
    cout << "Enter new file name: ";
    cin >> newFileName;
    ofstream outStudRec(newFileName);
    if (outStudRec.is_open())
    {
        cout << "File created successfully. :)\n";
        students.clear();
    }
    else
    {
        cout << "File not created. :( \n";
    }
    return newFileName;  // Return the new file name
}

void displayStudentRecords(const string &activeFile, const vector<Student> &students) // Working
{
    cout << "Active File : [" << activeFile << "]" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Rec\tStudent ID\tSurname\t\tFirstname\tBirthDate\tSex" << endl;
    for (size_t i = 0; i < students.size(); i++)
    {
        cout << i + 1 << "\t" << students[i].studentId << "\t" 
             << setw(10) << left <<  students[i].surName << "\t" 
             << setw(10) << left << students[i].firstName << "\t" << students[i].birthDate << "\t\t" 
             << students[i].gender << endl;
    }
    cout << "---------------------------------------------------------------------------" << endl;
}

void manageData(string &activeFile, vector<Student> &students) 
{
    char choice;
    do
    {
        displayStudentRecords(activeFile, students);
        cout << "[A]dd [E]dit [D]elete [S]ort sa[V]e e[X]it" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 'X':
            case 'x':
                cout << "Exiting Manage Data Option..." << endl;
                break;
            default:
                cout << "Enter valid choice please..." << endl;
        }
    } while (choice != 'X'  && choice != 'x');
}
