#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define inf 1000
#define mem(a,b,c) memset(a,b,sizeof(c))
typedef vector<int> vi;
queue<int>q;
vi adjlist[MAX],cost[MAX],color[MAX];
int level[MAX+1],visited[MAX];
int bfs(int s,int n){
    int count=0;
    q.push(s);
    level[s]=0;
    while(!q.empty()){
        //cout<<"Hi"<<endl;
        int u=q.front();
        q.pop();
        int len=adjlist[u].size();
        for(int i=0;i<len;i++){
            int v=adjlist[u][i];
            if(level[v]==inf){
                level[v]=level[u]+1;
                q.push(v);
                //if(visited[v]==-1)visited[v]=u;
                //cout<<visited[v]<<" ";
                if(level[v]>n)count++;
            }
        }
    }
    return count;
}
int main(){
    int N,E,s,d;
    //scanf("%d %d",&N,&E);
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    scanf("%d%d",&s,&d);
    for(int i=0;i<MAX+1;i++)level[i]=inf;
    mem(visited,-1,visited);
    cout<<bfs(s,d)<<endl;
    //int cur=d,count=0;
    /*while(visited[cur]!=-1){
        cout<<cur<<"-> ";
        cur=visited[cur];
        count++;
    }
    cout<<s<<endl;
    cout<<count<<endl;*/
    return 0;
}
