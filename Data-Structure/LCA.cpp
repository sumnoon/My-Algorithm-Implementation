#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int L[mx],P[mx][22],T[mx];
vector<int>adjlist[mx];
int d[mx];
void dfs(int from,int u,int dep){
    T[u]=from;
    L[u]=dep;
    int i,sz=adjlist[u].size();
    for(i=0;i<sz;i++){
        int v=adjlist[u][i];
        if(v==from)continue;
        d[v]=d[u]+1;
        dfs(u,v,dep+1);
    }
}
void lca_build(int nodes){
    memset(P,-1,sizeof P);
    int i,j;
    for(i=0;i<nodes;i++)P[i][0]=T[i];
    for(j=1;(1<<j)<nodes;j++){
        for(i=0;i<nodes;i++){
            if(P[i][j-1]!=-1)P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}
int lca_query(int nodes,int p,int q){
    int tmp,log,i;
    if(L[p]<L[q])swap(p,q);
    log=1;
    while(1){
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }
    for(i=log;i>=0;i--){
        if(L[p]-(1<<i)>=L[q])p=P[p][i];
    }
    if(p==q)return p;
    for(i=log;i>=0;i--){
        if(P[p][i]!=-1&&P[p][i]!=P[q][i])p=P[p][i],q=P[q][i];
    }
    return T[p];
}
int kth(int n,int u,int v,int k){
    int w=lca_query(n,u,v);
    int d1=L[u]-L[w]+1;
    int d2=L[v]-L[w]+1;
    int from;
    if(k>d1){
        from=v;
        k=d1+d2-k-1;
    }
    else if(k==d1)return w;
    else if(k<d1){
        from=u;
        k--;
    }
    int log=22;
    while(k!=0){
        if((1<<log)<=k){
            from=P[from][log];
            k-=(1<<log);
        }
        --log;
        if(log<0)log=0;
    }
    return from;
}
int main(){
    adjlist[0].push_back(2);
    adjlist[0].push_back(1);
    adjlist[2].push_back(3);
    adjlist[2].push_back(4);
    cout<<T[2]<<endl;
    dfs(0,0,0);
    lca_build(5);
    printf("%d\n",lca_query(4,3,4));
    return 0;
}
