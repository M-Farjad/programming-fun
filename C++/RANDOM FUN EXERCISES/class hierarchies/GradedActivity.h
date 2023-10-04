class GradedActivity
{
protected:
	char letter; // To hold the letter grade 
	double score; // To hold the numeric score 
	//void determineGrade(); // Determines the letter grade
public:
	// Default constructor 
	GradedActivity()
	{
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
	char getletterGrade();
};
char GradedActivity::getletterGrade() {
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
	letter= letterGrade;
	return letter;
}