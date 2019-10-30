/*
	Objective : WAP to evaluate postfix expressions using stack.
*/
#include<iostream>
#include"Program_4_Stack using Linked List.cpp"
using namespace std;
int evaluation(string exp){
	Stack<int>obj;
	int i =0;
	while(exp[i] != '\0'){
		if(isdigit(exp[i])){
			obj.push(exp[i]-48);i++;
		}
		else{
			int x = obj.pop();
			int y = obj.pop();
			if(exp[i] == '+'){obj.push(y + x);}
			else if(exp[i] == '-'){obj.push(y - x);}
			else if(exp[i] == '*'){obj.push(y * x);}
			else if(exp[i] == '/'){obj.push(y / x);}
			else if(exp[i] == '%'){obj.push(y % x);}
			else if(exp[i] == '^'){obj.push(y * x * x);}
			i++;
		}
	}
	return obj.pop();
}
int main(){
	string expression;
	cout<<"Enter a Postfix expression : ";
	cin>>expression;
	int ans = evaluation(expression);
	cout<<"Answer after evaluation of Postfix expression is : "<<ans<<endl;
	return 0;
}
