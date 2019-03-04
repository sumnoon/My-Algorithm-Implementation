///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define N 10000000
typedef long long LL;
///moduler exponentiation
#define mod 1000000007
LL mod_exp(LL x,LL y){
    LL res=1;
    x=x%mod;
    while(y>0){
        if(y&1)res=(res*x)%mod;
        y=y>>1;
        x=(x*x)%mod;
    }
    return res;
}
int main(){
	cout << mod_exp ( 50, 2 ) << endl;
	return 0;
}