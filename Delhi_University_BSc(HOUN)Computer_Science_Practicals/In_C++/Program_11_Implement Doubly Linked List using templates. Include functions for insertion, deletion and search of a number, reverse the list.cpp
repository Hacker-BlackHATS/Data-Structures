// Objective : Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

// NODE CLASS
template<class T>class Node{
	public:
		Node<T>*next,*prev;
		T info;
	public:
		Node(){
			next = NULL;
			prev = NULL;
		}
		Node(T data){
			next = NULL;
			prev = NULL;
			info = data;
		}
};

// SINGLE LINKED LIST CLASS
template<class T>class DoubleLinkedList{
	public:
		Node<T>*start;
	public:
		// CONSTRUCTOR
		DoubleLinkedList(){
			start = NULL;
		}
		// DISPLAY LIST
		void display_list(){
			if (start == NULL){
				cout<<"List is empty!\n";
				return;
			}
			else{
				cout<<"List is : \n";
				Node<T>*p = start;
				while (p != NULL){
					cout<<p->info<<" ";
					p = p->next;
				}
				cout<<"\n";
			}
		}
		// INSERT IN BEGINNING
		void insert_in_beginning(T data){
			Node<T>*temp = new Node<T>(data);
			if(start == NULL){
				start = temp;
				return;
			}
			temp->next = start;
			start->prev = temp;
			start = temp;
		}
		// INSERT AT END
		void insert_at_end(T data){
			Node<T>*temp = new Node<T>(data);
			if(start == NULL){
				start = temp;
				return;
			}
			Node<T>*p = start;
			while(p->next != NULL){
				p = p->next;
			}
			p->next = temp;
			temp->prev = p;
		}
		// DELETE FROM START
		void delete_from_start(){
			if(start == NULL){
				cout<<"List is empty!!\n";
				return;
			}
			if(start->next == NULL){
				Node<T>*temp = start;
				start = NULL;
				free(temp);
			}
			else{
				Node<T>*temp = start;
				start = start->next;
				start->prev = NULL;
				free(temp);
			}
		}
		// DELETE FROM LAST
		void delete_from_last(){
			if(start == NULL){
				cout<<"List is empty!!!\n";
				return;
			}
			else if(start->next == NULL){
				Node<T>*temp = start;
				start = NULL;
				free(temp);
				return;
			}
			Node<T>*p = start;
			while(p->next != NULL){
				p = p->next;
			}
			Node<T>*temp = p;
			p->prev->next = NULL;
			free(temp);
		}
		// SEARCH A NODE
		void search_node(T data){
			int position = 1;
			Node<T>*p = start;
			while(p != NULL){
				if(p->info == data){
					cout<<"Element found at position "<<position<<"\n";
					return;
				}
				++position;
				p = p->next;
			}
			cout<<data<<" is not found in the list.\n";
			return;
		}
		// REVERSE LIST
		void reverse_list(){
			if(start == NULL){
				return;
			}
			Node<T>*p = start;
			Node<T>*q = p->next;
			p->next = NULL;
			p->prev = q;
			while(q != NULL){
				q->prev = q->next;
				q->next = p;
				p = q;
				q = q->prev;
			}
			start = p;
		}
		// MENU
		void menu(){
			char ch ='y';int op;
			do{
				cout<<"Enter Operation number to perform ::\n";
				cout<<"1.Insert at the beginning\n2.Insert at End\n3.Delete from start\n4.Delete from end\n5.Search Node\n6.Reverse List\n7.Display\n";
				cin>>op;
				switch(op){
					case 1:{
						T data;
						cout<<"Enter data : ";
						cin>>data;
						insert_in_beginning(data);
						break;
					}
					case 2:{
						T data;
						cout<<"Enter data : ";
						cin>>data;
						insert_at_end(data);
						break;
					}
					case 3:{
						delete_from_start();
						break;
					}
					case 4:{
						delete_from_last();
						break;
					}
					case 5:{
						T data;
						cout<<"Enter the element to search for : ";
						cin>>data;
						search_node(data);
						break;
					}
					case 6:{
						reverse_list();
						break;
					}
					case 7:{
						display_list();
						break;
					}
					default:{
						cout<<"Invalid Input!!!\n";
						break;
					}
				}
				cout<<"Do you want to continue?(y/n) : ";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
		}
};

// MAIN MENU
int main(){
	DoubleLinkedList<int>obj;
	obj.menu();
	getch();
	return 0;
}

