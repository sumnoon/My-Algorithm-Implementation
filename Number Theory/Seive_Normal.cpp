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
int main(){
    seive();
    cout << total << endl;
    return 0;
}