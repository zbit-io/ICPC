#include<iostream>
using namespace std;

int main() {
   int n=1204,y=0;
   while(n>0){
    y=y*10+n%10;
    n=n/10;
   }
   cout<<y<<"ss";
    return 0;
}