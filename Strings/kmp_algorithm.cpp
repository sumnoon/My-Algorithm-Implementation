#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
string txt,pat;
int lcp[MAX];
int n,m;
void kmpprocess(){
    int i=0,j=-1;
    lcp[0]=-1;
    while(i<m){
        while(j>=0&&pat[i]!=pat[j])j=lcp[j];
        i++,j++;
        lcp[i]=j;
    }
}
vector<int>v;
int kmpsearch(){
    int i=0,j=0,cou=0;
    while(i<n){
        while(j>=0&&txt[i]!=pat[j])j=lcp[j];
        i++,j++;
        if(j==m){
            v.push_back(i-m);
            cou++;
            j=lcp[j];
        }
    }
    return cou;
}
int main(){
    int tc,cases=0,i,j,ans;
    scanf("%d",&tc);
    while(tc--){
        cin>>txt>>pat;
        n=txt.length(),m=pat.length();
        kmpprocess();
        ans=kmpsearch();
        for(i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
        for(i=0;i<m;i++)cout<<lcp[i]<<" ";
        cout<<endl;
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
