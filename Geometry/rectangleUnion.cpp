///*BISMILLAHIR RAHMANIR RAHIM*///
///Rectangle Union O(nlogn) complexity using segment tree
#include<bits/stdc++.h>
using namespace std;
#define MAX 30003
typedef long long ll;
struct side{
    int x,y1,y2;
    bool type;
    side(){};
    side(int x,int y1,int y2,bool type):x(x),y1(y1),y2(y2),type(type){};
};
bool comp(side a,side b){
    return a.x<b.x;
}
vector<side>edge;
int h[MAX<<1],counter[MAX<<5],t[MAX<<5];
void update(int node,int b,int e,int ymin,int ymax,bool open){
    if(h[e]<ymin||h[b]>ymax)return ;
    int left=node<<1;
    int right=(node<<1)|1;
    int mid=(b+e)>>1;
    if(ymin<=h[b]&&h[e]<=ymax){
        counter[node]+=open?1:-1;
        if(counter[node])t[node]=h[e]-h[b];
        else t[node]=t[left]+t[right];
        return;
    }
    if(b+1>=e)return;
    update(left,b,mid,ymin,ymax,open);
    update(right,mid,e,ymin,ymax,open);
    if(counter[node])t[node]=h[e]-h[b];
    else t[node]=t[left]+t[right];
}
ll union_area(int e){
    sort(h+1,h+e+1);
    int k=1;
    for(int i=2;i<=e;i++){
        if(h[i]!=h[k])h[++k]=h[i];
    }
    e=k;
    for(int i=0;i<MAX*3;i++)t[i]=0,counter[i]=0;
    sort(edge.begin(),edge.end(),comp);
    ll area=0;
    update(1,1,e,edge[0].y1,edge[0].y2,edge[0].type);
    for(int i=1;i<edge.size();i++){
        area+=t[1]*(ll)(edge[i].x-edge[i-1].x);
        update(1,1,e,edge[i].y1,edge[i].y2,edge[i].type);
    }
    return area;
}
int main(){
    int tc,cases=0,n,i,x1,y1,x2,y2,e;
    ll ans;
    scanf("%d",&tc);
    while(tc--){
        e=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            edge.push_back(side(x1,y1,y2,true));
            edge.push_back(side(x2,y1,y2,false));
            h[++e]=y1;
            h[++e]=y2;
        }
        ans=union_area(e);
        printf("Case %d: %lld\n",++cases,ans);
        edge.clear();
        //for(i=0;i<=e;i++)h[i]=0;
    }
    return 0;
}

