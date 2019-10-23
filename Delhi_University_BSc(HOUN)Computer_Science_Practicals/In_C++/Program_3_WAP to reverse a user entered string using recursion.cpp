//Objective : WAP to reverse a user entered string using recursion.
#include <iostream>
#include<conio.h>
using namespace std;
string rev(string s,int i, int j){
    if((i==j)||(j<i)){
        return s;
    }
    else{
        char c = s[i];
        s[i]=s[j];
        s[j]=c;
        return rev(s,++i,--j);
    }
}
int main()
{
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    cout<<"String in reverse : "<<rev(s,0,s.length()-1);
    getch();
    return 0;
}
