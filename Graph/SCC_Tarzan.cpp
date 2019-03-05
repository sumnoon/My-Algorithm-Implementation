///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
vi dfs_num, dfs_low, S, visited;
vi adjlist[MAX], num[MAX];
int numSCC, dfsNumberCounter, ans, cnt, cc;
int mini;
void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);

	visited[u] = 1;
	for (int j = 0; j < (int)adjlist[u].size(); j++) {
		int v = adjlist[u][j];
		if (dfs_num[v] == 0) {
			tarjanSCC(v);
		}
		if (visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

	if (dfs_low[u] == dfs_num[u]) {
		printf("SCC %d: ", ++numSCC);
		while (1) {
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			printf(" %d", v);
			num[numSCC].push_back(v);
			if(u == v)break;
		}
		printf("\n");
	}
}
int main(){
	int n,m,u,v,i,j;
	scanf("%d%d",&n,&m);
	for (i = 0; i < m; i++){
		scanf("%d%d",&u,&v);
		u--, v--;
		adjlist[u].push_back(v);
	}
	dfs_num.assign(n, 0);
	dfs_low.assign(n, 0);
	visited.assign(n, 0);
	dfsNumberCounter = numSCC = 0;
	for (i = 0; i < n; i++) {
		if (dfs_num[i] == 0) {
			tarjanSCC(i);
		}
	}
	for (i = 1; i <= numSCC; i++){
		for(j = 0; j < num[i].size(); j++ )cout<<num[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
