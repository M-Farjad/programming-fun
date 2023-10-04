//class declarations
class GPA {
private:
    float english,
        urdu,
        islamiyat,
        math,
        pakStudies,
        physics,
        gpa;

    int T_credit_hours;

public:
    //member functions
    GPA();
    ~GPA();
    float getPercentage();
    void setCredit(int);
    void setGpa(float);
    float getGpa();
    void print();
};