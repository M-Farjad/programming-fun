class Animal
{
    private: 
        string name; 
        string type; 
        string color;
        int age;
    public:
        Animal(string);

        void setType(string t) 
        void setAge(int a)  
        void setName(string n)  
        void setColor(string c) 

        string getType()
        int getAge()   const
        string getColor() const
        string getame() const

        void print();
        
};

class Car
{   
    private:
        int yearModel;
        string make;
        int speed;
    public:
        Car(int , string);
    
        int getYearModel();
        string getMake();
        int getSpeed();

        void accelerate();
        void brake();

        void print();
};

class Circle
{
    private: 
        double radius;
        double pi;
    public:
        Circle();
        Circle(double );

        void setRadius(double );
        double getRadius();
        double getArea();
        double getDiameter();
        double getCircumference();

        void print();
};

class Employee
{
    private: 
        string name;
        int id;
        string department;
        string position;
    public:
        Employee(string  ,int , string, string);
        Employee(string , int );
        Employee();

        void setName(string);
        void setId(int);
        void setDestination(string);
        void setPosition(string);

        string getName();
        int getId();
        string getDestination();
        string getPosition();

        void print();
        
};

class Information
{   
    private:
        string name; 
        string address;
        int age;
        string phoneNumber;
    public:
        Information();

        void setName(string s);
        void setAddress(string add);
        void setAge(int a);
        void setPhoneNumber(string p);

        string getName();
        string getAddres();
        int getAge();
        string getPhoneNumber();

        void print();
};

class Inventory
{
    private:
        int itemNumber;
        int quantity;
        double cost;
        double totalCost;
    public:
        Inventory();
        Inventory(int,double,double);

        void setItemNumber(int );
        void setQuantity(int );
        void setCost(double );
        void setTotalCost();
        
        int getItemNumber();
        int getQuantity();
        double getCost();
        double getTotalCost();

        void print();

};
class NumberArray
{
    private:
        int size;
        float *arr;
    public:
     NumberArray(int size);
     ~NumberArray();

    void fillArray();

    void setValue(float , int );
    float getValue( int );

    float getHighest();
    float getLowest();
    float getAverage();

    void print();
};

class Population{
    private:
        double population;
        double noOfDeath;
        double noOfBirth;
    public: 
        Population();

        void setPopulation(double p);
        void setnoOfDeath(double d);
        void setNoOfBirth(double b);

        double getPopulation();
        double getDeathRate();
        double getBirthRate();

        void print();
};

class RetailItem
{  
    private:
        string description;
        int unitsOnHand;
        double price;
    public:
        RetailItem(string , int , double );

        void setDescription(string );
        void setUnitsOnHand(int );
        void setPrice(double);

        string getDescription();
        int getUnitsOnHand();
        double getPrice();

        void print();
        void printHeadings();
};
class TestScore
{
    private:
        int score1;
        int score2;
        int score3;
    public:
        TestScore();
        void setScore1(int);
        void setScore2(int);
        void setScore3(int);

        int getScore1();
        int getScore2();
        int getScore3();
        double getAverageScore();
};