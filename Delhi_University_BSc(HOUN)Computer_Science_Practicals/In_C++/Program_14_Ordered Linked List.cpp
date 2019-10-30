/*
	Objective : Write a menu driven program to implement the following operations in an ordered linked list:
		    a) Insertion
		    b) Deletion
		    c) Merging
*/
#include<iostream>
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
template<class T>class OLL{
	public:
		Node<T>*start;
	public:
		OLL(){
			start = NULL;
		}
		bool isEmpty(){
			return start == NULL;
		}
		void Insertion(T data){
			Node<T>*temp = new Node<T>(data);
			if(isEmpty() || data < start->info){
				temp->link = start;
				start = temp;
				return;
			}
			Node<T>*p = start;
			while(p->link != NULL && p->link->info <= data){
				p = p->link;
			}
			temp->link = p->link;
			p->link = temp;
		}
		void Deletion(T ele){
			if(isEmpty()){
				cout<<"List is empty, can't delete...\n";
				return;
			}
			if(start->info == ele){
				Node<T>*temp = start;
				start = start->link;
				cout<<"Deleted element : "<<temp->info<<endl;
				free(temp);
				return;
			}
			Node<T>*p = start;
			while(p->link != NULL && ele > p->link->info){
				p = p->link;
			}
			if(p->link == NULL){
				cout<<"Element "<<ele<<" is not in the list.\n";
			}
			else{
				Node<T>*temp = p->link;
				p->link = p->link->link;
				cout<<"Deleted element : "<<temp->info<<endl;
				free(temp);
			}
						
		}
		void create_list(){
			int n;T temp;
			cout<<"Enter the number of elements to enter : ";
			cin>>n;
			for(int i =0 ; i < n; i++){
				cout<<"Enter data : ";
				cin>>temp;
				Insertion(temp);
			}
		}
		void Merging(OLL obj){
			Node<T>*p1 = start;
			Node<T>*p2 = obj.start;
			Node<T>*startM = NULL;
			if(p1->info <= p2->info){
				startM = p1;
				p1 = p1->link;
			}
			else{
				startM = p2;
				p2 = p2->link;
			}
			Node<T>*pM = startM;
			while(p1 != NULL && p2 != NULL)
				if(p1->info <= p2->info){
					pM->link = p1;
					p1 = p1->link;
				}
				else{
					pM->link = p2;
					p2 = p2->link;
				}
				pM = pM->link;
			if (p1 != NULL){
				pM->link = p2;
			}
			else{
				pM->link = p1;
			}
			start = startM;
		}
		void Display(){
			if(isEmpty()){
				cout<<"List is empty....\n";
				return;
			}
			cout<<"List ::\n";
			Node<T>*p = start;
			while(p != NULL){
				cout<<p->info<<" ";
				p = p->link;
			}cout<<endl;
		}
		void Menu(){
			char ch;int option;
			do{
				cout<<"Enter the operation number to perform ::\n";
				cout<<"<1> Insertion\n<2> Deletion\n<3> Merging\n<4> Display\n";
				cin>>option;
				switch(option){
					case 1:{
						T ele;
						cout<<"Enter the element to insert : ";
						cin>>ele;
						Insertion(ele);
						break;
					}
					case 2:{
						T ele;
						cout<<"Enter the element to delete : ";
						cin>>ele;
						Deletion(ele);
						break;
					}
					case 3:{
						OLL<T>obj2;
						cout<<"Enter data for 2nd list ::\n";
						obj2.create_list();
						Merging(obj2);
						break;
					}
					case 4:{
						Display();
						break;
					}
					default:{
						cout<<"Invalide Input!!!\n";
					}
				}
				cout<<"Do you want to continue?(y/n) : ";
				cin>>ch;
			}while(ch == 'y' || ch == 'Y');
		}
};
int main(){
	OLL<int>obj;
	obj.Menu();
	return 0;
}
