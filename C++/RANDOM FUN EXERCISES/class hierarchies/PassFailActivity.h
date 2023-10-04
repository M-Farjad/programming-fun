#include "GradedActivity.h" 
#include <iostream> 
#include <iomanip>
#include<conio.h>
using namespace std;
class PassFailActivity : public GradedActivity
{
protected:
	double minPassingScore; // Minimum passing score. 
public:
	// Default constructor
	PassFailActivity()
	{
		minPassingScore = 0.0;
	}
	// Constructor
	PassFailActivity(double mps) : GradedActivity()
	{
		minPassingScore = mps;
	}
	// Mutator 
	void setMinPassingScore(double mps)
	{
		minPassingScore = mps;
	}
	// Accessors 
	double getMinPassingScore() const
	{
		return minPassingScore;
	}

	char getLetterGrade() const;
};

char PassFailActivity::getLetterGrade() const {
	char letterGrade;

	if (score >= minPassingScore)
		letterGrade = 'P';
	else
		letterGrade = 'F';
	return letterGrade;
}
