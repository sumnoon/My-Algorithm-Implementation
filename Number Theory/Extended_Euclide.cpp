///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define N 10000000
typedef long long ll;
///Extended Euclidean
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
///Linear Diophantine Equation ax+by=c
//find whether there is a solution
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
//find number of solution
void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt) {

    x += cnt * b;
    y -= cnt * a;
}
ll find_all_solutions (ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    c=-c;
    if(a<0){
        a=-a;
        minx=-minx;
        maxx=-maxx;
        swap(minx,maxx);
    }
    if(b<0){
        b=-b;
        miny=-miny;
        maxy=-maxy;
        swap(miny,maxy);
    }
    if(a==0&&b==0){
        if(c==0)return (maxx-minx+1)*(maxy-miny+1);
        return 0;
    }
    ll x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))return 0;
    if(a==0){
        if(c/b>=miny&&c/b<=maxy)return (maxx-minx+1);
        return 0;
    }
    else if(b==0){
        if(c/a>=minx&&c/a<=maxx)return (maxy-miny+1);
        return 0;
    }
    a /= g;  b /= g;
    ll sign_a = a>0 ? +1 : -1;
    ll sign_b = b>0 ? +1 : -1;
    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)shift_solution (x, y, a, b, sign_b);
    if (x > maxx)return 0;
    ll lx1 = x;
    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)shift_solution (x, y, a, b, -sign_b);
    ll rx1 = x;
    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)return 0;
    ll lx2 = x;
    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)shift_solution (x, y, a, b, sign_a);
    ll rx2 = x;
    if (lx2 > rx2)swap (lx2, rx2);
    ll lx = max (lx1, lx2);
    ll rx = min (rx1, rx2);
    return max((rx - lx) / abs(b) + 1LL,0LL);
}
int main(){
    return 0;
}