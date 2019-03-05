#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define LN 14
vector<int>adjlist[N],costs[N],indexx[N];
int chainNo,baseArray[N],chainInd[N],chainHead[N],posInBase[N],ptr;
int T[N],L[N],P[LN][N],otherEnd[N],subsize[N];
int t[2*N];
int n;
void dfs(int from,int u,int dep){
    //T[u]=from;
    L[u]=dep;
    P[0][u]=from;
    int i,sz=adjlist[u].size();
    subsize[u]=1;
    while(sz--){
        int v=adjlist[u][sz];
        if(v!=from){
            otherEnd[indexx[u][sz]]=v;
            //d[v]=d[u]+1;
            dfs(u,v,dep+1);
            subsize[u]+=subsize[v];
        }
    }
}
void HLD(int curNode,int cost,int prev){
    if(chainHead[chainNo]==-1)chainHead[chainNo]=curNode;
    ptr++;
    chainInd[curNode]=chainNo;
    posInBase[curNode]=ptr;
    baseArray[ptr]=cost;
    int sc=-1,ncost=0,sz=adjlist[curNode].size();
    while(sz--){
        int next=adjlist[curNode][sz];
        if(next!=prev){
            if(sc==-1||subsize[sc]<subsize[next]){
                sc=next;
                ncost=costs[curNode][sz];
            }
        }
    }
    if(sc!=-1)HLD(sc,ncost,curNode);
    sz=adjlist[curNode].size();
    while(sz--){
        int next=adjlist[curNode][sz];
        if(next!=prev&&sc!=next){
            chainNo++;
            HLD(next,costs[curNode][sz],curNode);
        }
    }
}
void lca_build(int nodes){
    int i,j;
    //for(i=0;i<nodes;i++)P[i][0]=T[i];
    for(j=1;j<LN;j++){
        for(i=1;i<=nodes;i++){
            P[j][i]=P[j-1][P[j-1][i]];
        }
    }
}
int lca_query(int nodes,int p,int q){
    int tmp,log,i;
    if(L[p]<L[q])swap(p,q);
    log=LN-1;
    for(i=log;i>=0;i--){
        if(L[p]-(1<<i)>=L[q])p=P[i][p];
    }
    if(p==q)return p;
    for(i=log;i>=0;i--){
        if(P[i][p]!=P[i][q])p=P[i][p],q=P[i][q];
    }
    return P[0][p];
}
void tree_build(int node,int b,int e){

    if(b==e){
        t[node]=baseArray[b];
        return ;
    }
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    tree_build(left,b,mid);
    tree_build(right,mid+1,e);
    t[node]=max(t[left],t[right]);
}
int tree_query(int node,int b,int e,int i,int j){
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return t[node];
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    int p1=tree_query(left,b,mid,i,j);
    int p2=tree_query(right,mid+1,e,i,j);
    return max(p1,p2);
}
void tree_update(int node,int b,int e,int i,int newvalue){
    //if(i>=e||i<b)return ;
    if(b==e){
        t[node]=newvalue;
        return;
    }
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    if(i<=mid)tree_update(left,b,mid,i,newvalue);
    else tree_update(right,mid+1,e,i,newvalue);
    t[node]=max(t[left],t[right]);
}
int query_up(int u,int v){
    if(u==v)return 0;
    int uchain,vchain=chainInd[v],ans=-1;
    while(1){
        uchain=chainInd[u];
        if(uchain==vchain){
            if(u==v)break;
            int tmp=tree_query(1,1,ptr,posInBase[v]+1,posInBase[u]);
            ans=max(ans,tmp);
            break;
        }
        int tmp=tree_query(1,1,ptr,posInBase[chainHead[uchain]],posInBase[u]);
        ans=max(tmp,ans);
        u=chainHead[uchain];
        u=P[0][u];
    }
    return ans;
}
void query(int u,int v){
    int lca=lca_query(n,u,v);
    int a=query_up(u,lca);
    int b=query_up(v,lca);
    //cout<<a<<" "<<b<<endl;
    int ans=max(a,b);
    printf("%d",ans);
}
void update(int i,int val){
    int node=otherEnd[i];
    tree_update(1,1,ptr,posInBase[node],val);
}
void clear_all(){
    for(int i=0;i<=n;i++){
        adjlist[i].clear();
        costs[i].clear();
        indexx[i].clear();
        chainHead[i]=-1;
        for(int j=0;j<LN;j++)P[j][i]=-1;
    }
}
int main(){
    int tc,m,l,r,q,i,j,u,v,c;
    scanf("%d",&tc);
    while(tc--){
        //printf("\n");
        scanf("%d",&n);
        clear_all();
        for(i=1;i<n;i++){
            cin>>u>>v>>c;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
            indexx[u].push_back(i);
            indexx[v].push_back(i);
            costs[u].push_back(c);
            costs[v].push_back(c);
        }
        dfs(0,1,0);
        lca_build(n);
        ptr=-1;
        chainNo=1;

        //cout<<subsize[1]<<" "<<subsize[2]<<endl;
        HLD(1,0,0);
        //for(i=0;i<=ptr;i++)cout<<baseArray[i]<<" ";
        //cout<<endl;
        tree_build(1,1,ptr);
        // cout<<query(1,0,ptr,1,4)<<endl;
        //cout<<lca_query(n,4,5)<<endl;
        char comm[10];
        scanf("%s",comm);
        while(comm[0]!='D'){
            scanf("%d %d",&u,&v);
            if(comm[0]=='Q'){
                query(u,v);
                printf("\n");
            }
            else update(u,v);
            scanf("%s",comm);
        }
    }
    return 0;
}

