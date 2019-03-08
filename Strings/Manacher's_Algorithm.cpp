#include<bits/stdc++.h>
using namespace std;
const  int N = 1000005;
char s[N], a[N*2];
int p[N*2];
void Manacher(char s[], int len)
{
    int i,j,k = 0;
    a[k++] = '$';
    a[k++] = '#';
    for(i = 0; i < len; i++)
    {
        a[k++] = s[i];
        a[k++] = '#';
    }
    a[k] = 0;

    int mx=0,id=0;
    for(i = 0; i < k; i++)
    {
        p[i] = mx>i?min(p[2*id-i], mx-i):1;

        while(a[i+p[i]] == a[i-p[i]])  p[i]++;
        if(i+p[i] > mx)
        {
            mx = i+p[i];
            id = i;
        }
    }
}

int main()
{
    int t,ca = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s", s);
        int len = strlen(s);
        Manacher(s, len);
        int ans = 0;
        int i,j;
        for(i = 0; i <= 2*len+1; i++)
        {
            if(i+p[i]==2*len+2)
            {
                ans = max(ans, p[i]-1);
            }
        }
        printf("Case %d: %d\n", ca++, len+len-ans);
    }
    return 0;
}
