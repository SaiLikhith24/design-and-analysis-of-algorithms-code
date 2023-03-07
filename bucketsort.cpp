#include<iostream>
using namespace std;

struct node{
    double data;
    node* link;
};


node* insertnode(double n){
    node* pnew =new node;
    pnew->data=n;
    pnew->link=NULL;
    return pnew;
}

void display(double a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
    //cout<<endl;
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void insertionsort(double a[],int n){
    double value;
    int hole;
    for(int i=1;i<n;i++){
        value=a[i];
        hole=i;
        while(hole>0 && a[hole-1]>value){
            swap(a[hole],a[hole-1]);
            hole--;
        }
    }
    
}
void bucketsort(double a[],int n){
    node* b[10];
    node* pred=new node;
    for(int i=0;i<n;i++)
        b[i]=NULL;
    for(int i=0;i<n;i++){
        int temp=n*a[i];
        if(b[temp]==NULL){
            b[temp]=insertnode(a[i]);
        }
        else{
           pred=b[temp];
           while(pred->link!=NULL){
                pred=pred->link;
           }
            pred->link=insertnode(a[i]);
        }
    }
    int j=0;
    cout<<"\n===== AFTER SORTING =====\n";
    while(j<n){
        double arr[10];
        int i=0;
        node* temp=new node;
        temp=b[j];
        while(temp!=NULL){
            arr[i]=temp->data;i++;
            temp=temp->link;
        }
        insertionsort(arr,i);
        display(arr,i);
        j++;
    }
}



int main(){
    double a[20];
    int n;
    cout<<"Enter size ";
    cin>>n;
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    bucketsort(a,n);
}
