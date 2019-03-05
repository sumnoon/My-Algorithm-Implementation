///*BISMILLAHI RAHMANIR RAHIM*///
/// 1-based indexing input taken in 1-based than decremented
#include<bits/stdc++.h>
using namespace std;
#define MAX 30010
typedef pair<int ,int > ii;
typedef vector<ii> vii;

int visited[MAX],u,v,n,w,maxi,start;
vii adjlist[MAX];
void dfs(int s,int dist){
    visited[s]=1;
    if(dist>maxi){
        maxi=dist;
        start=s;
    }
    for(int i=0;i<adjlist[s].size();i++){
        ii v=adjlist[s][i];
        if(!visited[v.first]){
            visited[v.first]=1;
            dfs(v.first,dist+v.second);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,cases=0;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&u,&v);
        u--,v--;
        adjlist[u].push_back(make_pair(v,1));
        adjlist[v].push_back(make_pair(u,1));
    }
    maxi=0;
    memset(visited,0,sizeof(visited));
    dfs(0,0);
    maxi=0;
    memset(visited,0,sizeof(visited));
    dfs(start,0);
    printf("Case %d: %d\n",++cases,maxi);
    for(int i=0;i<n;i++)adjlist[i].clear();
   return 0;
}
