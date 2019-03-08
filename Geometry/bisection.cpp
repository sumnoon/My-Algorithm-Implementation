#include<bits/stdc++.h>
using namespace std;
#define eps .00000001
int main(){
    double low,high,mid,n;
    cin>>n;
    low=0.0,high=n;
    for(int i=0;i<64;i++){
        mid=(low+high)/2;
        if(mid*mid>n)high=mid;
        else low=mid;
    }
    cout<<mid<<endl;
    return 0;
}
