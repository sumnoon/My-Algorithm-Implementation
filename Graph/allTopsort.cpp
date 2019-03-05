#include<bits/stdc++.h>
using namespace std;
#define MAX 100+10
vector<int>edgelist[MAX];
vector<int>top_sort;
int in[MAX];
bool visited[MAX];
int n,m;
void back_track(){
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!in[i]&&!visited[i]){
            for(int j=0;j<edgelist[i].size();j++)in[edgelist[i][j]]--;
            top_sort.push_back(i);
            visited[i]=true;
            back_track();
            visited[i]=false;
            top_sort.erase(top_sort.end()-1);
            for(int j=0;j<edgelist[i].size();j++)in[edgelist[i][j]]++;
            flag=true;
        }
    }
    if(!flag){
        for(int i=0;i<top_sort.size();i++)cout<<top_sort[i]<<" ";
        cout<<endl;
    }
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edgelist[x].push_back(y);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<edgelist[i].size();j++)in[edgelist[i][j]]++;
    }
    back_track();
    return 0;
}
