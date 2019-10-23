//Roll no. : 18/94089
//Objective : WAP to compute b^r using recursion where b represents base and r represents power.
#include <iostream>
#include<conio.h>
using namespace std;
double po(double b, int r){
    if(r==0){
        return 1;
    }
    else if(r<0){
        return (1/b)*po(b,r+1);
    }
    else{
        return b*po(b,r-1);
    }
}

int main()
{
    double b;int r;
    cout<<"Enter value of base : ";
    cin>>b;
    cout<<"Enter value of power : ";
    cin>>r;
    cout<<"Answer is "<<po(b,r);
    getch();
    return 0;
}
