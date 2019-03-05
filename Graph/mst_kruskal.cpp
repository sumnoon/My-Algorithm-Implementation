#include<bits/stdc++.h>
using namespace std;
#define MAX 110
typedef pair<int,int> ii;
typedef pair<ii,ii> iii;
vector<iii>edge;
int pr[MAX],a[MAX],n,m;
bool comp(iii a,iii b){
    return (a.first.second<b.first.second);
}
int findSet(int r){
    return (a[r]==r)?r:findSet(a[r]);
}
bool isSameset(int i,int j){
    return findSet(i)==findSet(j);
}
void unionSet(int i,int j){
    if(!isSameset(i,j)){
        int x=findSet(i);
        int y=findSet(j);
        if(pr[x]>pr[y]){
            a[y]=x;
        }
        else{
            a[x]=y;
            if(pr[x]==pr[y])pr[y]++;
        }
    }
}
ii node[20];
void kruskal(){
    int i;
    sort(edge.begin(),edge.end(),comp);
    for(i=1;i<=n;i++)a[i]=i;
    int cnt=0,s=0,sz=edge.size();
    for(i=0;i<sz;i++){
        iii frnt=edge[i];
        if(!isSameset(frnt.second.first,frnt.second.second)){
            cnt+=frnt.first.second;
            node[frnt.first.first]=ii(frnt.second.first,frnt.second.second);
            unionSet(frnt.second.first,frnt.second.second);
        }
    }
    for(i=0;i<m;i++){
        if(node[i].first&&node[i].second)cout<<node[i].first<<" "<<node[i].second<<endl;
    }
    cout<<cnt<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    int i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        int w,u,v;
        scanf("%d %d %d",&w,&u,&v);
        edge.push_back(make_pair(ii(i+1,w),ii(u,v)));
    }
    kruskal();
}
