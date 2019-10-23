/* 	Objective : Implement Circular Linked List using templates. Include functions for insertion, deletion and search of a number,
		    reverse the list.
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
		}
		Node(T data){
			link = NULL;
			info = data;
		}
};
template<class T>class CircularSLinkedList{
	public:
		Node<T>*last;
	public:
		CircularSLinkedList(){
			last = NULL;
		}
		void display_list(){
			if (last == NULL){
				cout<<"List is empty!\n";
				return;
			}
			cout<<"List is : \n";
			Node<T>*p = last->link;
			while (true){
				cout<<p->info<<" ";
				p = p->link;
				if(p == last->link){
					break;
				}
			}cout<<"\n";
		}
		void insert_in_beginning(T data){
			Node<T>*temp = new Node<T>(data);
			if(last == NULL){
				last = temp;
				last->link = last;
				return;
			}
			temp->link = last->link;
			last->link = temp;
		}
		void insert_at_end(T data){
			Node<T>*temp = new Node<T>(data);
			if(last == NULL){
				last = temp;
				last->link = last;
				return;
			}
			temp->link = last->link;
			last->link = temp;
			last = temp;
		}
		void delete_from_start(){
			if(last == NULL){
				cout<<"List is empty!!\n";
				return;
			}
			else if(last->link == last){
				Node<T>*temp = last;
				last = NULL;
				T a = temp->info;
				free(temp);
				cout<<"Element deleted : "<<a<<endl;
				return;
			}
			Node<T>*temp = last->link;
			last->link = last->link->link;
			free(temp);
		}
		// DELETE FROM LAST
		void delete_from_last(){
			if(last == NULL){
				cout<<"List is empty!!\n";
				return;
			}
			else if(last->link == last){
				Node<T>*temp = last;
				last = NULL;
				free(temp);
				return;
			}
			Node<T>*p = last->link;
			while(p->link != last){
				p = p->link;
			}
			Node<T>*temp = last;
			p->link = last->link;
			last = p;
			free(temp);
		}
		void search_node(T data){
			int position = 1;
			Node<T>*p = last->link;
			while(true){
				if(p->info == data){
					cout<<"Element found at position "<<position<<"\n";
					return;
				}
				++position;
				p = p->link;
				if(p == last->link){
					cout<<data<<" is not found in the list.\n";
					return;
				}
			}
		}
		void reverse_list(){
			Node<T>*p = last->link;
			Node<T>*prev = NULL;
			Node<T>*k = p;
			while(true){
				Node<T>*next = p->link;
				p->link = prev;
				prev = p;
				p = next;
				if(prev == last){
					break;
				}
			}
			k->link = prev;
			last = k;
		}
		void alternate(){
			Node<T>*p = last->link;int count = 0, a = rand() % 2;
			cout<<"Alternate elements are :\n";
			while(true){
				if(a==0){
					if(count % 2 ==0){
						cout<<p->info<<" ";
					}
				}
				else{
					if(count % 2 !=0){
						cout<<p->info<<" ";
					}
				}
				count++;
				p = p->link;
				if(p == last->link){
					break;
				}
			}cout<<endl;
		}
		void menu(){
			char ch ='y';int op;
			do{
				cout<<"Enter Operation number to perform ::\n";
				cout<<"1.Insert at the beginning\n2.Insert at End\n3.Delete from start\n4.Delete from end\n5.Search Node\n6.Reverse List\n7.Alternate Elements\n8.Display\n";
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
						alternate();
						break;
					}
					case 8:{
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

int main(){
	CircularSLinkedList<int>obj;
	obj.menu();
	getch();
	return 0;
}
