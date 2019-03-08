///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define mx 300001
struct point{
    int x,y;
    point(){x=y=0;}
    point(int _x,int _y):x(_x),y(_y){}
};
inline bool onSegment(const point &p,const point &q,const point &r){
    return (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) &&r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y));
}
inline int orientation(const point &p,const point &q,const point &r){
    return p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y);
}
inline bool doIntersect(const point &p1,const point &q1,const point &p2,const point &q2,bool &on){
    int o1=orientation(p2,q2,p1);
    int o2=orientation(p2,q2,q1);
    int o3=orientation(p1,q1,p2);
    int o4=orientation(p1,q1,q2);
    on=false;
    if(((o1<0&&o2>0)||(o1>0&&o2<0))&&((o3<0&&o4>0)||(o3>0&&o4<0)))return true;
    if(!o3&&onSegment(p1,q1,p2)){
        on=true;
        return true;
    }
    if(!o4&&onSegment(p1,q1,q2))return true;
    if(!o1&&onSegment(p2,q2,p1))return true;
    if(!o2&&onSegment(p2,q2,q1))return true;
    return false;
}
bool inPolygon(point pt,vector<point> &p){
    bool on;
    int sz=p.size();
    if(sz<3)return false;
    p.push_back(p[0]);
    point extreme = point(pt.x+30000,pt.y+30001);
    int count=0,i;
    for(i=0;i<sz;i++){
        if(doIntersect(p[i],p[i+1],pt,extreme,on)){
            if(on){
                count=1;
                break;
            }
            count++;
        }
    }
    return count&1;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,cases=0,n,d,m,q,i;
    int x,y;
    scanf("%d %d",&n, &d);
    vector<point>p;
    point pt;
    p.push_back(point(0,d));
    p.push_back(point(d,0));
    p.push_back(point(n,n-d));
    p.push_back(point(n-d,n));
   	scanf("%d",&m);
    while(m--){
        cin>>x>>y;
        pt=point(x,y);
        if(inPolygon(pt,p))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}