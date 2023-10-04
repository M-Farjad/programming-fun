#include"PassfailExam.h"

int main()
{
	int questions; // Number of questions 
	int missed; // Number of questions missed 
	double minPassing; // The minimum passing score 
	// Get the number of questions on the exam.
	char ch = ' ';
	do
	{

	cout << "How many questions are on the exam? ";
	cin >> questions;
	// Get the number of questions the student missed. 
	cout << "How many questions did the student miss? ";
	cin >> missed;
	// Get the minimum passing score. 
	cout << "Enter the minimum passing score for this test: ";
	cin >> minPassing;
	// Define a PassFailExam object. 
	PassFailExam exam(questions,missed,minPassing);
	// Display the test results. 
	cout << fixed << setprecision(1);
	cout << "\nEach question counts "
		 << exam.getPointsEach() << " points.\n";
	cout << "The minimum passing score is "
		 << exam.getMinPassingScore() << endl;
	cout << "The student's exam score is "
		 << exam.getScore() << endl;
	cout << "The student's grade is "
	<< exam.getLetterGrade() << endl;
	cout << "\nEnter Y/y for doing again: ";
	cin >> ch;
	system("cls");
	} while (ch=='y' || ch == 'Y');
	
	return 0;
}

void displayGrade(GradedActivity activity)
{
	cout << setprecision(1) << fixed;
	cout << "The activity's numeric score is "
		<< activity.getScore() << endl;
	cout << "The activity's letter grade is "
		<< activity.getletterGrade() << endl;
}


