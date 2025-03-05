#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate average homework score
double findAverageHomeworkScore(double h1, double h2, double h3, double h4) {
    return (h1 + h2 + h3 + h4) / 4;
}

int main() {
    ifstream inputFile("gradesIn.txt");
    ofstream outputFile2("gradesOut2.txt");

    if (!inputFile || !outputFile2) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string firstName, lastName;
    int studentCount = 0;
    double totalCourseAverage = 0;

    while (inputFile >> firstName >> lastName) {
        double attendance, groupWork, midterm, finalExam;
        double labs[8], homework[4], quizzes[4];

        // Read and print input data for debugging
        inputFile >> attendance;
        cout << "Attendance: " << attendance << endl;

        for (int i = 0; i < 8; i++) {
            inputFile >> labs[i];
            cout << "Lab[" << i << "]: " << labs[i] << endl;
        }

        for (int i = 0; i < 4; i++) {
            inputFile >> homework[i];
            cout << "Homework[" << i << "]: " << homework[i] << endl;
        }

        for (int i = 0; i < 4; i++) {
            inputFile >> quizzes[i];
            cout << "Quiz[" << i << "]: " << quizzes[i] << endl;
        }

        inputFile >> groupWork >> midterm >> finalExam;
        cout << "Group Work: " << groupWork << ", Midterm: " << midterm << ", Final Exam: " << finalExam << endl;

        // Calculate average homework score using the function
        double avgHomework = findAverageHomeworkScore(homework[0], homework[1], homework[2], homework[3]);
        cout << "Average Homework: " << avgHomework << endl;

        // Calculate course average with homework as an important component
        double courseAverage = (attendance * 0.10) + (groupWork * 0.10) + (midterm * 0.20) + (finalExam * 0.20) + (avgHomework * 0.40);
        cout << "Course Average: " << courseAverage << endl;

        // Output for debugging (to see the intermediate values)
        studentCount++;
        totalCourseAverage += courseAverage;
    }

    // Write summary to gradesOut2.txt
    if (studentCount > 0) {
        outputFile2 << "Total Number of Students: " << studentCount << endl;
        outputFile2 << "Average Course Score: " << (totalCourseAverage / studentCount) << endl;
    }

    inputFile.close();
    outputFile2.close();

    cout << "Processing complete. Check gradesOut2.txt for results." << endl;
    return 0;
}
