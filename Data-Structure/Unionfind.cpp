#include<bits/stdc++.h>
using namespace std;
vector<int>a,p,setSize;

int numSet;
int findSet(int i){
    return (a[i]==i)?i:(a[i]=findSet(a[i]));
}
bool isSameSet(int i,int j){
    return findSet(i)==findSet(j);
}
void unionSet(int i,int j){
    if(!isSameSet(i,j)){
        int x=findSet(i);
        int y=findSet(j);
        if(p[x]>p[y]){
            a[y]=x;
            setSize[x]+=setSize[y];
        }
        else{
            a[x]=y;
            if(p[x]==p[y])p[y]++;
            setSize[y]+=setSize[x];
        }
        numSet--;
    }
}
int numDisjointSet(){
    return numSet;
}
int sizeofSet(int i){
    return setSize[findSet(i)];
}
int n=5;
int main(){
    setSize.assign(n,1);
    numSet=n;
    p.assign(n,0);
    a.assign(n,0);
    for(int i=0;i<n;i++)a[i]=i;
    unionSet(0,1);
    unionSet(2,3);
    unionSet(4,3);
    if(isSameSet(3,4))printf("Connected\n");
    else printf("Not connected\n");
    cout<<findSet(0)<<endl;
    cout<<numDisjointSet()<<endl;
    for(int i=0;i<n;i++)cout<<sizeofSet(i)<<" ";
    cout<<endl;
    return 0;
}
