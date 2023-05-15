#include<iostream>
#include<math.h>
using namespace std;

void count(int a[],int g[],int k,int n){
    int c[k],b[n];
    for(int i=0;i<=k;i++)
        c[i]=0;
    for(int j=1;j<=n;j++)
        c[g[j]]=c[g[j]]+1;
    for(int i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];
    for(int j=n;j>=1;j--){
        b[c[g[j]]]=a[j];
        c[g[j]]=c[g[j]]-1;
    }
    for(int k=1;k<=n;k++)
        a[k]=b[k];
    cout<<endl;
}

int main(){
    int d,n,a[20],g[20];
    cout<<"Enter size ";
    cin>>n;
    cout<<"Enter number of digits ";
    cin>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int max=a[1];
    for(int i=2;i<=n;i++)   
        if(a[i]>max)
            max=a[i];
    cout<<"==========\n";
    for(int i=1;i<=d;i++){
        for(int j=1;j<=n;j++){
            g[j]=(int(a[j]/pow(10,i-1)))%10;
        }
        count(a,g,max,n);
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

}