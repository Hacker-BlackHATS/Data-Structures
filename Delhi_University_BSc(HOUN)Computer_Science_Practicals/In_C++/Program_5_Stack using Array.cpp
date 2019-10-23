/*
	Objevtive : Perform the following Stack operations using Array implementation using Templates:
		    a) Push
		    b) Pop
		    c) Clear
*/
#include<iostream>
#include<conio.h>
using namespace std;
template<class T>class Stack{
	public:
		T *arr;
		int top,size;
	public:
		Stack(){
			size=5;
			arr = new T [size];
			top=-1;
		}
		Stack(int n){
			size=n;
			arr = new T [size];
			top=-1;
		}
		void push(T ele){
			if(top>=size-1){
				cout<<"Stack Overflow!!!\n";
			}
			else{
				arr[++top]=ele;
			}
		}
		T pop(){
			if(top<0){
				return -1;
			}
			else{
				return arr[top--];
			}
		}
		void clear(){
			top = -1;
			cout<<"Stack cleared!!!\n";
		}
		void display(){
			if(top<0){
				cout<<"Stack Underflow!!!\n";
				return;
			}
			else{
				cout<<"Stack is ::\n";
				for(int i=top;i>-1;i--){
					cout<<arr[i]<<"\n";
				}
			}
		}
		void menu(){
			char ch = 'y';
			int opt;
			do{
				cout<<"Enter the number of operation to perform ::\n";
				cout<<"1.PUSH\n2.POP\n3.CLEAR\n4.DISPLAY\n>>>>>>";
				cin>>opt;
				switch(opt){
					case 1:{
						T ele;
						cout<<"Enter the element to push : ";
						cin>>ele;
						push(ele);
						break;
					}
					case 2:{
						T pp = pop();
						if(pp != -1){
							cout<<"Popped element : "<<pp<<"\n";
						}
						else{
							cout<<"Stack Underflow!!!\n";
						}
						break;
					}
					case 3:{
						clear();
						break;
					}
					case 4:{
						display();
						break;
					}
					default:{
						cout<<"Invalid Input!!!\n";
					}

				}
				cout<<"Do you want to continue?(y/n) : ";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
		}
};

int main(){
	int n;
	cout<<"Enter the size of stack : ";
	cin>>n;
	Stack<char>obj(n);
	obj.menu();
	getch();
	return 0;
}
