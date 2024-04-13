#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0,high=nums.size()-1;
        
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target){
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;  // 目标在左半部分
                } else {
                    low = mid + 1;   // 目标在右半部分
                }
            }
            // 右侧有序
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // 目标在右半部分
                } else {
                    high = mid - 1; // 目标在左半部分
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}