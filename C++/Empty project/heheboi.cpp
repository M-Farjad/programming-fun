// #include <stdio.h>
// #include <conio.h>
// int main()
// {
//     int a, b, c, d;
//     printf("Enter 1st number");
//     scanf("%d", &a);
//     printf("Enter 2nd number");
//     scanf("%d", &b);
//     printf("Enter 3rd num");
//     scanf("%d", &c);
//     printf("Enter 4th num");
//     scanf("%d", &d);
//     if (a > b && a > c && a > d)
//         printf("\t a is greatest");
//     else if (b > a && b > c && b > d)
//         printf("\tb is greatest");
//     else if (b > a && b > c && b > d)
//         printf("\t b is greatest");
//     else if (c > a && c > b && c > d)
//         printf("\t c is greatest");
//     else 
//         printf("d is greatest");
//     return 0;
// }



#include<iostream>
using namespace std;

int main(){

    int k=2;
    int j=0;
    for (int i = 4; i >= 1; i--)
    {
        for(j=k-1;j<=i;j++){
            cout<<j;
        }
        cout<<"\n";
        k=j;
    }
    return 0;
}