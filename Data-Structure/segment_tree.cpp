#include<bits/stdc++.h>
using namespace std;

const int N =100000+10;
int n;
int a[N];
int t[4*N];
void build(int node,int b,int e){
    if(b==e){
        t[node]=a[b];
        return ;
    }
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    build(left,b,mid);
    build(right,mid+1,e);
    t[node]=min(t[left],t[right]);
}
int query(int node,int b,int e,int i,int j){
    if(i>e||j<b)return N;
    if(b>=i&&e<=j)return t[node];
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}
void update(int node,int b,int e,int i,int newvalue){
    if(i>e||i<b)return ;
    if(b>=i&&e<=i){
        t[node]=newvalue;
        return;
    }
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    t[node]=min(t[left],t[right]);
}
int main(){
    int l,r,i;
    //scanf("%d",&n);
    n=5;
    for(i=0;i<n;i++)scanf("%d",a+i);
    build(0,0,n-1);
    printf("%d\n",query(0,0,n-1,0,1));
    update(0,0,n-1,1,0);
    printf("%d\n",query(0,0,n-1,0,1));
    return 0;
}
