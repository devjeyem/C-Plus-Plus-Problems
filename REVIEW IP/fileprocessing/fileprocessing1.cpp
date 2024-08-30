#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

int main() {
    // Writing data to a file sequentially
    ofstream outFile("employees.txt");
    if (outFile.is_open()) {
        Employee emp1 = {1, "John Doe", 50000.0};
        Employee emp2 = {2, "Jane Smith", 60000.0};

        // Write emp1
        outFile << emp1.id << "," << emp1.name << "," << emp1.salary << endl;

        // Write emp2
        outFile << emp2.id << "," << emp2.name << "," << emp2.salary << endl;

        outFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
        return 1;
    }

    // Reading data from the file sequentially
    ifstream inFile("employees.txt");
    if (inFile.is_open()) {
        Employee emp;
        char comma;

        while (inFile >> emp.id >> comma && getline(inFile, emp.name, ',') && inFile >> emp.salary) {
            // Display the read data
            cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
        }

        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
        return 1;
    }

    return 0;
}
