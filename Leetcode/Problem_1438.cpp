#include<bits/stdc++.h>

using namespace std;
int main(){

}
class Solution1 {
    // 我一开始的思路，维护两个单调队列，枚举窗口从size到0，每一次循环时间复杂度O(n)
    //最后求窗口的最大值和最小值之差，整体来看，时间复杂度O(n^2)
public:
    int longestSubarray(vector<int>& nums, int limit) {
    int _size=nums.size();
    while(_size){
        deque<int> mq_max,mq_min;
        vector<int>_max,_min;
        int mmax,mmin;
        
        for(int i=0;i<nums.size();i++){
            //求区间最大值
            while(!mq_max.empty()&&mq_max.front()<=i-_size){
                mq_max.pop_front();
            }
            while(!mq_max.empty()&&nums[mq_max.back()]<nums[i]){
                mq_max.pop_back();
            }
            mq_max.push_back(i);
            // if(i+1-_size>=0){
            //     _max.push_back(nums[mq_max.front()]);
            // }

            //求区间最小值
             while(!mq_min.empty()&&mq_min.front()<=i-_size){
                mq_min.pop_front();
            }
            while(!mq_min.empty()&&nums[mq_min.back()]>nums[i]){
                mq_min.pop_back();
            }
            mq_min.push_back(i);
            if(i+1-_size>=0){
                mmax=nums[mq_max.front()];
                mmin=nums[mq_min.front()];
                if(mmax-mmin<=limit)return _size;
            }
        }
        // for(int i=0;i<_max.size();i++){
        //     if(_max[i]-_min[i]<=limit){
        //         return _size;
        //     }
        // }
        _size--;
    }return 0;
    }
};

class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        /**
         * 最好的解法，滑动窗口right从0到n，如果满足条件，right就一直+1，记录最大区间
         * 如果不满足，那么必然只有left+1，因为再扩大right一定不满足
         * 但是需要注意的是如果left是最大值或者最小值，则要从单调队列中删除
         * 
         */
    int _size=nums.size();
        deque<int> mq_max,mq_min;
        int length=0;
    int left=0,right=0;
        
        while(right<_size){
            
            while(!mq_min.empty()&&mq_min.back()>nums[right]){
                mq_min.pop_back();
            }
            while(!mq_max.empty()&&mq_max.back()<nums[right]){
                mq_max.pop_back();
            }
            mq_max.push_back(nums[right]);
            mq_min.push_back(nums[right]);
            while(!mq_max.empty()&&!mq_min.empty()&&mq_max.front()-mq_min.front()>limit){
           if(mq_max.front()==nums[left]){
               mq_max.pop_front();
           }
           if(mq_min.front()==nums[left]){
               mq_min.pop_front();
           }
           left++;
            }
            length=max(length,right-left+1);
            right++;
        }

      return length;
    }
    
};