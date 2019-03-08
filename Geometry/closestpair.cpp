///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define mx 50001
#define inf 1e9
#define eps 1e-9
typedef long long ll;
typedef pair<ll,ll> pll;
pll pnts[mx],tmp[mx];
bool comp(pll a,pll b){
    return a.second<b.second;
}
ll sq(ll x){
    return x*x;
}
int id1,id2;
ll closest_pair(int n){
    sort(pnts,pnts+n,comp);
    ll best=inf;
    set<pll>box;
    box.insert(pnts[0]);
    int left=0;
    for(int i=1;i<n;i++){
        while(left<i&&pnts[i].second-pnts[i].second>best)box.erase(pnts[left++]);
        for(set<pll>::const_iterator it =box.lower_bound(pll(pnts[i].first-best,pnts[i].second-best));it!=box.end()&&pnts[i].first+best>=it->first;it++){
            ll len=sq(pnts[i].first-it->first)+(sq(pnts[i].second-it->second));
            if(best>len){
                id1=i;
                best=len;
            }
        }
        box.insert(pnts[i]);
    }
    return best;
}
int main(){
    int n,i;
    ll x,y;
    ll ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&pnts[i].second,&pnts[i].first);
        tmp[i].second=pnts[i].second,tmp[i].first=pnts[i].first;
    }
    ans=closest_pair(n);
//    cout<<pnts[id1].second<<" "<<pnts[id1].first<<" ";
    for(i=0;i<n;i++){
        if(i==id1)continue;
        ll len=sq(pnts[i].first-pnts[id1].first)+(sq(pnts[i].second-pnts[id1].second));
        if(ans==len)id2=i;
    }
//    cout<<pnts[id2].second<<" "<<pnts[id2].first<<endl;
    for(i=0;i<n;i++){
        if(pnts[id1].first==tmp[i].first&&pnts[id1].second==tmp[i].second){
            id1=i;
            break;
        }
    }
    for(i=0;i<n;i++){
        if(pnts[id2].first==tmp[i].first&&pnts[id2].second==tmp[i].second){
            id2=i;
            break;
        }
    }
    printf("%d %d %.6f\n",min(id1,id2),max(id1,id2),(double)sqrt(ans+.0));
    return 0;
}
