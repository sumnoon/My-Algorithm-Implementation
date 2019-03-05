///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define mxn 100005
typedef long long ll;
int sz[mxn], col[mxn],  bigChild, maxi;
bool big[mxn];
ll ans[mxn], sum;
vector<int>adjlist[mxn];
int cnt[mxn];
void getsz ( int u, int p ) {
	sz[u] = 1;
	for ( auto v : adjlist[u] ) {
		if ( v != p ) {
			getsz ( v, u );
			sz[u] += sz[v];
			
		}
	}
}

void add ( int u, int p, int x ) {
	cnt [ col[u] ] += x;
	if (cnt[ col[u] ] > maxi) {
		maxi=cnt[col[u]];
		sum = col[u];
	}
	else if(cnt[ col[u] ] == maxi) {
		sum += col[u];
	}
	for ( auto v : adjlist[u] ) {
		if ( v != p && !big[v] ) {
			add ( v, u, x );
		}
	}
}

void dfs ( int u, int p, bool keep ) {
	int mx = -1, bigChild = -1;
	for (auto v: adjlist[u]) {
		if (v != p && sz[v] > mx) {
			mx = sz[v];
			bigChild = v;
		}
	}
	for (auto v: adjlist[u]) {
		if (v != p && v!= bigChild) {
			dfs (v, u, 0);
		}
	}
	if (bigChild != -1){
		dfs (bigChild, u, 1);
		big[bigChild] = 1;
	}
	add (u, p, 1);
	ans[u] = sum;
	if (bigChild != -1) {
		big[bigChild] = 0;
	}
	if (keep == 0) {
		add (u, p, -1);
		sum = 0, maxi = 0;
	}
}
int main(){
	int n, m, u, v, i, j;
	scanf("%d", &n);
	m = n - 1;
	for ( i = 1; i <= n; i++ ) {
		scanf("%d", col + i);
	}
	for ( i = 0; i < m; i++ ) {
		scanf("%d%d", &u, &v);
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	getsz ( 1, 1 );
	dfs ( 1, 1, 0);
	for ( i = 1; i <= n; i++ ) cout << ans[i] << " ";
	//cout << cnt[3] << endl;
	return 0;
}
/*
	12
	3 4 4 1 2 2 3 3 1 2 3 3
	1 2 1 3
	2 4 2 5
	3 6
	5 7 5 8
	6 9 6 10
	10 11 10 12
*/