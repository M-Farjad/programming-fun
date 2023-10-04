// GradedActivity class declaration 
class GradedActivity
{
protected:
	double score; // To hold the numeric score 
	char letter;
public:
	// Default constructor 
	GradedActivity()
	{
		score = 0.0;
		letter = ' ';
	}
	// Constructor 
	GradedActivity(double s)
	{
		score = s;
		letter = ' ';
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
	virtual char getLetterGrade() const {
		char letterGrade; // To hold the letter grade 	
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
		return letterGrade;
	}
};

