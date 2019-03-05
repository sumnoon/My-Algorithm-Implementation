#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int cell[100][100],d[100][100],vis[100][100];
int row,col;
struct node{
    int r,c;
};
int C;
void bfs(int sx,int sy){
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    d[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty()){
        pii top=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(tx>=0&&tx<row&&ty>=0&&ty<col&&cell[tx][ty]!=-1&&vis[tx][ty]!=0){
                vis[tx][ty]=1;
                d[tx][ty]=d[top.first][top.second]+1;
                q.push(pii(tx,ty));
            }
        }
    }
}
int main(){
    int n,i,j,sum=0;
    scanf("%d",&C);
    for(i=0;i<3;i++){
        for(j=0;j<C;j++)cin>>cell[i][j];
    }
    sum=bfs(0,0);
    cout<<sum<<endl;
    return 0;
}

