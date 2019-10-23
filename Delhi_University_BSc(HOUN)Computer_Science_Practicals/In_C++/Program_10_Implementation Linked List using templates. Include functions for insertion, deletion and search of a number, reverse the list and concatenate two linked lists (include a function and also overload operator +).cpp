/*
	Objective : Implementation Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the 			    list and concatenate two linked lists (include a function and also overload operator +).
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

// NODE CLASS
template<class T>class Node{
	public:
		Node<T>*link;
		T info;
	public:
		Node(){
			link = NULL;
		}
		Node(T data){
			link = NULL;
			info = data;
		}
};

// SINGLE LINKED LIST CLASS
template<class T>class SingleLinkedList{
	public:
		Node<T>*start;
	public:
		// CONSTRUCTOR
		SingleLinkedList(){
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
					p = p->link;
				}
				cout<<"\n";
			}
		}
		void create(){
			int n;T temp;
			cout<<"Enter the number of nodes to enter : ";
			cin>>n;
			for(int i =0 ; i < n; i++){
				cout<<"Enter data : ";
				cin>>temp;
				insert_at_end(temp);
			}
		}
		// INSERT IN BEGINNING
		void insert_in_beginning(T data){
			Node<T>*temp = new Node<T>(data);
			if(start == NULL){
				start = temp;
				return;
			}
			temp->link = start;
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
			while(p->link != NULL){
				p = p->link;
			}
			p->link = temp;
		}
		// DELETE FROM START
		void delete_from_start(){
			if(start == NULL){
				cout<<"List is empty!!\n";
				return;
			}
			else{
				Node<T>*temp = start;
				start = start->link;
				free(temp);
			}
		}
		// DELETE FROM LAST
		void delete_from_last(){
			if(start == NULL){
				cout<<"List is empty!!!\n";
				return;
			}
			else if(start->link == NULL){
				Node<T>*temp = start;
				start = NULL;
				free(temp);
				return;
			}
			Node<T>*p = start;
			while(p->link->link != NULL){
				p = p->link;
			}
			Node<T>*temp = p->link;
			p->link = NULL;
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
				p = p->link;
			}
			cout<<data<<" is not found in the list.\n";
			return;
		}
		// REVERSE LIST
		void reverse_list(){
			Node<T>*prev = NULL;
			Node<T>*p = start;
			while(p != NULL){
				Node<T>*next = p->link;
				p->link = prev;
				prev = p;
				p = next;
			}
			start = prev;
		}
		// Merging by creating a new list (+ operator overloading)
		SingleLinkedList<T>operator+(SingleLinkedList <T>obj){
			SingleLinkedList<T>obj3;
			Node<T>*temp1 = start;
			while(temp1 != NULL){
				obj3.insert_at_end(temp1->info);
				temp1 = temp1->link;
			}
			Node<T>*temp2 = obj.start;
			while(temp2 != NULL){
				obj3.insert_at_end(temp2->info);
				temp2 = temp2->link;
			}
			return obj3;
		}
		// Merging by rearranging links (concatenation)
		void concatenate(SingleLinkedList<T>obj){
			if(start == NULL){
				start = obj.start;
				return;
			}
			else if(obj.start == NULL){
				return;
			}
			Node<T>*p = start;
			while(p->link != NULL){
				p = p->link;
			}
			p->link = obj.start;
		}
		// MENU
		void menu(){
			char ch ='y';int op;
			do{
				cout<<"Enter Operation number to perform ::\n";
				cout<<"1.Insert at the beginning\n2.Insert at End\n3.Delete from start\n4.Delete from end\n5.Search Node\n6.Reverse List\n7.Merge(+operator)\n8.Merge(Concatenate)\n9.Display\n";
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
						SingleLinkedList<T>obj2;
						cout<<"Enter data for 2nd list\n";
						obj2.create();
						SingleLinkedList<T>obj3 = *this + obj2;
						cout<<"New List :\n";
						obj3.display_list();
						break;
					}
					case 8:{
						SingleLinkedList<T>obj2;
						cout<<"Enter data for 2nd list\n";
						obj2.create();
						concatenate(obj2);
						break;
					}
					case 9:{
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
	SingleLinkedList<int>obj;
	obj.menu();
	return 0;
}

