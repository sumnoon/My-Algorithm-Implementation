#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
int a[MAX];
struct info{
    int sum,prop;
}t[3*MAX];
void build(int node,int b,int e){
    if(b>=e){
        if(b==e)t[node].sum=a[b];
        return ;
    }
    int left=node<<1;
    int right=left|1;
    int mid=(b+e)>>1;
    build(left,b,mid);
    build(right,mid+1,e);
    t[node].sum=t[left].sum+t[right].sum;
}
void update(int node,int b,int e,int i,int j,int x){
    if(i>e||j<b)return;
    if(b>=i&&e<=j){
        t[node].sum+=((e-b+1)*x);
        t[node].prop+=x;
        return ;
    }
    int left=node<<1;
    int right=left|1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    t[node].sum=t[left].sum+t[right].sum+(e-b+1)*t[node].prop;
}
int query(int node,int b,int e,int pos,int carry=0){
    if(pos<b||e<pos)return 0;
    if(b==pos&&pos==e)return t[node].sum+carry*(e-b+1);
    int left=node<<1;
    int right=left|1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,pos,carry+t[node].prop);
    int p2=query(right,mid+1,e,pos,carry+t[node].prop);
    return p1+p2;
}
int main(){
    int n,i,k,l,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    build(1,1,n);
    scanf("%d %d %d",&l,&r,&k);
    update(1,1,n,l,r,k);
    cout<<query(1,1,n,l,r)<<endl;
}
