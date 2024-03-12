#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int RabinKarp(string s,string target){
    const ull MOD=(1ULL<<61)-1;
    const ull N=1e9+7;
    int sl=s.size();
    int tl=target.size();
    ull hs=0;
    ull ht=0;
    ull nm=1;
    if(sl<tl)return -1;
    for(int i=0;i<tl;i++){
        nm*=N;
    }
    for(int i=0;i<tl;i++){

    }
    for(int i=0;i<tl;i++){
        hs=hs*N+target[i];
    }
    for(int i=0;i<tl;i++){
        ht=ht*N+s[i];
    }
    for(int i=0;i+tl<sl;i++){
        if(hs==ht)return i;
        if(i+tl+1<sl)hs=hs*N-s[i]*nm+s[i+tl+1];
    }

    int i=0,j=0;

}
int main() {
    
    return 0;
}