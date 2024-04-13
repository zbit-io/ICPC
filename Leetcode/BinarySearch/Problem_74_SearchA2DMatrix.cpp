#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix.front().size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int row=mid/n,col=mid%n;
            if(matrix[row][col]>target){
                if(matrix[row][col]==target){
                    return true;
                }
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};
int main(){

    return 0;
}