/* Objective : Write a menu driven program to implement the following sparse matrices using one-dimensional array:
		a) Diagonal Matrix
		b) Lower Triangular Matrix
		c) Upper Triangular Matrix
		d) Symmetric Matrix*/
#include<iostream>
#include<iomanip>

using namespace std;

class dia
{
	public:
		int *A;
		int size;
	public:
		dia(int x){
		    A=new int[x];
		    size=x;
		    for(int i=0; i<size; i++)
		        A[i]=0;
		}
		void set(int i, int j, int element){
		    if(i<0 || j<0 || i>size || j>size){
		        cout<<"\nOut of bounds!";
		    }
		    else{
		        if( i==j){
		            A[i-1]=element;
		        }
		    }
		}
		void chk(int i, int j){
		    if(i<0 || j<0 || i>size || j>size)
		    {
		        cout<<"\nOut of bounds!";
		    }
		    else{
		        if( i==j)
		            cout<<"\nValue= "<<A[i-1];
		        else
		            cout<<"Value= 0";
		    }
		}
		void disp(){
		    int i=0, j=0;
		    while(i!=size){
		        j=0;
		        while(j!=size)
		        {
		            if(i==j)
		                cout<<A[i]<<" ";
		            else
		                cout<<"0 ";
		            j++;
		        }
		        cout<<endl;
		        i++;
		    }
		}
    
};

class tri_dia{
    int *A;
    int size, mat_size;
    public:
    tri_dia(int x){
        A=new int[ (3*x)-2];
        size=(3*x)-2;
        mat_size=x;
        for(int i=0; i<size; i++)
            A[i]=0;
    }
    void set(int i, int j, int element){
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i==j+1)
                A[j-1]=element;
            else if( i==j)
                A[ (mat_size-1)+(i-1)]=element;
            else if(i==j-1)
                A[ ((2*mat_size)-1)+(i-1)]=element;
        }
    }
    void chk(int i, int j){
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i==j+1)
                cout<<"\nValue= "<<A[j-1];
            else if( i==j)
                cout<<"\nValue= "<<A[mat_size-1+i-1];
            else if(i==j-1)
                cout<<"\nValue= "<<A[2*mat_size-1+i-1];
            else
                cout<<"\nValue= 0";
        }
    }
    void disp(){
        int i=1, j=1;
        while(i<=mat_size){
            j=1;
            while(j<=mat_size){
                if(i==j+1)
                    cout<<A[j-1]<<" ";
                else if( i==j)
                    cout<<A[ (mat_size-1)+(i-1) ]<<" ";
                else if(i==j-1)
                    cout<<A[ (2*mat_size-1)+(i-1) ]<<" ";
                else
                    cout<<"0 ";
                j++;
            }cout<<endl;
            i++;
        }
    }
};

class low_tri{
    int *A;
    int size, mat_size;
    public:
        
    low_tri(int x){
        A=new int[ (x*(x+1))/2];
        size=(x*(x+1))/2;
        mat_size=x;
        for(int i=0; i<size; i++)
            A[i]=0;
    }
    void set(int i, int j, int element){
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i>=j)
                A[ (i*(i-1))/2+ (j-1)]=element;
        }
    }
    void chk(int i, int j){
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i>=j)
                cout<<"\nValue= "<<A[ (i*(i-1))/2+ (j-1)];
            else
                cout<<"\nValue= 0";
        }
    }
    void disp(){
        int i=1, j=1;
        while(i<=mat_size){
            j=1;
            while(j<=mat_size){
                if(i>=j)
                    cout<<A[ (i*(i-1))/2+ (j-1)]<<" ";
                else
                    cout<<"0 ";
                j++;
            }cout<<endl;
            i++;
        }
    }
};

class up_tri{
    int *A;
    int size, mat_size;
    public:
    up_tri(int x){
        A=new int[(x*(x+1))/2];
        size=(x*(x+1))/2;
        mat_size=x;
        for(int i=0; i<size; i++)
            A[i]=0;
    }  
    void set(int j, int i, int element){
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i>=j)
                A[ (i*(i-1))/2+ (j-1)]=element;
        }
    }
    void chk(int j, int i){
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i>=j)
                cout<<"\nValue= "<<A[ (i*(i-1))/2+ (j-1)];
            else
                cout<<"\nValue= 0";
        }
    }
    void disp(){
        int i=1, j=1;
        while(j<=mat_size){
            i=1;
            while(i<=mat_size){
                if(i>=j)
                    cout<<A[ (i*(i-1))/2+ (j-1)]<<" ";
                else
                    cout<<"0 ";
                i++;
            }cout<<endl;
            j++;
        }
    }
};

class sym{
    int *A;
    int size, mat_size;
    public:
    sym(int x){
        A=new int[ (x*(x+1))/2];
        size=(x*(x+1))/2;
        mat_size=x;
        for(int i=0; i<size; i++)
            A[i]=0;
    }
    
    void set(int i, int j, int element)
    {
        if(i<0 || j<0 || i>mat_size || j>mat_size)
        {
            cout<<"\nOut of bounds!";
        }
        else
        {
            if(i>=j)
                A[ (i*(i-1))/2+ (j-1)]=element;
        }
    }
    
    void chk(int i, int j)
    {
        if(i<0 || j<0 || i>mat_size || j>mat_size){
            cout<<"\nOut of bounds!";
        }
        else{
            if(i>=j)
                cout<<"\nValue= "<<A[ (i*(i-1))/2+ (j-1)];
            else if(i<j){
                swap(i,j);
                cout<<"\nValue= "<<A[ (i*(i-1))/2+ (j-1)];
            }
            else
                cout<<"\nValue= 0";
        }
    }
    void disp(){
        int i=1, j=1;
        while(i<=mat_size){
            j=1;
            while(j<=mat_size){
                if(i>=j)
                    cout<<setw(2)<<A[ (i*(i-1))/2+ (j-1)]<<" ";
                else if(i<j){
                    swap(i,j);
                    cout<<setw(2)<<A[ (i*(i-1))/2+ (j-1)]<<" ";
                    swap(i,j);
                }
                else
                    cout<<setw(2)<<"0";
                j++;
            }cout<<endl;
            i++;
        }
    }
};

int main()
{
    int num,size,num2,i,j,element;
    char ch;
    cout<<"\nEnter matrix size: ";
    cin>>size;
    dia ob(size);
    tri_dia ob1(size);
    low_tri ob2(size);
    up_tri ob3(size);
    sym ob4(size);
    do
    {
        cout<<"\n**********MENU**************";
        cout<<"\n1. Diagonal matrix.";
        cout<<"\n2. Tri-Diagonal matrix.";
        cout<<"\n3. Lower-Diagonal matrix.";
        cout<<"\n4. Upper-Diagonal matrix.";
        cout<<"\n5. Symmetric matrix.";
        cout<<"\n6. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>num;   
        switch(num)
        {
            case 1:	do
                {
                    cout<<"\n1. Insert element.";
                    cout<<"\n2. check any element.";
                    cout<<"\n3. display matrix.";
                    cout<<"\nEnter your choice: ";
                    cin>>num2;
                    
                    switch(num2)
                    {
                        
                        case 1:	cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                cout<<"\n\tEnter element value: ";
                                cin>>element;
                                ob.set(i,j,element);
                                break;
                        case 2: cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                ob.chk(i,j);
                                break;
                        case 3: ob.disp();
                                break;
                        default:cout<<"\nWrong input";
                                break;
                    }
                    cout<<"\n\n\tEnter again(y/n): ";
                    cin>>ch;
                }while(ch=='y');
                break;
        
            case 2:	do
                {
                    cout<<"\n1. Insert element.";
                    cout<<"\n2. check any element.";
                    cout<<"\n3. display matrix.";
                    cout<<"\nEnter your choice: ";
                    cin>>num2;
                    
                    switch(num2)
                    {
                        
                        case 1:	cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                cout<<"\n\tEnter element value: ";
                                cin>>element;
                                ob1.set(i,j,element);
                                break;
                        case 2: cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                ob1.chk(i,j);
                                break;
                        case 3: ob1.disp();
                                break;
                        default:cout<<"\n\tWrong input";
                                break;
                    }
                    cout<<"\n\n\tEnter again(y/n): ";
                    cin>>ch;
                }while(ch=='y');
                break;
        
            case 3:	do
                {
                    cout<<"\n1. Insert element.";
                    cout<<"\n2. check any element.";
                    cout<<"\n3. display matrix.";
                    cout<<"\nEnter your choice: ";
                    cin>>num2;
                    
                    switch(num2)
                    {
                        
                        case 1:	cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                cout<<"\n\tEnter element value: ";
                                cin>>element;
                                ob2.set(i,j,element);
                                break;
                        case 2: cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                ob2.chk(i,j);
                                break;
                        case 3: ob2.disp();
                                break;
                        default:cout<<"\n\tWrong input";
                                break;
                    }
                    cout<<"\n\n\tEnter again(y/n): ";
                    cin>>ch;
                }while(ch=='y');
                break;
        
            case 4: do
                {
                    cout<<"\n1. Insert element.";
                    cout<<"\n2. check any element.";
                    cout<<"\n3. display matrix.";
                    cout<<"\nEnter your choice: ";
                    cin>>num2;
                    
                    switch(num2)
                    {
                        
                        case 1:	cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                cout<<"\n\tEnter element value: ";
                                cin>>element;
                                ob3.set(i,j,element);
                                break;
                        case 2: cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                ob3.chk(i,j);
                                break;
                        case 3: ob3.disp();
                                break;
                        default:cout<<"\tWrong input";
                                break;
                    }
                    cout<<"\n\tEnter again(y/n): ";
                    cin>>ch;
                }while(ch=='y');
                break;
        
            case 5: do
                {
                    cout<<"\n1. Insert element.";
                    cout<<"\n2. check any element.";
                    cout<<"\n3. display matrix.";
                    cout<<"\nEnter your choice: ";
                    cin>>num2;
                    
                    switch(num2)
                    {
                        
                        case 1:	cout<<"\nEnter only lower triangular matrix elements:-\n";
                                cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                cout<<"\n\tEnter element value: ";
                                cin>>element;
                                ob4.set(i,j,element);
                                break;
                        case 2: cout<<"\n\tEnter row(i): ";
                                cin>>i;
                                cout<<"\n\tEnter column(j): ";
                                cin>>j;
                                ob4.chk(i,j);
                                break;
                        case 3: ob4.disp();
                                break;
                        default:cout<<"\n\tWrong input";
                                break;
                    }
                    cout<<"\n\n\tEnter again(y/n): ";
                    cin>>ch;
                }while(ch=='y');
                break;
            case 6: cout<<"\nEXITING...";
                    exit(100);
                    break;
            default:cout<<"\nWrong Input!!!";
                    break;
        }
        cout<<"\n\nChoose different matrix(y/n): ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
    return 0;
}
