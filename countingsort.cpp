
#include<iostream>
using namespace std;

void countsort(int a[],int k,int n){
    int i,j;
    int c[k];                       //creating array c o size k
    int b[n];                       //creating array b of size n
    for(i=0;i<=k;i++)
        c[i]=0;                     //intializing c array with 0
    for(i=1;i<=n;i++)
        c[a[i]]=c[a[i]]+1;
    for(i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];           //adding present and next consecutive term of c and storing it back in c 
    for(j=n;j>=1;j--){
        b[c[a[j]]]=a[j];
        c[a[j]]=c[a[j]]-1;
    }
    cout<<"======SORTED ARRAY======\n";
    for(i=1;i<=n;i++)               //printing sorted array
        cout<<b[i]<<" ";
    cout<<" "<<endl;
}

int main(){
    int a[20];
    int n;
    cout<<"Enter size  ";           //taking input of size
    cin>>n;
    cout<<"Enter array elements \n";      
    for(int i=1;i<=n;i++)           //taking input for array elements
        cin>>a[i];
    int max=a[1];                   //finding maximum of array
    for(int i=1;i<=n;i++){
        if(a[i]>max)
            max=a[i];
    }
    countsort(a,max,n);             //calling countsort function
}