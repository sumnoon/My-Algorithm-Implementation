#include<bits/stdc++.h>
using namespace std;
int t[100010],f[100010],n;
int read(int idx){
    int sum=0;
    while(idx>0){
        sum += t[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx,int x){
    while(idx<=n){
        t[idx]+=x;
        idx+=(idx&-idx);
    }
}
int query(int i,int j){
    return read(j)-read(i-1);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,cases=0,q,i;
    scanf("%d",&tc);
    while(tc--){
        memset(t,0,sizeof(t));
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++){
            scanf("%d",f+i);
            update(i,f[i]);
        }
        printf("Case %d:\n",++cases);
        for(i=0;i<q;i++){
            int c,x,y,v;
            scanf("%d",&c);
            if(c==1){
                scanf("%d",&x);
                x++;
                update(x,-f[x]);
                printf("%d\n",f[x]);
                f[x]=0;
            }
            else if(c==2){
                scanf("%d %d",&x,&v);
                x++;
                update(x,v);
                f[x]+=v;
            }
            else{
                scanf("%d %d",&x,&y);
                x++,y++;
                printf("%d\n",query(x,y));
            }
        }
    }
    return 0;
}
