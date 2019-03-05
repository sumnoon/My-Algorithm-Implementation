#include<bits/stdc++.h>
using namespace std;
#define MAX 100+1
int N,E,x,y,i;
vector<int>edgelist[MAX];
vector<int>in(MAX);
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&E);
    for(i=0;i<E;i++){
        scanf("%d%d",&x,&y);
        edgelist[x].push_back(y);
    }
    for(i=1;i<=N;i++){
        for(int j=0;j<edgelist[i].size();j++)in[edgelist[i][j]]++;
    }
    for(i=1;i<=N;i++)cout<<"Node: "<<i<<" in degree : " << in[i]<<endl;
    queue<int>q;
    for(i=1;i<=N;i++){
        if(in[i]==0)q.push(i);
    }
    vector<int>top_order;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        top_order.push_back(u);
        for(i=0;i<edgelist[u].size();i++){
            int v=edgelist[u][i];
            --in[v];
            if(in[v]==0)q.push(v);
        }
    }
    for(i=0;i<top_order.size();i++)cout<<top_order[i]<<" ";
    cout<<endl;
    return 0;
}
