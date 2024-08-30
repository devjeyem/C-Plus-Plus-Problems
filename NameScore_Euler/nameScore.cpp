#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int alphabeticalValue(const string& name) {
    int value = 0;
    for (char c : name) {
        value += c - 'A' + 1; // Assuming uppercase letters only
    }
    return value;
}

int calculateTotalNameScores(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    vector<string> names;
    string name;
    while (getline(file, name, ',')) {
        names.push_back(name.substr(1, name.size() - 2)); // Removing surrounding quotes
    }
    file.close();

    sort(names.begin(), names.end());

    int totalScore = 0;
    for (size_t i = 0; i < names.size(); ++i) {
        totalScore += alphabeticalValue(names[i]) * (i + 1);
    }

    return totalScore;
}

int main() {
    string filename = "names.txt";
    int totalScores = calculateTotalNameScores(filename);
    if (totalScores >= 0) {
        cout << "Total of all the name scores in the file: " << totalScores << endl;
    }
    return 0;
}
