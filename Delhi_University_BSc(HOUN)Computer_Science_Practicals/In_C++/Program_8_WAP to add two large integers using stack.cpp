// Roll No. : 18/94089
// Objective : Add two large numbers with Stack.
#include<iostream>
#include<conio.h>
#include"Stack.cpp"
using namespace std;
int main(){
	string s1,s2,s3="";int i = 0,a,b,m = 0,c = 0;
	cout<<"Enter 1st number : ";
	cin>>s1;
	cout<<"Enter 2nd number : ";
	cin>>s2;
	Stack<int>obj1(s1.size());
	Stack<int>obj2(s2.size());
	Stack<int>obj3(s1.size()+s2.size());
	while(s1[i]!='\0'){
		obj1.push(s1[i]-48);i++;
	}
	i = 0;
	while(s2[i]!='\0'){
		obj2.push(s2[i]-48);i++;
	}
	while((obj1.top != -1)||(obj2.top != -1)){
		a = obj1.pop();
		b = obj2.pop();
		if(a == -1){
			a = 0;
		}
		if(b == -1){
			b = 0;
		}
		m = a + b + c;
		c = 0;
		if(m>=10){
			c = m/10;
			m = m% 10;
			obj3.push(m);
		}
		else{
			obj3.push(m);
		}
	}
	if(c!=0){
		obj3.push(c);c=0;
	}
	while(obj3.top != -1){
		s3 += obj3.pop() + 48;
	}
	cout<<"\n"<<"Sum of 1st and 2nd number is "<<s3<<"\n";
	getch();
	return 0;
}
