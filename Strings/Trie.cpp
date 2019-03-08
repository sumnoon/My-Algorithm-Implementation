#include<bits/stdc++.h>
using namespace std;
const int maxN = 500500;
int sz=0;
int nex[maxN][27];
int en[maxN];
bool created[maxN];
void ins(string s){
    int v=0,len=s.length();
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!created[nex[v][id]]){
            nex[v][id]= ++sz;
            created[sz]=true;
        }
        v=nex[v][id];
    }
    ++en[v];
}
bool sear(string s){
    int v=0,len=s.length();
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!created[nex[v][id]])return false;
        v=nex[v][id];
    }
    return en[v]>0;
}
int main(){
    string s;
    for(int i=0;i<5;i++){
        cin>>s;
        ins(s);
    }
    for(int i=0;i<5;i++){
        cin>>s;
        if(sear(s))printf("Found\n");
        else printf("Not found\n");
    }
    return 0;
}
