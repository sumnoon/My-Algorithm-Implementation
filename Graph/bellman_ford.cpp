#include<bits/stdc++.h>
using namespace std;
#define mx 201
#define inf 1e9
typedef int ll;
int cost[mx],dist[mx],n,m;
bool flag;
struct info{
    int u,v,w;
    info(){u=0,v=0,w=0;}
    info(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
int cube(int x){
    return x*x*x;
}
vector<info>adj;
void bellman(int src){
    int i , j;
    for(i=0;i<n;i++)dist[i]=inf;
    dist[src] = 0;
    for( i = 1 ; i <=n-1 ; i++ ){
        for( j = 0 ; j < m ; j++ ){
            ll x = adj[j].u;
            ll y = adj[j].v;
            ll z = adj[j].w;
            if( dist[x]!=inf&&(dist[x]+z<dist[y])){
                dist[y] = dist[x] + z ;
            }
        }
    }
    flag=true;
    for(i=0;i<m;i++){
        ll x=adj[i].u;
        ll y=adj[i].v;
        ll z=adj[i].w;
        if(dist[x]!=inf&&(dist[x]+z<dist[y])){
            dist[y]=dist[x]+z;
        }
    }
}
int main(){
    int tc,cases=0,i,j,ans;
    scanf("%d",&tc);
    while(tc--){
        int x,y,z;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",cost+i);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            cin>>x>>y;
            x--,y--;
            z=cube(cost[y]-cost[x]);
            adj.push_back(info(x,y,z));
        }
        //for(i=0;i<m;i++)cout<<adj[i].u<<" "<<adj[i].v<<" "<<adj[i].w<<endl;
        bellman(0);
        int q,ans;
        scanf("%d",&q);
        printf("Case %d:\n",++cases);
        for( i = 0 ; i <q;i++ ){
            scanf("%d",&ans);
            ans--;
            if(dist[ans]==inf||dist[ans]<3)printf("?\n");
            else printf("%d\n",dist[ans]);
        }
        adj.clear();
    }
    return 0;
}
