#include <iostream>
#include <fstream>
using namespace std;

//Function to calculate the average of 8 lab scores
double findAverageLabScore(double lab1, double lab2, double lab3, double lab4, double lab5, double lab6, double lab7, double lab8)
{
    return (lab1 + lab2 + lab3 + lab4 + lab5 + lab6 + lab7 + lab8) / 8.0;
}
int main()
{
    ofstream outFile("gradesOut1.txt"); //Open file for writing

    if (!outFile)
    {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    double lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8;

    //Taking input from user and writing to file
    cout << "Enter 8 lab scores separated by spaces: " << endl;
    cin >> lab1 >> lab2 >> lab3 >> lab4 >> lab5 >> lab6 >> lab7 >> lab8;

    outFile << lab1 << " " << lab2 << " " << lab3 << " " << lab4 << " " << lab5 << " " << lab6 << " " << lab7 << " " << lab8;

    outFile.close(); //Close file after writing

    ifstream inFile("gradesOut1.txt"); //Open file for reading

    if (!inFile)
    {
        cout << "Error opening file for reading!" << endl;//Error message if something went wrong
        return 1;
    }


    //Reading values from file
    inFile >> lab1 >> lab2 >> lab3 >> lab4 >> lab5 >> lab6 >> lab7 >> lab8;

    inFile.close(); // Close file after reading

    //Display lab average
    double labAvg = findAverageLabScore(lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8);
    cout << "Lab Average: " << labAvg << endl;

    return 0;
}