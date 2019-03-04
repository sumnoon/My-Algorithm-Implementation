///*BISMILLAHIR RAHMANIR RAHIM*///
/// If 1 then prime otherwise not prime
#include<bits/stdc++.h>
using namespace std;
#define N 10000000
typedef long long LL;
LL mul_mod(LL a,LL b,LL mod)
{
    LL ret=0;
    while(b)
    {
        if(b&1)ret=(ret+a);
        a<<=1;
        if(ret>mod)ret-=mod;
        if(a>mod)a-=mod;
        b>>=1;
    }
    return ret;
}
LL pow_mod(LL a,LL b,LL mod)
{
    LL ret=1,tmp=a%mod;
    while(b)
    {
        if(b&1)ret=mul_mod(ret,tmp,mod)%mod;
        tmp=mul_mod(tmp,tmp,mod)%mod;
        b>>=1;
    }
    return ret;
}

bool Miller_Rabin(LL n)
{
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    LL a,m=n-1,x,y;
    int k=0;
    while(!(m&1))
    {
        k++;
        m>>=1;
    }
    for(int i=0; i<10; i++)//times=10
    {
        a=rand()%(n-1)+1;
        x=pow_mod(a,m,n);
        for(int j=0; j<k; j++)
        {
            y=mul_mod(x,x,n);
            if(y==1&&x!=1&&x!=n-1) return false;
            x=y;
        }
        if(y!=1) return false;
    }
    return true;
}
int main(){
    cout<<Miller_Rabin(6)<<endl;
    return 0;
}