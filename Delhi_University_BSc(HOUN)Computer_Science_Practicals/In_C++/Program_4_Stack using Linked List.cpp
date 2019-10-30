/*
	Objective :  Perform the following Stack operations using Linked List implementation.
		    a) Push
		    b) Pop
		    c) Clear
*/
#include<iostream>
#include"Program_10_Implementation Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list and concatenate two linked lists (include a function and also overload operator +).cpp"
using namespace std;
template<class T>class Stack{
	public:
		SingleLinkedList<T>top;
	public:
		Stack(){
			top.start = NULL;
		}
		void push(T ele){
			top.insert_in_beginning(ele);
		}
		T pop(){
			top.delete_from_start();
		}
		void clear(){
			while(top.start != NULL){
				top.delete_from_start();
			}
			cout<<"Stack cleared!!!\n";
		}
		void display(){
			top.display_list();
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
						T x = pop();
						if(x == 0){
							cout<<"Stack is empty...\n";
						}
						else{
							cout<<"Popped element is "<<x<<endl;
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
	Stack<int>obj;
	obj.menu();
	return 0;
}
