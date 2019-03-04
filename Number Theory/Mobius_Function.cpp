///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define N 10000000
typedef long long ll;
#define mx 100001
int mob[mx],prime_chk[mx];
void mobius(){
    int i,j;
    for(i=1;i<=mx;i++)mob[i]=prime_chk[i]=1;
    prime_chk[1]=0;
    for(i=2;i<=mx;i++){
        if(prime_chk[i]){
            mob[i]=-mob[i];
            for(j=2;i*j<=mx;j++){
                prime_chk[i*j]=0;
                if(j%i==0)mob[i*j]=0;
                else mob[i*j]=-mob[i*j];
            }
        }
    }
}
int main(){
    mobius();
    return 0;
}