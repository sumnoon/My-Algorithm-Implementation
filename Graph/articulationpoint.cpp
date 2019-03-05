#include<bits/stdc++.h>
using namespace std;
#define N 110
#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1
typedef vector<int> vi;
vi AdjList[N];
vi dfs_num;
vi dfs_parent;
vi dfs_low;       // additional information for articulation points/bridges/SCCs
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
void printThis(char* message) {
  printf("==================================\n");
  printf("%s\n", message);
  printf("==================================\n");
}
void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == DFS_WHITE) {  // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++;  // special case, count children of root

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u]){              // for articulation point
        articulation_vertex[u] = true;           // store this information first
        cout<<"node : "<<u<<" "<<v<<" "<<"dfs_num value : "<<dfs_num[u]<<" "<<"dfs_low value : "<<dfs_low[v]<<endl;
      }
     // if (dfs_low[v] > dfs_num[u])                           // for bridge
        //printf(" Edge (%d, %d) is a bridge\n", u, v);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);       // update dfs_low[u]
    }
    else if (v != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);       // update dfs_low[u]
} }
int main(){
    //freopen("in.txt","r",stdin);
    int V,m,i;
    scanf("%d %d",&V,&m);
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    printThis("Articulation Points & Bridges (the input graph must be UNDIRECTED)");
    dfsNumberCounter = 0; dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0);
    dfs_parent.assign(V, -1); articulation_vertex.assign(V, 0);
    printf("Bridges:\n");
    for (int i = 0; i < V; i++)
        if (dfs_num[i] == DFS_WHITE) {
            dfsRoot = i; rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); }       // special case
    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++)
        if (articulation_vertex[i])
            printf(" Vertex %d\n", i);
    for(int i=0;i<V;i++)cout<<"node : "<<i<<" "<<"dfs_num value : "<<dfs_num[i]<<" "<<"dfs_low value : "<<dfs_low[i]<<endl;
    return 0;
}
