#include<bits/stdc++.h>
using namespace std;
int a[1001],cou[1001],cur_ans;
int ans[1001],block_size;
typedef pair< pair<int,int> ,int> iii;
pair< pair<int,int>, int> q[1001];
inline bool comp(const iii &x,const iii &y){
    int block_x=x.first.first/block_size;
    int block_y=y.first.first/block_size;
    if(block_x!=block_y)return block_x<block_y;
    return x.first.second<y.first.second;
}
inline void add(int x){
    //cur_ans-=(cou[x]==2);
    cou[x]++;
    cur_ans+=(cou[x]==3);
}
inline void remo(int x){
    cur_ans-=(cou[x]==2);
    cou[x]--;
    //cur_ans+=(cou[x]==3);
}
int main(){
    freopen("in.txt","r",stdin);
    int i,curl,curr,l,r;
    for(i=0;i<10;i++)scanf("%d",&a[i]);
    block_size=sqrt(10);
    curl=0,curr=-1;
    for(i=0;i<2;i++){
        cin>>q[i].first.first>>q[i].first.second;
        q[i].second=i;
    }
    sort(q,q+2,comp);
    for(i=0;i<2;i++){
        l=q[i].first.first;
        r=q[i].first.second;
        while(curr<r){
            curr++;
            add(a[curr]);
        }
        while(curr>r){
            remo(a[curr]);
            curr--;
        }
        while(curl<l){
            remo(a[curl]);
            curl++;
        }
        while(curl>l){
            curl--;
            add(a[curl]);
        }
        ans[q[i].second]=cur_ans;
    }
    for(i=0;i<2;i++)cout<<ans[i]<<endl;
    return 0;
}
