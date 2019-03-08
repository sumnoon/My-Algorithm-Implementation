///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point () {x = y = 0.0;}
    point (double _x,double _y) :x(_x),y(_y){}
};

bool comp ( point a, point b ) {
        return a.x < b.x || (a.x == b.x && a.y <b.y );
}
double cross ( point a, point b, point c ) {
    return ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}
vector<point>CH ( vector<point>p ) {
    int n = p.size(), k = 0;
    vector<point>H( 2*n );
    sort( p.begin(), p.end(), comp );
    for (int i = 0; i < n; i++ ) {
        while ( k >= 2 && cross ( H[k-2], H[k-1], p[i] ) <= 0 ) k--;
        H[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i-- ) {
        while( k >= t && cross ( H[k-2], H[k-1], p[i] ) <= 0 )k--;
        H[k++] = p[i];
    }
    H.resize( k - 1 );
    return H;
}
int main(){
    vector<point>a, b;
    double x, y;
    for (int i = 0; i < 3; i++ ) {
        cin >> x >> y;
        b.push_back( point( x, y ) );
    }
    a = CH ( b );
    for (int i = 0; i < a.size(); i++ ) {
        cout << a[i].x << " " << a[i].y << endl;
    }
    return 0;
}
