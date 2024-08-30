#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

// Define the Student structure
struct Student
{
    std::string StudentID;
    std::string Surname;
    std::string FirstName;
    std::string BirthDate;
    char Gender;
};

// Function to display records
void displayRecords(std::string activeFile, std::vector<Student> students)
{
    std::cout << "Active File : [" << activeFile << "]\n";
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "Rec\tStudent ID\tSurname\t\tFirstname\tBirthDate\tSex\n";
    std::cout << "-----------------------------------------------------------------\n";
    for (size_t i = 0; i < students.size(); ++i)
    {
        std::cout << i + 1 << "\t" << students[i].StudentID << "\t" 
                  << std::setw(10) << std::left << students[i].Surname << "\t"
                  << std::setw(10) << std::left << students[i].FirstName << "\t" 
                  << students[i].BirthDate << "\t\t" << students[i].Gender << "\n";
    }
    std::cout << "-----------------------------------------------------------------\n";
}

// Function to create a new file
void createNewFile(std::string &activeFile, std::vector<Student> &students)
{
    std::cout << "Enter new file name: ";
    std::cin >> activeFile;
    std::ofstream outStudRec(activeFile);
    if (outStudRec)
    {
        std::cout << "File created successfully.\n";
        students.clear(); // Clear current records for the new file
    }
    else
    {
        std::cout << "Error creating file.\n";
    }
}

// Function to save file
void saveFile(std::string activeFile, std::vector<Student> students)
{
    std::ofstream outStudRec(activeFile);
    if (!outStudRec)
    {
        std::cout << "Error opening file for saving.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); ++i)
    {
        outStudRec << students[i].StudentID << " "
                   << students[i].Surname << " "
                   << students[i].FirstName << " "
                   << students[i].BirthDate << " "
                   << students[i].Gender << "\n";
    }

    std::cout << "Records saved to " << activeFile << " successfully.\n";
}

// Function to add a new record
void addRecord(std::vector<Student> &students)
{
    Student newStudent;

    
    std::cout << "Enter Student ID: ";
    std::cin >> newStudent.StudentID;
    std::cout << "Enter Surname: ";
    std::cin.ignore();
    std::getline(std::cin, newStudent.Surname);
    std::cout << "Enter Firstname: ";
    std::getline(std::cin, newStudent.FirstName);
    std::cout << "Enter BirthDate (format: 99/99/99): ";
    std::cin >> newStudent.BirthDate;
    std::cout << "Enter Gender (M/F): ";
    std::cin >> newStudent.Gender;

    students.push_back(newStudent);
}

// Function to edit a record
void editRecord(std::vector<Student> &students, int index)
{
    if (index < 0 || index >= students.size())
    {
        std::cout << "Invalid record number.\n";
        return;
    }

    Student& student = students[index];
    std::cout << "Editing record " << index + 1 << "\n";
    std::cout << "Current Student ID: " << student.StudentID << "\n";
    std::cout << "New Student ID: ";
    std::cin >> student.StudentID;
    std::cout << "Current Surname: " << student.Surname << "\n";
    std::cout << "New Surname: ";
    std::cin.ignore();
    std::getline(std::cin, student.Surname);
    std::cout << "Current Firstname: " << student.FirstName << "\n";
    std::cout << "New Firstname: ";
    std::getline(std::cin, student.FirstName);
    std::cout << "Current BirthDate: " << student.BirthDate << "\n";
    std::cout << "New BirthDate: ";
    std::cin >> student.BirthDate;
    std::cout << "Current Gender: " << student.Gender << "\n";
    std::cout << "New Gender (M/F): ";
    std::cin >> student.Gender;
}

// Function to delete a record
void deleteRecord(std::vector<Student> &students, int index)
{
    if (index < 0 || index >= students.size())
    {
        std::cout << "Invalid record number.\n";
        return;
    }

    students.erase(students.begin() + index);
    std::cout << "Record deleted successfully.\n";
}

// Function to sort records by Surname
void sortRecordsBySurname(std::vector<Student> &students)
{
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
        return a.Surname < b.Surname;
    });
}

// Function to sort records by Student ID
void sortRecordsByID(std::vector<Student> &students)
{
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
        return a.StudentID < b.StudentID;
    });
}

// Data management menu
void manageDataMenu(std::string activeFile, std::vector<Student> &students)
{
    char choice;
    do
    {
        displayRecords(activeFile, students);
        std::cout << "[A]dd [E]dit [D]elete [S]ort sa[V]e e[X]it\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 'A':
            case 'a':
                addRecord(students);
                break;
            case 'E':
            case 'e':
            {
                int index;
                std::cout << "Enter record number to edit: ";
                std::cin >> index;
                editRecord(students, index - 1);
                break;
            }
            case 'D':
            case 'd':
            {
                int index;
                std::cout << "Enter record number to delete: ";
                std::cin >> index;
                deleteRecord(students, index - 1);
                break;
            }
            case 'S':
            case 's':
            {
                char sortChoice;
                std::cout << "[1] Sort by Surname\n[2] Sort by Student ID\n";
                std::cout << "Enter your choice: ";
                std::cin >> sortChoice;
                if (sortChoice == '1')
                {
                    sortRecordsBySurname(students);
                }
                else if (sortChoice == '2')
                {
                    sortRecordsByID(students);
                }
                break;
            }
            case 'V':
            case 'v':
                saveFile(activeFile, students);
                break;
            case 'X':
            case 'x':
                std::cout << "Exiting Data Management...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 'X' && choice != 'x');
}

int main()
{
    std::string activeFile = "sample.txt";
    std::vector<Student> students = {
        {"01-1-00177", "ABELLA", "JOCELYN", "1/1/90", 'F'},
        {"98-1-00754", "AURE REV", "RHIZZA", "1/2/90", 'M'},
        {"01-1-00385", "AUSTERO", "AGNES MARIE", "1/3/90", 'F'},
        {"01-1-01114", "BALDO", "DEMETRIO", "1/4/90", 'M'},
        {"01-1-00706", "CACHUELA", "DAISY", "1/5/90", 'F'},
        {"01-1-01143", "CADIZ", "ADELFA", "1/6/90", 'F'}
    };

    char mainChoice;
    do
    {
        std::cout << "Active File : [" << activeFile << "]\n";
        std::cout << "[1] Create New File [2] Open an Existing File [3] Manage Data [4] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;

        switch (mainChoice)
        {
            case '1':
                createNewFile(activeFile, students);
                break;
            case '2':
            {
                std::cout << "Enter the file name to open: ";
                std::cin >> activeFile;
                std::ifstream inStudRec(activeFile);
                
                if (inStudRec)
                {
                    students.clear();  // Clear the current records
                    Student student;
                    
                    while (inStudRec >> student.StudentID)
                    {
                        inStudRec.ignore(); // Ignore the space after StudentID
                        std::getline(inStudRec, student.Surname, ' ');
                        std::getline(inStudRec, student.FirstName, ' ');
                        inStudRec >> student.BirthDate >> student.Gender;
                        students.push_back(student);
                    }
                    
                    std::cout << "File opened successfully.\n";
                }
                else
                {
                    std::cout << "Error opening file.\n";
                }
                break;
            }
            case '3':
                manageDataMenu(activeFile, students);
                break;
            case '4':
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (mainChoice != '4');

    return 0;
}
