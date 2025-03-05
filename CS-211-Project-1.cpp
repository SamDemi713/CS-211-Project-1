#include <iostream>
#include <fstream>

using namespace std;

double findAverageQuizScore(double test1, double test2, double test3, double test4)
{
	(test1 + test2 + test3 + test4 - findMinQuiz(test1, test2, test3, test4)) / 3

}


