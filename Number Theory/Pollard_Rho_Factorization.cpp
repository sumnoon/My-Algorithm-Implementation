///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define N 10000000
typedef long long LL;
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
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
LL Pollard_rho(LL n,LL c)
{
    LL x,y,d,i=1,k=2;
    y=x=rand()%(n-1)+1;
    while(true)
    {
        i++;
        x=(mul_mod(x,x,n)+c)%n;
        d=gcd((y-x+n)%n,n);
        if(1<d&&d<n) return d;
        if(y==x) return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}
int main(){
    return 0;
}