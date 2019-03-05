#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dr[]={1,0,-1,0};
ll dc[]={0,1,0,-1};
ll grid[101][101];
ll C,R,E,Sr, Sc, Tr, Tc;
ll floodfill(int r,int c){
    if(r<0||r>=R||c<0||c>=C)return 0;
    if(grid[r][c]==-100000)return 0;
    if(r == Tr && c == Tc ) return 1;
    int ans=1;
    E += grid[r][c];
    grid[r][c]=-100000;
    for(int d=0;d<4;d++){
        ans+=floodfill(r+dr[d],c+dc[d]);
    }
    return ans;
}
int main(){
	int tc, cases = 0;
	ll i, j;
	scanf("%d", &tc);
	while ( tc-- ) {
		scanf("%lld %lld %lld %lld %lld %lld %lld", &R, &C, &E, &Sr, &Sc, &Tr, &Tc);
		for ( i = 0; i < R; i++ ) {
			for ( j = 0; j < C; j++ ) {
				scanf("%lld", &grid[i][j]);
			}
		}
		ll ans = floodfill(Sr, Sc);
		if ( grid[Tr][Tc] == 0 ) printf("Case #%d: -1\n", ++cases);
		else printf("Case #%d: %lld\n", ++cases, E);
	}
    return 0;
}
