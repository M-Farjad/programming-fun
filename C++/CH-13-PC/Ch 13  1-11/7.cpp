#include <iostream>
#include <string>

using namespace std;

class TestScores {
    int score1,
        score2,
        score3;

public:
    //constructors
    TestScores(){
        score1 = 0;
        score2 = 0;
        score3 = 0;
    }
    TestScores(int n1 , int n2 , int n3){
        score1 = n1;
        score2 = n2;
        score3 = n3;
    }
    //Mutator functions
    void setScore1(int n){
        while(n < 0){
            cout<<"Please enter a positive Number: ";           
            cin>>n;
        }
        score1 = n ;
    }
    void setScore2(int n){
        while(n < 0){
            cout<<"Please enter a positive Number: ";           
            cin>>n;
        }
        score2 = n ;
    }
    void setScore3(int n){
        while(n < 0){
            cout<<"Please enter a positive Number: ";           
            cin>>n;
        }
        score3 = n ;
    }
    //accessor functions
    int getScore1(){
        return score1;
    }
    int getScore2(){
        return score2;
    }
    int getScore3(){
        return score3;
    }
    double getAverage(){
        return (score1 + score2 + score3)/3.0 ;
    }
};
int main(){
    
    int s1 , s2 , s3 ;
    TestScores t1;
    cout<<"Enter the first score: ";
    cin >> s1;
    t1.setScore1(s1);

    cout<<"Enter the second score: ";
    cin >> s2;
    t1.setScore1(s2);
    
    cout<<"Enter the third score: ";
    cin >> s3;
    t1.setScore1(s3);

    cout<<"The average of the scores is: "<<t1.getAverage()<<endl;   

    
    return 0;
}