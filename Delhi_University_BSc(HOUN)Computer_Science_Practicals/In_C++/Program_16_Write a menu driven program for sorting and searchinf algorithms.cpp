/*
Objective : Write a menu driven program to implement the following sorting and searching algorithms:
		a) Bubble Sort
		b) Insertion
		c) Selection
		d) Merge Sort
		e) Quick Sort
		f) Linear Search
		g) Binary Search
*/
#include<iostream>

using namespace std;


class algos{
	public:
		int size;
		int *arr;
	
	public:
		algos(){
			size = 0;
			arr = new int[size];
		}
		
		void input(){
			cout<<"Enter the size of list : ";
			cin>>size;
			arr = new int[size];
			cout<<"Enter the elements of the list ::\n";
			for(int i = 0 ; i < size; i++){
				cin>>arr[i];
			}
		}
		
		void display(){
			cout<<"List after sorting ::\n";
			for(int i = 0 ; i < size; i++){
				cout<<arr[i]<<" ";
			}cout<<endl;
		}
		
		void bubble_sort(){
			for(int i = size-1; i > -1; i--){
				for(int j = 0; j < i; j++){
					if(arr[j] > arr[j+1]){
						int temp = arr[j+1];
						arr[j+1] = arr[j];
						arr[j] = temp;
					}
				}
			}
			display();
		}
		
		void insertion_sort(){
			for(int i = 1; i < size; i++){
				int temp = arr[i];
				int j = i-1;
				while(j >= 0 && arr[j] > temp){
					arr[j+1] = arr[j];
					j--;
				}
				arr[j+1] = temp;
			}
			display();
		}
		
		void selection_sort(){
			for(int i = 0; i < size-1; i++){
				int imin = i;
				for(int j = i+1; j < size; j++){
					if(arr[j] < arr[imin]){
						imin = j;
					}
				}
				if(i != imin){
					int temp = arr[i];
					arr[i] = arr[imin];
					arr[imin] = temp;
				}
			}
			display();
		}
		
		void merge_sort(){
			int *temp = new int[size];
			sort(temp, 0, size-1);
		}
		
		void sort(int *temp, int low, int up){
			if(low == up){
				return;
			}
			int mid = (low+up)/2;
			sort(temp, low, mid);
			sort(temp, mid+1, up);
			merge(temp, low, mid, mid+1, up);
			copy(temp, low, up);	
		}
		
		void merge(int *temp, int low1, int up1, int low2, int up2){
			int k = low1;
			while(low1 <= up1 && low2 <= up2){
				if(arr[low1] < arr[low2]){
					temp[k] = arr[low1];
					low1++;
				}
				else{
					temp[k] = arr[low2];
					low2++;
				}
				k++;
			}
			while(low1 <= up1){
				temp[k] = arr[low1];
					low1++;k++;
			}
			while(low2 <= up2){
				temp[k] = arr[low2];
					low2++;k++;
			}
		}
		
		void copy(int *temp, int low, int up){
			for(int i = low; i<= up; i++){
				arr[i] = temp[i];
			}
		}
		
		void quick_sort(){
			sort2(0, size-1);
			display();
		}
		
		void sort2(int low, int up){
			if(low >= up){
				return;
			}
			int p = partition(low, up);
			sort2(low, p-1);
			sort2(p+1, up);
		}
		
		int partition(int low, int up){
			int pivot = arr[low];
			int i = low+1;
			int j = up;
			while(i <= j){
				while((arr[i] < pivot)&&(i < j)){
					i++;
				}
				while(arr[j] > pivot){
					j--;
				}
				if(i < j){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					i++;
					j--;
				}
				else{
					break;
				}
			}
			arr[low] = arr[j];
			arr[j] = pivot;
			return j;
		}
		
		int linear_search(int ele){
			for(int i = 0; i < size; i++){
				if(arr[i] == ele){
					return i;
				}
			}
			return -1;
		}
		
		int binary_search(int ele){
			quick_sort();
			int l = 0;int r = size-1;
			while(l <= r){
				int mid = (l+r)/2;
				if(arr[mid] == ele){
					return mid;
				}
				else if(arr[mid] < ele){
					l = mid+1;
				}
				else{
					r = mid-1;
				}
			}
			return -1;			
		}
		
		void menu(){
			char ch, datc; int opt;
			input();
			do{
				cout<<"Enter the operation number to perform ::\n";
				cout<<"1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n";
				cout<<"6. Linear Search\n7. Binary Search\n";
				cin>>opt;
				switch(opt){
					case 1:{
						bubble_sort();
						break;
					}
					case 2:{
						insertion_sort();
						break;
					}
					case 3:{
						selection_sort();
						break;
					}
					case 4:{
						merge_sort();
						display();
						break;
					}
					case 5:{
						quick_sort();
						break;
					}
					case 6:{
						int n;
						cout<<"Enter element to search : ";
						cin>>n;
						int ans = linear_search(n);
						if(ans == -1){
							cout<<"Element not found!!!\n";
						}
						else{
							cout<<"Element is at position "<<ans+1<<endl;
						}
						break;
					}
					case 7:{
						int n;
						cout<<"Enter element to search : ";
						cin>>n;
						int ans = binary_search(n);
						if(ans == -1){
							cout<<"Element not found!!!\n";
						}
						else{
							cout<<"Element is at position "<<ans+1<<endl;
						}
						break;
					}
					default:{
						cout<<"Wrong Option...\n";
					}
				}cout<<"Do you want to continue?(y/n) : ";
				cin>>ch;
				if(ch == 'Y' || ch == 'y'){
					cout<<"Do you want to re-enter data?(y/n) : ";
					cin>>datc;
					if(datc == 'Y' || datc == 'y'){
						input();
					}
				}
			}while(ch == 'Y' || ch == 'y');
		}
};


int main(){
	algos obj;
	obj.menu();
	return 0;
}

