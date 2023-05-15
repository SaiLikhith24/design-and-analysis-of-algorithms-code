 #include<iostream>
 using namespace std;
int m[50][50],s[50][50];

 void printlcs(int s[][50],int i,int j){
    if(i==j){
        cout<<"A"<<i;
        return;
    }
    else{
        cout<<"(";
        printlcs(s,i,s[i][j]);
        printlcs(s,s[i][j]+1,j);
        cout<<")";
    }
 }

 void mcm(int p[],int n){
    int q,j;
    for(int i=1;i<n;i++)
        m[i][i]=0;
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=9999;
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    /*cout<<"\n===============\n";
    for(int i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\n===============\n";
    for(int i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }*/
    printlcs(s,1,n);
 }

int main(){
    int n;
    cin>>n;
    int p[n+2];
    for(int i=1;i<=n;i++)
        cin>>p[i-1]>>p[i];
    mcm(p,n);
}