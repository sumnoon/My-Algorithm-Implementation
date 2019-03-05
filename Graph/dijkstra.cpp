//Single Source Shortest Path
//We can use it to find k'th shortest path
//by changing k in line 46
#include<bits/stdc++.h>
using namespace std;
#define MAX 5005
int k;
vector<int>d[MAX];
struct edge{
    int to,w;
    edge(){}
    edge(int a,int b){
        to=a,w=b;
    }
};
vector<edge>adjlist[MAX];
struct node{
    int city,dist;
    bool operator<(const node& p)const{
        return dist>p.dist;
    }
};
int dijkstra(int so,int des){
    priority_queue<node>pq;
    node curr,u;
    int i,curr_dis;
    for(int i=0;i<=MAX;i++)d[i].clear();
    u.city=so,u.dist=0;
    pq.push(u);
    while(!pq.empty()){
        u=pq.top();
        pq.pop();
        if(d[u.city].size()==0)d[u.city].push_back(u.dist);
        else if(d[u.city].back()!=u.dist)d[u.city].push_back(u.dist);
        if(d[u.city].size()>k)continue;
        for(i=0;i<adjlist[u.city].size();i++){
            if(d[adjlist[u.city][i].to].size()==k)continue;
            curr_dis=adjlist[u.city][i].w+u.dist;
            curr.city=adjlist[u.city][i].to,curr.dist=curr_dis;
            pq.push(curr);
        }
    }
    if(d[des].size()<k)return -1;
    else return d[des][1];
}
int main(){
    //freopen("in.txt","r",stdin);
    k=2;
    int tc,cases=0,i,n,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adjlist[u].push_back(edge(v,w));
            adjlist[v].push_back(edge(u,w));
        }
        printf("Case %d: %d\n",++cases,dijkstra(1,n));
        for(i=0;i<=n;i++)adjlist[i].clear();
    }
    return 0;
}
