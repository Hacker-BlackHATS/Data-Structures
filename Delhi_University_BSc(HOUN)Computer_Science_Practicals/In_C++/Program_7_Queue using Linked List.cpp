/*
	Objective : Create and perform the following operations on Queues using Linked List implementation:
		    a) Enqueue
		    b) Dequeue

*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template<class T>class Node{
	public:
		Node<T>*link;
		T info;
	public:
		Node(){
			link = NULL;
			info = 0;
		}
		Node(int data){
			link = NULL;
			info = data;
		}
};
template<class T>class LQueue{
	public:
		Node<T>*rear;
		Node<T>*front;
	public:
		LQueue(){
			rear = NULL;
			front = NULL;
		}
		bool isEmpty(){
			return front == NULL;
		}
		void Enqueue(T x){
			Node<T>*temp = new Node<T>(x);
			if(front == NULL){
				front = temp;
			}
			else{
				rear->link = temp;
			}
			rear = temp;
		}
		void Dequeue(){
			if(isEmpty()){
				cout<<"Queue is empty..\n";
				return;
			}
			Node<T>*x = front;
			cout<<"Element deleted : "<<x->info<<endl;
			front = front->link;
			free(x);
			return;
		}
		void Peek(){
			if(isEmpty()){
				cout<<"Queue is empty..\n";
				return;
			}
			cout<<"Element at top : "<<front->info<<endl;
			return;
		}
		void Clear(){
			while(!isEmpty()){
				Dequeue();
			}
		}
		void Display(){
			if(isEmpty()){
				cout<<"Queue is empty..\n";
				return;
			}
			Node<T>*p = front;
			while(p != NULL){
				cout<<p->info<<" ";
				p = p->link;
			}cout<<endl;
		}
		void Menu(){
			char ch = 'Y'; int op;
			while(ch == 'Y' || ch == 'y'){
				cout<<"Enter operation number ::\n";
				cout<<"<1> Enqueue\n<2> Dequeue\n<3> Peek\n<4> Clear\n<5> Display\n";
				cin>>op;
				switch(op){
					case 1:{
						T ele;
						cout<<"Enter element to insert : ";cin>>ele;
						Enqueue(ele);
						break;
					}
					case 2:{
						Dequeue();
						break;
					}
					case 3:{
						Peek();
						break;
					}
					case 4:{
						Clear();
						break;
					}
					case 5:{
						Display();
						break;
					}
					default:{
						cout<<"INVALID INPUT!!!/n";
					}
				}
				cout<<"Do you want to continue?(y/n) : ";
				cin>>ch;
			}
		}

};
int main(){
	LQueue<int>obj;
	obj.Menu();
	getch();
	return 0;
}
