#include <iostream> 
#include <iomanip>
using namespace std;
class GradedActivity
{
protected:
	char letter; // To hold the letter grade 
	double score; // To hold the numeric score
public:
	// Default constructor 
	GradedActivity()
	{
	    cout<<"Hello from graded constructor";
		letter = ' '; score = 0.0;
	}
	// Mutator function 
	void setScore(double s)
	{
		score = s;
	}
	// Accessor functions 
	double getScore() const
	{
		return score;
	}
    virtual char getLetterGrade(){
	char letterGrade; // To hold the letter grade 
	cout<<"Hello from GradedActivity getlettergrade";
	if (score > 89)
	letterGrade = 'A';
	else if (score > 79)
		letterGrade = 'B';
	else if (score > 69)
		letterGrade = 'C';
	else if (score > 59)
		letterGrade = 'D';
	else
		letterGrade = 'F';
	letter = letterGrade;
	return letter;
    }
};


class PassFailActivity : public GradedActivity
{
 protected:
	 double minPassingScore; // Minimum passing score. 
 public:
	 // Default constructor 
		PassFailActivity() : GradedActivity()
		{ 
		    cout<<"\nHello from PassFailActivity constructor\n";
		    minPassingScore = 0.0; }
		 // Constructor 
		PassFailActivity(double mps) : GradedActivity()
		{ minPassingScore = mps; }
		 // Mutator 
		void setMinPassingScore(double mps)
		{ minPassingScore = mps; }
		// Accessors 
		double getMinPassingScore() const
		{ return minPassingScore; }
	
		char getLetterGrade();
};

char PassFailActivity::getLetterGrade() {
	 char letterGrade;
	cout<<"Hello from PassFailActivity getlettergrade";
	 if (score >= minPassingScore)
		letterGrade = 'P';
	 else
		letterGrade = 'F';
		return letterGrade;
}


class PassFailExam : public PassFailActivity
{
 private:
	int numQuestions; // Number of questions 
	double pointsEach; // Points for each question 
	int numMissed; // Number of questions missed 
 public:
	 // Default constructor 
	PassFailExam() : PassFailActivity()
	{
	 cout<<"\nHello from PassFailExam constructor\n";
	 numQuestions = 0;
	 pointsEach = 0.0;
	 numMissed = 0; }
	
	 // Constructor 
	 PassFailExam(int questions, int missed, double mps) :
	 PassFailActivity(mps)
	 { 
	     cout<<"Hello from PassFailExam constructor";
	     set(questions, missed); }

	 // Mutator function 
	 void set(int, int); 
	 // Accessor functions 
	 double getNumQuestions() const
	 { return numQuestions; }
	 double getPointsEach() const
	 { return pointsEach; }
	 int getNumMissed() const
	 { return numMissed; }
	
};

void PassFailExam::set(int questions, int missed)
{
	double numericScore; // To hold the numeric score 
	// Set the number of questions and number missed. 
	numQuestions = questions;
	numMissed = missed;
	// Calculate the points for each question. 
	pointsEach = 100.0 / numQuestions;
	// Calculate the numeric score for this exam. 
	numericScore = 100.0 - (missed * pointsEach);
	// Call the inherited setScore function to set 
	// the numeric score. 
	setScore(numericScore);
}



int main()
{
	// int questions; // Number of questions 
	// int missed; // Number of questions missed 
	// double minPassing; // The minimum passing score 
	// // Get the number of questions on the exam.

	// cout << "How many questions are on the exam? ";
	// cin >> questions;
	// // Get the number of questions the student missed. 
	// cout << "How many questions did the student miss? ";
	// cin >> missed;
	// // Get the minimum passing score. 
	// cout << "Enter the minimum passing score for this test: ";
	// cin >> minPassing;
	// // Define a PassFailExam object. 
	// PassFailExam exam(questions, missed, minPassing);
	// // Display the test results. 
	// cout << fixed << setprecision(1);
	// cout << "\nEach question counts "
	// 	 << exam.getPointsEach() << " points.\n";
	// cout << "The minimum passing score is "
	// 	 << exam.getMinPassingScore() << endl;
	// cout << "The student's exam score is "
	// 	 << exam.getScore() << endl;
	// cout << "The student's grade is "
	// << exam.getLetterGrade() << endl;

    // exam.~PassFailExam();
	GradedActivity*ptr;
	PassFailActivity obj;
	ptr=&obj;
	ptr->getLetterGrade();
	return 0;
	
}