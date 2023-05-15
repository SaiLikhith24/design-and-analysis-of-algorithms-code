#include<iostream>
using namespace std;

int partition(int a[],int p,int r){
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quicksort(int a[],int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main(){
    int n,a[20];
    cout<<"Enter size ";
    cin>>n;
    cout<<"Enter elements ";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    quicksort(a,1,n);
    cout<<"==========\n";
    cout<<"SORTED ARRAY: ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

}