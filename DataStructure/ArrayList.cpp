#include <iostream>
#include <deque>
using namespace std;
struct ArrayList{
    int next[10000];
    int val[10000];
    int head=0;
    int cnt=0;
    void insert(int n){
        next[cnt]=cnt+1;
        cnt++;
        val[cnt]=n;
    }
    void insert(int x,int y,int n){

    }
}arr;
int main(){



    return 0;
}