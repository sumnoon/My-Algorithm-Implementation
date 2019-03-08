///O(nlogn) approach using radix sort
#include<bits/stdc++.h>
using namespace std;
#define mx 100010
char T[mx]; ///input string
int RA[mx],tempRA[mx]; ///rank array and temporary rank array
int SA[mx],tempSA[mx]; ///suffix array and temporary suffix array
int i,n; /// n=length of string
int c[mx]; ///for counting/radix sort

void countingSort(int k){
    int i,sum,maxi=max(300,n);
    memset(c,0,sizeof c);
    for(i=0;i<n;i++)c[i+k<n?RA[i+k]:0]++;
    for(i=sum=0;i<maxi;i++){
        int t=c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i=0;i<n;i++)tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
    for(i=0;i<n;i++)SA[i]=tempSA[i];
}
void constructSA(){
    int i,k,r;
    for(i=0;i<n;i++)RA[i]=T[i],SA[i]=i;
    for(k=1;k<n;k <<=1){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]]=r=0;
        for(i=1;i<n;i++){
            if(RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])tempRA[SA[i]]=r;
            else tempRA[SA[i]]=++r;
        }
        for(i=0;i<n;i++)RA[i]=tempRA[i]; ///update rank array
        if(RA[SA[n-1]]==n-1)break;
    }
}
int LCP[mx],PLCP[mx],Phi[mx];
void computeLCP(){
    int i,l;
    Phi[SA[0]]=-1;
    for(i=1;i<n;i++)Phi[SA[i]]=SA[i-1];
    for(i=l=0;i<n;i++){
        if(Phi[i]==-1){
            PLCP[i]=0;
            continue;
        }
        while(T[i+l]==T[Phi[i]+l])l++;
        PLCP[i]=l;
        l=max(l-1,0);
    }
    for(i=0;i<n;i++)LCP[i]=PLCP[SA[i]];
}
int owner[mx];
int main(){
    int tc,o,p,q;
    string s,t,u;
    cin>>s;
    o=s.length();
    for(i=0;i<o;i++)T[i]=s[i];
    n=(int)strlen(T);
    T[n++]='#';
    cout<<T<<endl;
    constructSA();
    computeLCP();
    for(int i=0;i<n;i++)cout<<SA[i]<<" "<<LCP[i]<<" "<<owner[i]<<" "<<T+SA[i]<<endl;
    return 0;
}

