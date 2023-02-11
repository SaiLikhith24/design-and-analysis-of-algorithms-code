#include<iostream>
using namespace std;

struct type{
    int low,high,sum;
};

type fmcsa(int a[],int low,int mid,int high){
    int i=0,j=0,sum,leftsum,rightsum,maxleft,maxright;
    leftsum=-999;
    sum=0;
    for(i=mid;i>=low;i--){
        sum+=a[i];
        if(sum>leftsum){
            leftsum=sum;
            maxleft=i;
        }
    }
    rightsum=-999;
    sum=0;
    for(j=mid+1;j<=high;j++){
        sum+=a[j];
            if(sum>rightsum){
                rightsum=sum;
                maxright=j;
            }
    }
    type s1={maxleft,maxright,leftsum+rightsum};
    return s1;
}

type fms(int a[],int low,int high){
    int mid;
    type left,right,cross;
    
    if(low==high){
        type x={low,high,a[low]};
        return x;
    }
    else{
        mid=(low+high)/2;
        left=fms(a,low,mid);
        right=fms(a,mid+1,high);
        cross=fmcsa(a,low,mid,high);

        if(left.sum>=right.sum && left.sum>=cross.sum)
                    return left;
        else if(right.sum>=left.sum && right.sum>=cross.sum)
                    return right;
        else
                    return cross;
                    
    }
}

int main(){
    int a[10];
    int n;
    cout<<"Enter size ";cin>>n;
    cout<<"Ener array elements ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    type result=fms(a,1,n);
    cout<<":::::::::::::::\nLOW  ="<<result.low<<endl;
    cout<<"HIGH ="<<result.high<<endl;
    cout<<"SUM  ="<<result.sum<<endl;
}