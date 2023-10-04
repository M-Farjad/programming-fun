//class definitions 
class IntArray
{
public:

	
	~IntArray();		//destructor
	IntArray(int);		//constructor
	IntArray(const IntArray &);			//copy constructor
	int GetSize() const{
		return size_arr;
	}
	int& operator [](const int&);		//overloaded [] operator
private:
	int* aptr;				//pointer to the array	
	int size_arr;			//holds the sizee of the array
	void SubscriptError();	//handles invalid subscript

};