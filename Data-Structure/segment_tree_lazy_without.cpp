#include<bits/stdc++.h>
using namespace std;
const int N=5*100000;
int a[N+10];
int t[3*N+10];
void update(int node,int b,int e,int i,int j){
    if(i>e||j<b)return;
    if(b>=i&&e<=j){
        t[node]++;
        return ;
    }
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}
int query(int node,int b,int e,int pos){
    if(pos<b||e<pos)return 0;
    if(b<=pos&&pos<=e)return t[node];
    int left=node<<1;
    int right=left|1;
    int mid=(b+e)>>1;
    if(pos<=mid)return query(left,b,mid,pos);
    else return query(right,mid+1,e,pos);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)update(1,1,n,i,i);
    }
    update(1,1,n,1,5);
    update(1,1,n,2,4);
    cout<<query(1,1,n,2)%2<<endl;
    return 0;
}
