#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define INF 1e9
typedef int ll;
int capacity[MAXN][MAXN];
vector<int>adjlist[MAXN];
int max_flow(int source, int sink) {
    int residual[MAXN][MAXN];
    memset(residual, 0, sizeof(residual));
    while(1) {
        int prev[MAXN];
        memset(prev, -1, sizeof(prev));
        int actual[MAXN];
        memset(actual, 0, sizeof(actual));
        prev[source] = source;
        actual[source] = INF;
        queue<int> q; q.push(source);
        bool flag=false;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < adjlist[u].size(); i++) {
                int v = adjlist[u][i];
                if(capacity[u][v] - residual[u][v] > 0 && prev[v] == -1) {
                    prev[v] = u;
                    actual[v] = min(actual[u], capacity[u][v] - residual[u][v]);
                    if(v != sink) {
                        q.push(v);
                    } else {
                        while(prev[v] != v) {
                            u = prev[v];
                            residual[u][v] += actual[sink];
                            residual[v][u] -= actual[sink];
                            v = u;
                        }
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(prev[sink] == -1) {
            int sum = 0;
            for(int i = 0; i < MAXN; i++) {
                sum += residual[source][i];
            }
            return sum;
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,a,b,i,j,tc,cases=0,c,source,sink;
    scanf("%d",&tc);
    while(tc--){
        cin>>n>>m>>source>>sink;
        memset(capacity,0,sizeof capacity);
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            if(a==b)continue;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
            capacity[a][b]=c;
            //capacity[b][a]=c;
        }
        cout<<max_flow(source,sink)<<endl;
        for(i=0;i<=n;i++)adjlist[i].clear();
    }

    return 0;
}
/*
10 13
2 3 918
4 5 121
6 7 685
8 9 805
1 10 24
5 10 703
1 6 483
9 4 251


*/
