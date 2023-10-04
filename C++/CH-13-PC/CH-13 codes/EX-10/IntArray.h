//class declarations

class IntArray
{
    int size;
    float* arr;

public:
    //Destructor
    ~IntArray();
    //Constructor
    IntArray(int);
    //Mutator
    void fillArray();
    
    void setValue(float, int);
    //Accessors
    float getValue(int);
    float gethighest();
    float getLowest();
    float getAverage();
    void print();
};