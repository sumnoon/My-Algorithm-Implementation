#include<bits/stdc++.h>
using namespace std;
vector<int>zalgorithm(string s){
    int n=(int)s.length(),i,l,r;
    vector<int>z(n);
    for(i=1,l=0,r=0;i<n;i++){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,cases=0,i,sz,ans,n;
    string txt,pat;
    scanf("%d",&tc);
    while(tc--){
        cin>>txt>>pat;
        sz=(int)txt.length();
        n=(int)pat.size(),ans=0;
        vector<int>z;
        z=zalgorithm(pat+"$"+txt);
        for(i=0;i<sz;i++){
            if(z[i+n+1]==n)ans++;
        }
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
