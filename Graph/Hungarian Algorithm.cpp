///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define inf 100000000
int n,m;
int cost[MAX+1][MAX+1];
vector<int>hungarian(){
    vector<int>u(n+1),v(m+1),p(m+1),way(m+1),ans(n+1);
    for(int i=1;i<=n;i++){
        p[0]=i;
        int j0=0;
        vector<int>minv(m+1,inf);
        vector<bool>used(m+1,false);
        do{
            used[j0]=true;
            int i0=p[j0],delta=inf,j1;
            for(int j=1;j<=m;j++){
                if(!used[j]){
                    int cur=cost[i0][j]-u[i0]-v[j];
                    if(cur<minv[j])minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta)delta=minv[j],j1=j;
                }
                //cout<<a[i0][j]<<" "<<u[i0]<<" "<<v[j]<<" ";
            }
            //cout<<endl;
            for(int j=0;j<=m;j++){
                if(used[j])u[p[j]]+=delta,v[j]-=delta;
                else minv[j]-=delta;
                //cout<<u[p[j]]<<" "<<v[j]<<" "<<minv[j]<<" ";
            }
            //cout<<endl;
            j0=j1;
        }while(p[j0]!=0);
        do{
            int j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    for(int j=1;j<=m;j++)ans[p[j]]=j;
    return ans;
}
int main(){
    int tc,cases=0,i,j,price;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        m=n;
        price=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&cost[i][j]);
                cost[i][j]*=(-1);
            }
        }
        vector<int>ans;
        ans=hungarian();
        for(int i=1;i<=n;i++)price+=abs(cost[i][ans[i]]);
        printf("Case %d: %d\n",++cases,price);
    }
    return 0;
}
