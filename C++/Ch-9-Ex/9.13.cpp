#include <iostream>
#include <string>
using namespace std;

int InputValidate(int);
void movieInfo(int *, const int);
double findmedian(int *, const int);
int findmode(int *, const int);
double Avg(int *, const int);

int main()
{
    int num_of_students;
    double avg, mode, median;
    cout << "how many students were surveyed : ";
    num_of_students = InputValidate(num_of_students);
    int *students = new int[num_of_students];

    movieInfo(students, num_of_students);

    avg = Avg(students, num_of_students);
    mode = findmode(students, num_of_students);
    

    median = findmedian(students, num_of_students);
    system("clear");

    delete[] students;
    students = nullptr;

    cout << "The average is: " << avg << endl;
    cout << "the median is: " << median << endl;
    if ( mode !=  -1)
    {
        cout << "the mode is: " << mode << endl;
    }
    else
        cout << "No value exists more than once: " << endl;

    return 0;
}
int InputValidate(int num)
{
    while (!(cin >> num) || num < 0)
    {
        cout << "Error ! a value above 0 must be entered. ";
        cin.clear();
        cin.ignore(1200, '\n');
    }
    return num;
}
void movieInfo(int *students, const int num_of_students)
{
    cout << "enter the no of movies watched\n";
    for (int i = 0; i < num_of_students; i++)
    {
        cout << "student #"
             << "1: ";
        *(students + i) = InputValidate(*(students + i));
    }
}
double Avg(int *array, int SIZE)
{
    double total = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += *(array + i);
    }
    double Avg = total / SIZE;
    return Avg;
}
double findmedian(int *array, int SIZE)
{
    double median = 0.0;
    if ((SIZE % 2) != 0)
        median = *(array + (SIZE / 2));
    else
        median = (*(array + (SIZE - 1) / 2) + *(array + (SIZE / 2))) / 2.0;
    return median;
}
int findmode(int *array, int SIZE)
{
    int maxvalue = 0,
        maxcount = 0,
        i, j;
    for (i = 0; i < SIZE; i++)
    {
        int count = 0;
        for (j = 0; j < SIZE; j++)
        {
            if (*(array + j) == *(array + i))
                count++;
        }
        if (count > maxcount)
        {

            maxcount = count;
            maxvalue = *(array + i);
        }
        else if (maxcount == 1)
            maxvalue = -1;
    }
    return maxvalue;
}