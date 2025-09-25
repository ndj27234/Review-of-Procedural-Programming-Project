#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 5;

int readData(ifstream &inFile, string names[], double scores[][NUM_TESTS]);
void calcAverages(double scores[][NUM_TESTS], int count, double averages[]);
char calcLetterGrade(double avg);
void printReport(string names[], double scores[][NUM_TESTS], double averages[], int count);

int main() {
    const int MAX_STUDENTS = 50;  
    string names[MAX_STUDENTS];
    double scores[MAX_STUDENTS][NUM_TESTS];
    double averages[MAX_STUDENTS];

    ifstream inFile("StudentGrades.txt");
    if (!inFile) {
        cout << "Error opening file.\n";
        return 1;
    }

    int studentCount = readData(inFile, names, scores);
    calcAverages(scores, studentCount, averages);
    printReport(names, scores, averages, studentCount);

    return 0;
}

int readData(ifstream &inFile, string names[], double scores[][NUM_TESTS]) {
    int count = 0;
    while (inFile >> names[count]) {
        for (int i = 0; i < NUM_TESTS; i++) {
            inFile >> scores[count][i];
        }
        count++;
    }
    return count;
}

void calcAverages(double scores[][NUM_TESTS], int count, double averages[]) {
    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / NUM_TESTS;
    }
}

char calcLetterGrade(double avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

void printReport(string names[], double scores[][NUM_TESTS], double averages[], int count) {
    cout << left << setw(15) << "Name"
         << setw(10) << "Average"
         << setw(10) << "Grade" << endl;

    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << names[i]
             << setw(10) << fixed << setprecision(2) << averages[i]
             << setw(10) << calcLetterGrade(averages[i])
             << endl;
    }
}
