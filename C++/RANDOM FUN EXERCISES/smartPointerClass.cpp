// Pointer classes with Dynamic Allocated Memory 

// this demostrate how the basic classs and its object is used and how to access its member .. 

#include<iostream>
#include<conio.h>
#include<memory> // for smart pointer ... because smart pointer automatically delte when no longer use 
using namespace std;

class Rectangle
{
    private:
        int width;
        int length;
    public: 
        void setLength(int );
        void setWidth(int );
        int getLength();
        int getWidth();
        int getArea();
};

void Rectangle::setLength(int l)
{
    length=l;
}

void Rectangle::setWidth(int w)
{
    width=w;
}

int Rectangle::getLength()
{
    return length;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getArea()
{
    return width*length;
}

int main()
{
    int n ; 
    Rectangle box; 

    unique-ptr <Rectangle> rectPtr(new Rectangle);
}