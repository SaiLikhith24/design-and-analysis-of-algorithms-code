#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1];
    int R[n2+1];
    int i;
    int j;
    for(i=1;i<=n1;i++)
        L[i]=a[p+i-1];
    for(j=1;j<=n2;j++)
        R[j]=a[q+j];
    L[n1+1]=9999;
    R[n2+1]=9999;
    i=1;j=1;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else {
            a[k]=R[j];
            j++;
        }
    }
  }

void mergesort(int a[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}


int main(){
    int a[10];
    int n;
    cout<<"Enter size ";
    cin>>n;
    cout<<"enter elements \n";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mergesort(a,1,n);
    cout<<"Sorted array ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";        
}