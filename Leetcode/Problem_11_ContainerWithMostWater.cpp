#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxSize=-1e9;
        while(i<j){
            int t=(j-i)*min(height[i],height[j]);
            maxSize=maxSize>=t?maxSize:t;
            height[i]<height[j]?i++:j--;
        }
        return maxSize;
    }
};
int main() {
    vector<int>arr{1,8,6,2,5,4,8,3,7};
    cout<<Solution(). maxArea(arr);
    return 0;
}