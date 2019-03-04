///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define N 10000000
typedef long long ll;
bool status[N+1];
vector<int>primes;
int total=1;
//can store upto 664578 primes
void seive(){
    int i,j,len;
    primes.push_back(2);
    len=sqrt(N);
    for(i=2;i<=len;i++){
        if(!status[i]){
            for(j=i*i;j<=N;j+=i)status[j]=true;
        }
    }
    for(i=3;i<=N;i+=2){
        if(!status[i]){
            primes.push_back(i);
            total++;
        }
    }
}
///Euler Phi for single n
int ePhi(int n){
    int i,len,ans=n;
    len=sqrt(n);
    for(i=0;primes[i]<=len;i++){
        if(n%primes[i]==0)ans-=ans/primes[i];
        while(n%primes[i]==0)n/=primes[i];
    }
    if(n!=1)ans-=ans/n;
    return ans;
}
///Euler Phi generation less than n
ll phi[N];
void genePhi(int n){
    ll i,p;
    for(i=1;i<=n;i++)phi[i]=i;
    for(p=2;p<=n;p++){
        if(phi[p]==p){
            phi[p]=p-1;
            for(i=2*p;i<=n;i+=p)phi[i]=(phi[i]/p)*(p-1);
        }
    }
}
int main(){
    seive();
    cout << primes.size() << endl;
    genePhi(10000);
    return 0;
}