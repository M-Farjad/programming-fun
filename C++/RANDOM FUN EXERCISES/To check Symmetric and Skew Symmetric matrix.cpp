/*
Symmetric Matrix :          If transpose of Matrix A is equal to the same 
                            Matrix then it is symmetric matrix

Skew Symmetric Matrix :     If negative of transpose of Matrix a is equal to the
                            same Matrix then it is skew symmetric matrix

****CONDITION**** 
MATRIX MUST BE A SQUARE MATRIX
*/

#include<iostream>
using namespace std;

int main(){
    int A[3][3] ,               //matrix to be checked
        T[3][3] ,               //matrix to check symmetric
        NT[3][3] ;              //matrix to check skew  symmetric
    bool symmetric = 1 ,     
         skewSymmetric = 1;     //both set to true

    //Taking Input for Matrix
    for(int i = 0; i<3 ; i++){
        for(int j = 0; j<3 ; j++){
            cout<<"Enter number for ["<<i<<"]["<<j<<"]";
            cin>>A[i][j];
        }
    }
    //Printing Matrix 
    cout<<endl<<"Matrix is: "<<endl;
    for(int i = 0; i<3 ; i++){
        for(int j = 0; j<3 ; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }

    //Taking Transpose of Matrix   (for symmetric)
    for(int i = 0; i<3 ; i++){
        for(int j = 0; j<3 ; j++){
            T[i][j] = A[j][i];
        }
        cout<<endl;
    }

    //Taking Negative of Transpose of Matrix (for skew symmetric)
    for(int i = 0; i<3 ; i++){
        for(int j = 0; j<3 ; j++){
            NT[i][j] = A[j][i];
        }
        cout<<endl;
    }

    //Checking For Symmetric
    for(int i = 0; i<3 ; i++){
        for(int j = 0; j<3 ; j++){
            if( T[i][j] != A[i][j] )
            {
                symmetric = 0;   
                break;
            }
        }
    }
    if(symmetric == 0){
        cout<<endl<<"Not a Symmetric Matrix. "<<endl;
    }
    else{
        cout<<endl<<"The Matrix is Symmetric. "<<endl;
    }

    //Checking For Skew Symmetric
    for(int i = 0; i<3 ; i++){
        for(int j = 0; j<3 ; j++){
            if( NT[i][j] != A[i][j] )
            {
                skewSymmetric = 0;   
                break;
            }
        }
    }
    if(skewSymmetric == 0){
        cout<<endl<<"Not a Skew Symmetric Matrix. "<<endl;
    }
    else{
        cout<<endl<<"The Matrix is Symmetric. "<<endl;
    }

    return 0;
}
