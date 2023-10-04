#include <iostream>
using namespace std;

class Array
{
    int size;
    float *arr;

public:
    //Destructor
    ~Array()
    {
        delete[] arr;
    }
    //Constructor
    Array(int s)
    {
        if(s>0)
            size=s;
        else
        {
            do{cout<<"Enter Size of Array : ";
            cin>>s;
            }while(s<=0);
            size=s;
        }
        arr = new float[size];
    }
    //Mutator
    void fillArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << " Enter Number in arr[" << i << "] : ";
            cin >> arr[i];
        }
    }
    void setValue(float val , int index)  //set value at particular index
    {
        if( index < size)
        {
            arr[index]=val;
        }
        else
        {
            do{  cout<<"Kindly Enter Index less then "<<size<<" but greater than 0 : ";
                cin>>index;
            }while(index>size || index<0);
            arr[index]=val;
        }
    }
    //Accessors
    float getValue(int index)              //to get value of a particular index
    {
        if( index < size)
        {
            return arr[index];
        }
        else
        {
            do{  cout<<"Kindly Enter Index less then "<<size<<" : ";
                cin>>index;
            }while(index>size || index<0);
        return arr[index];
        }
    }
    float getHighest()                      //to get highest element of the array
    {
        float max=arr[0];
            for(int i=0 ; i<size ; i++ )
            {
                if( max<arr[i])
                {
                    max=arr[i];
                }
            }
        return max;
    }
    float getLowest()                      //to get lowest element of the array
    {
        float min=arr[0];
            for(int i=0 ; i<size ; i++ )
            {
                if( min>arr[i])
                {
                    min=arr[i];
                }
            }
        return min;
    }
    float getAverage()                    // to get average of all elements in array
    {
        float sum=0;
            for(int i=0 ; i<size ; i++ )
            {
                sum+=arr[i];
            }
        return (sum)/size;
    }
    void print()
    {
        cout<<endl;
        cout<<"The Highest Value is : "<<getHighest()<<endl;
        cout<<"The Lowest  Value is : "<<getLowest()<<endl;
        cout<<"The Average Value is : "<<getAverage()<<endl;
        cout<<"========================================\n";
        for(int i=0; i<size; i++)               // to display elements of array 
        {
            cout<<" arr["<<i<<"] : "<<arr[i]<<endl;
        }
    }
};
int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    Array a1(size);
    int index , val;
    a1.fillArray();

    cout<<"Enter the index of array to set value: ";
    cin >> index;
    
    cout<<"Enter value: ";
    cin >> val;

    a1.setValue(val , index );

    cout<<"Enter the index of array to get the value: ";
    cin >> index;
    cout<<"Value of index is: " << a1.getValue(index);

    a1.print();

    return 0;
}